/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 09 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: UART                              */
/* File Name: UART_program.c                    */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_register.h"
#include "UART_private.h"


const u8 BaudRateValue [3][3] =
{
  /* 4800  , 9600  ,  115200 */
  {  0x67  , 0x33  ,  0x03    }, /* System Frequency 0 -> 8M */
  {  154   ,  77   ,     6    }, /* System Frequency 1 -> 12M */
  {  0xCF  , 0x67  ,  0x08    }  /* System Frequency 2 -> 16M */
};

void (*EndOfTransmit)(void);
void (*EndOfReceive)(u8);

/*
    Description: This function shall initiate UART  
    Input: void
    output: u8 -> represents error status
*/
extern u8 UART_u8Initialize (void)
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  /* U2X = 0 */
  CLR_BIT(UCSRA,1);
  
  /* Disable all interrupts and enable receiver and transmitter */
  UCSRB = 0x18;
  
  /*
    bit 7 -> register select
    bit 6 -> Asynch mode
    bit 4,5 -> parity
    bit 3 -> stop bit
    bit 1,2 -> character size -> 8 bits
  */
  UCSRC = (1<<7) |
          (UART_u8_PARITY<<4) |
          (UART_u8_STOP_BITS<<3) |
          (3 << 1);
          
          
  /* Assign Baudrate */
  UBRRL = BaudRateValue[UART_u8_SYSTEM_FREQ][UART_u8_BAUDRATE];
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall transmit data synchronous
    Input: Copy_u8Data -> represents data to be transmitted
    output: u8 -> represents error status
*/
extern u8 UART_u8TransmitDataSynch (u8 Copy_u8Data)
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  u32 Local_u32TimeOut = 0;
  
  /* Send data on UDR */
  UDR_T = Copy_u8Data;
  
  /* Polling on flag and checking timeout*/
  while (GET_BIT(UCSRA,6) == 0 && Local_u32TimeOut < UART_u32_TIME_OUT_THRESHOLD)
  {
    Local_u32TimeOut ++;
  }
  
  if (Local_u32TimeOut >= UART_u32_TIME_OUT_THRESHOLD)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NOK;
  }
  else
  {
    /* Clear flag */
    SET_BIT(UCSRA,6);
  }
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall transmit data asynchronous
    Input: 
          1- Copy_u8Data -> represents data to be transmitted
          2- Copy_ptrCallBack -> pointer to callback function
    output: u8 -> represents error status
*/
extern u8 UART_u8TransmitDataAsynch (u8 Copy_u8Data, void(*Copy_ptrCallBack)(void))
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  if (Copy_ptrCallBack == NULL)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NULL_POINTER;
  }
  
  /* Enable Tx interrupt */
  SET_BIT(UCSRB,6);
  
  /* Set data to UDR */
  UDR_T = Copy_u8Data;
  
  /* Save the callback address */
  EndOfTransmit = Copy_ptrCallBack;
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall receive data synchronous
    Input: 
          1- Copy_u8Data -> pointer to hold received data 
    output: u8 -> represents error status
*/
extern u8 UART_u8ReceiveSynch (u8 * Copy_u8PtrData)
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  u32 Local_u32TimeOut = 0;
  
  /* Polling on flag and checking timeout*/
  while (GET_BIT(UCSRA,7) == 0 && Local_u32TimeOut < UART_u32_TIME_OUT_THRESHOLD)
  {
    Local_u32TimeOut ++;
  }
  
  if (Local_u32TimeOut >= UART_u32_TIME_OUT_THRESHOLD)
  {
    Local_u8ErrorStatus = STD_TYPES_ERROR_NOK;
  }
  else
  {
    /* Set data to receieved pointer */
    *Copy_u8PtrData = UDR_R;
  }
  
  return Local_u8ErrorStatus;
}

/*
    Description: This function shall receive data asynchronous
    Input: Copy_ptrCallBack -> pointer to callback function, with argument u8 that holds the received data 
    output: u8 -> represents error status
*/
extern u8 UART_u8ReceiveAsynch (void(*Copy_ptrCallBack)(u8))
{
  u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;
  
  /* Check if there is data received */
  if (GET_BIT(UCSRA,7) == 1)
  {
    Copy_ptrCallBack(UDR);
  }
  /* Nothing to receive now, enable receive enable interrupt */
  else
  {
    /* Enable Rx interrupt */
    SET_BIT(UCSRB,7);
    /* Save the callback address */
    EndOfReceive = Copy_ptrCallBack;
  }
  
  return Local_u8ErrorStatus;
}