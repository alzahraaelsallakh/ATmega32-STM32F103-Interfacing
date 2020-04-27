/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 27 Apr 2020                            */
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
extern STD_TYPES_ERROR SPI_errInit (void);

/*
    Description: This function shall send byte synchronously
    Input:
    		1- Copy_u8SentByte -> Byte to be sent
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR SPI_errSendDataByteSynch(u8 Copy_u8SentByte);

/*
    Description: This function shall receive byte synchronously
    Input:
    		1- Copy_u8ReceivedByte -> Pointer to hold received data
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR SPI_errReceiveDataByteSynch(u8 * Copy_u8ReceivedByte);

/*
    Description: This function shall send and receive byte synchronously
    Input:
    		1- Copy_u8SentByte -> Byte to be sent
    		2- Copy_u8ReceivedByte -> Pointer to hold received data
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR SPI_errSendReceiveByteSynch(u8 Copy_u8SentByte, u8 * Copy_u8ReceivedByte);

/*
    Description: This function shall send and receive byte asynchronously
    Input:
    		1- Copy_u8SentBuffer -> Pointer to hold sent data buffer
    		2- Copy_u8ReceivedBuffer -> Pointer to hold received data buffer
    		3- Copy_u8BufferSize -> Size of buffer
    		4- Copy_ptrCallBackFn -> Pointer to callback function
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR SPI_errSendReceiveBufferAsynch(u8 * Copy_u8SentBuffer, u8 * Copy_u8ReceivedBuffer, u8 Copy_u8BufferSize,void (*Copy_ptrCallBackFn)(void));




#endif
