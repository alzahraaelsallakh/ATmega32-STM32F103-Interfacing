/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 22 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: SPI                               */
/* File Name: SPI_interface.h                   */
/************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



/*
    Description: This function shall initiate SPI
    Input: void
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR SPI1_errInit (void);

/*
    Description: This function shall send/receive 8 bits of data through SPI
    Input:
    		1- Copy_u8SentData -> Data to be sent
    		2- Copy_u8ReceivedData -> Pointer to hold received data
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR  SPI1_errSendRecvSynch(u8 Copy_u8SentData,u8 *Copy_u8ReceivedData);

#endif
