/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_interface.h                   */
/************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/* Single Ended Input */
#define ADC_u8_CHANNEL_0    0
#define ADC_u8_CHANNEL_1    1
#define ADC_u8_CHANNEL_2    2
#define ADC_u8_CHANNEL_3    3
#define ADC_u8_CHANNEL_4    4
#define ADC_u8_CHANNEL_5    5
#define ADC_u8_CHANNEL_6    6
#define ADC_u8_CHANNEL_7    7

typedef struct 
{
  u8 * ptrChain;
  u8  length;
  u16 * ptrResults;
} ADC_Chain;

/*
    Description: This function shall initiate ADC driver by setting reference voltage, setting adjustment, setting prescaler and enabling ADC
    Input: void
    output: u8 -> represents error status
*/
extern u8 ADC_u8Init(void);

/*
    Description: This function shall set the channel number, start conversion, poll on the flag, set pointer with digital value and clear flag.
    Input: 
          1- u8 Copy_u8Channel -> represents the channel number
          2- Copy_u16PrtConvData -> pointer that holds the digital value
    output: u8 -> represents error status
*/
extern u8 ADC_u8GetChannelReadingSynchronous (u8 Copy_u8Channel,u16 * Copy_u16PtrConvData);

/*
    Description: This function shall set the channel number, waits for ISR and set pointer with digital value. 
    Input: 
          1- u8 Copy_u8Channel -> represents the channel number
          2- Copy_u16PrtConvData -> pointer that holds the digital value
          3- Copy_ptrNotificationFn -> pointer to function that is called at the end of conversion
    output: u8 -> represents error status
*/
extern u8 ADC_u8GetChannelReadingAsynchronous (u8 Copy_u8Channel,u16 * Copy_u16PtrConvData, void(*Copy_ptrNotificationFn)(void));


/*
    Description: This function shall initialize chain by setting the array of channel and length of chain
    Input: 
          1- Copy_objectChain -> pointer to object of ADC_Chain passed by user
          2- Copy_u8PtrToChannels -> pointer to array of channels
          3- Copy_u8Length -> length of array of channels
          4- Copy_u16PtrResults -> pointer to array that hold results of digital values
    output: u8 -> represents error status
*/
extern u8 ADC_u8ChainInit (ADC_Chain * Copy_objectChain, u8 * Copy_u8PtrToChannels, u8 Copy_u8Length, u16 * Copy_u16PtrResults);

/*
    Description: This function shall start conversion of chain
    Input: 
          1- u8 Copy_objectChain -> pointer to object of ADC_Chain
          2- Copy_ptrNotificationFn -> pointer to function that is called at the end of conversion
    output: u8 -> represents error status
*/
extern u8 ADC_u8StartChainConversionAsynchronous (ADC_Chain *Copy_objectChain,void(*Copy_ptrNotificationFn)(void));

#endif
