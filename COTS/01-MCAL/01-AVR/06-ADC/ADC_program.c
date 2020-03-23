/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_program.c                     */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_register.h"
#include "ADC_private.h"




static u8 ADC_u8ADCState = ADC_u8_STATE_IDLE;
static u8 ADC_u8ISRState = ADC_u8_SINGLE_CONVERSION;

/* Asynchronous and chain global variables */
static void (*GlobalPtrFunc)(void) = NULL;
static u16 *ADC_u16ADCResult = NULL;

/* Chain global variables */
static u8 * ADC_ChainArr = NULL;
static u8  ADC_ChainLength = 0;
static u8 ADC_u8ChainIndex = 0;

/*
    Description: This function shall initiate ADC driver by setting reference voltage, setting adjustment, setting prescaler and enabling ADC
    Input: void
    output: u8 -> represents error status
*/
extern u8 ADC_u8Init(void)
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  /* Setting reference voltage -> AVCC*/
  CLR_BIT(ADMUX,ADMUX_REFS1_BIT);
  SET_BIT(ADMUX,ADMUX_REFS0_BIT);
  
  /* Setting adjustment mode -> Left */
  SET_BIT(ADMUX,ADMUX_ADLAR_BIT);
  
  /* Enable ADC */
  SET_BIT(ADCSRA,ADCSRA_ADEN_BIT);
  
  /* Setting prescaler */
  SET_BIT(ADCSRA,ADCSRA_ADPS2_BIT);
  SET_BIT(ADCSRA,ADCSRA_ADPS1_BIT);
  SET_BIT(ADCSRA,ADCSRA_ADPS0_BIT);
  
  return Local_u8ErrorStatus;
  
}

/*
    Description: This function shall set the channel number, start conversion, poll on the flag, set pointer with digital value and clear flag.
    Input: 
          1- u8 Copy_u8Channel -> represents the channel number
          2- Copy_u16PrtConvData -> pointer that holds the digital value
    output: u8 -> represents error status
*/
extern u8 ADC_u8GetChannelReadingSynchronous (u8 Copy_u8Channel,u16 * Copy_u16PtrConvData)
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  u32 Local_u32TimeOut = 0;
  
  /* Checking that pointer is not equal to NULL and channel number is in the range of allowable channels*/
  if (Copy_u16PtrConvData == NULL)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NULL_POINTER;
  }
  else if (Copy_u8Channel > MAX_NUMBER_OF_CHANNELS)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NOK;
  }
  else
  {
    /* Clear channel fields */
    ADMUX &= ADMUX_CHANNEL_CLEAR;
    /* Choose channel */
    ADMUX |= Copy_u8Channel;
    
    /* Start conversion */
    SET_BIT(ADMUX,ADCSRA_ADSC_BIT);
    
    /* Polling on the conversion complete flag  and checking for timeout parameter */
    while (GET_BIT(ADCSRA,ADCSRA_ADIF_BIT) == 0 && Local_u32TimeOut < ADC_u32TIME_OUT_COUNT)
    {
      Local_u32TimeOut ++;
    }
    
    /* The polling is interrupted by timeout */
    if (Local_u32TimeOut >= ADC_u32TIME_OUT_COUNT)
    {
      Local_u8ErrorStatus = STD_TYPES_ERROR_NOK;
    }
    else
    {
        /* Conversion is done */
        
        /* Clear conversion flag */
        SET_BIT(ADCSRA,ADCSRA_ADIF_BIT);
        
        /* Read conversion result */
        #if ADC_u8_RESOLUTION == ADC_u8_8BITS_RESOLUTION
          * Copy_u16PtrConvData = ADCH;
        #elif ADC_u8_RESOLUTION == ADC_u8_10BITS_RESOLUTION
          * Copy_u16PtrConvData = ADC;
        #endif
    }
    
  }
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall set the channel number, waits for ISR and set pointer with digital value. 
    Input: 
          1- u8 Copy_u8Channel -> represents the channel number
          2- Copy_u16PrtConvData -> pointer that holds the digital value
          3- Copy_ptrNotificationFn -> pointer to function that is called at the end of conversion
    output: u8 -> represents error status
*/
extern u8 ADC_u8GetChannelReadingAsynchronous (u8 Copy_u8Channel,u16 * Copy_u16PtrConvData, void(*Copy_ptrNotificationFn)(void))
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  /* Checking that pointers is not equal to NULL and channel number is in the range of allowable channels*/
  if (Copy_u16PtrConvData == NULL || Copy_ptrNotificationFn == NULL)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NULL_POINTER;
  }
  else if (Copy_u8Channel > MAX_NUMBER_OF_CHANNELS)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NOK; 
  }
  else
  {
    if (ADC_u8ADCState == ADC_u8_STATE_IDLE)
    {
      /* Initiating objects -> setting ADC state to busy and ISR state to single conversion */
      ADC_u8ADCState = ADC_u8_STATE_BUSY;
      ADC_u8ISRState = ADC_u8_SINGLE_CONVERSION;
      
      /* Initiating objects -> global pointer to function and global pointer to variable */
      GlobalPtrFunc = Copy_ptrNotificationFn;
      ADC_u16ADCResult = Copy_u16PtrConvData;
      
      /* Clear channel fields */
      ADMUX &= ADMUX_CHANNEL_CLEAR;
      /* Choose channel */
      ADMUX |= Copy_u8Channel;
      
      /* Enable interrupt of ADC */
      SET_BIT(ADCSRA,ADCSRA_ADIE_BIT);
      
      /* Start conversion */
      SET_BIT(ADMUX,ADCSRA_ADSC_BIT);
    }
    else
    {
      Local_u8ErrorStatus = STD_TYPES_ERROR_NOK; 
    }
  }
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall initialize chain by setting the array of channel and length of chain
    Input: 
          1- Copy_objectChain -> pointer to object of ADC_Chain passed by user
          2- Copy_u8PtrToChannels -> pointer to array of channels
          3- Copy_u8Length -> length of array of channels
          4- Copy_u16PtrResults -> pointer to array that hold results of digital values
    output: u8 -> represents error status
*/
extern u8 ADC_u8ChainInit (ADC_Chain * Copy_objectChain, u8 * Copy_u8PtrToChannels, u8 Copy_u8Length, u16 * Copy_u16PtrResults)
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  if (Copy_objectChain == NULL || Copy_u8PtrToChannels == NULL || Copy_u16PtrResults == NULL )
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NULL_POINTER;
  }
  else
  {
    Copy_objectChain->ptrChain = Copy_u8PtrToChannels;
    Copy_objectChain->length = Copy_u8Length;
    Copy_objectChain->ptrResults = Copy_u16PtrResults;
  }
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall start conversion of chain
    Input: 
          1- u8 Copy_objectChain -> pointer to object of ADC_Chain
          2- Copy_ptrNotificationFn -> pointer to function that is called at the end of conversion
    output: u8 -> represents error status
*/
extern u8 ADC_u8StartChainConversionAsynchronous (ADC_Chain *Copy_objectChain,void(*Copy_ptrNotificationFn)(void))
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  if (Copy_ptrNotificationFn == NULL || Copy_objectChain == NULL)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NULL_POINTER;
  }
  else if (ADC_u8ADCState == ADC_u8_STATE_BUSY)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NOK;
  }
  else
  {
    /* Ready to convert */
    
    /* Initiating objects -> setting ADC state to busy and ISR state to chain conversion */
    ADC_u8ADCState = ADC_u8_STATE_BUSY;
    ADC_u8ISRState = ADC_u8_CHAIN_CONVERSION;
    
    /* Initiating objects */
    GlobalPtrFunc = Copy_ptrNotificationFn;
    ADC_ChainArr = Copy_objectChain->ptrChain;
    ADC_ChainLength = Copy_objectChain->length;
    ADC_u16ADCResult = Copy_objectChain->ptrResults;
    
    /* Starting conversion for the first channel in chain */
    ADC_u8ChainIndex = 0;
    
    /* Clear channel fields */
    ADMUX &= ADMUX_CHANNEL_CLEAR;
    /* Choose channel */
    ADMUX |= ADC_ChainArr[ADC_u8ChainIndex];

    /* Enable interrupt of ADC */
    SET_BIT(ADCSRA,ADCSRA_ADIE_BIT);
    
    /* Start conversion */
    SET_BIT(ADMUX,ADCSRA_ADSC_BIT);
  }
  
  return Local_u8ErrorStatus;
}

/* ISR */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
  if (ADC_u8ISRState == ADC_u8_SINGLE_CONVERSION)
  {
    /* Read conversion result */
    #if ADC_u8_RESOLUTION == ADC_u8_8BITS_RESOLUTION
      * ADC_u16ADCResult = ADCH;
    #elif ADC_u8_RESOLUTION == ADC_u8_10BITS_RESOLUTION
      * ADC_u16ADCResult = ADC;
    #endif
    
    ADC_u8ADCState = ADC_u8_STATE_IDLE;
    
    /* Disable interrupt of ADC */
    CLR_BIT(ADCSRA,ADCSRA_ADIE_BIT);
    
    /* Call notification function */
    GlobalPtrFunc();
  }
  else if (ADC_u8ISRState == ADC_u8_CHAIN_CONVERSION)
  {
    /* Read conversion result */
    #if ADC_u8_RESOLUTION == ADC_u8_8BITS_RESOLUTION
      ADC_u16ADCResult[ADC_u8ChainIndex] = ADCH;
    #elif ADC_u8_RESOLUTION == ADC_u8_10BITS_RESOLUTION
      ADC_u16ADCResult[ADC_u8ChainIndex] = ADC;
    #endif
    
    /* Increament index of chain */
    ADC_u8ChainIndex++;
    
    /* If all channels are converted */
    if (ADC_u8ChainIndex == ADC_ChainLength)
    {
      ADC_u8ADCState = ADC_u8_STATE_IDLE;
      /* Disable interrupt of ADC */
      CLR_BIT(ADCSRA,ADCSRA_ADIE_BIT);
      /* Call notification function */
      GlobalPtrFunc();
    }
    else
    {
      /* Clear channel fields */
      ADMUX &= ADMUX_CHANNEL_CLEAR;
      /* Choose channel */
      ADMUX |= ADC_ChainArr[ADC_u8ChainIndex];
      
      /* Start conversion */
      SET_BIT(ADMUX,ADCSRA_ADSC_BIT);
    }
  }
}