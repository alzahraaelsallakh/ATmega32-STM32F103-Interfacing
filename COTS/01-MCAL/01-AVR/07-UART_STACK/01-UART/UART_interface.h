/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 09 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: UART                              */
/* File Name: UART_interface.h                  */
/************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


/*
    Description: This function shall initiate UART  
    Input: void
    output: u8 -> represents error status
*/
extern u8 UART_u8Initialize (void);

/*
    Description: This function shall transmit data synchronous
    Input: Copy_u8Data -> represents data to be transmitted
    output: u8 -> represents error status
*/
extern u8 UART_u8TransmitDataSynch (u8 Copy_u8Data);

/*
    Description: This function shall transmit data asynchronous
    Input: 
          1- Copy_u8Data -> represents data to be transmitted
          2- Copy_ptrCallBack -> pointer to callback function
    output: u8 -> represents error status
*/
extern u8 UART_u8TransmitDataAsynch (u8 Copy_u8Data, void(*Copy_ptrCallBack)(void));

/*
    Description: This function shall receive data synchronous
    Input: 
          1- Copy_u8Data -> pointer to hold received data 
    output: u8 -> represents error status
*/
extern u8 UART_u8ReceiveSynch (u8 * Copy_u8PtrData);

/*
    Description: This function shall receive data asynchronous
    Input: Copy_ptrCallBack -> pointer to callback function, with argument u8 that holds the received data 
    output: u8 -> represents error status
*/
extern u8 UART_u8ReceiveAsynch (void(*Copy_ptrCallBack)(u8));

#endif
