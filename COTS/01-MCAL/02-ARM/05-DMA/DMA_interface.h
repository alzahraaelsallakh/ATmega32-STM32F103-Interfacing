/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 30 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: DMA                               */
/* File Name: DMA_interface.h                   */
/************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/*
    Description: This function shall initiate channel 1
    Input: void
    output: STD_TYPES_ERROR 
*/
extern STD_TYPES_ERROR DMA_errInit (void);

/*
    Description: This function shall start channel 1
    Input: 
          1- Copy_u16SourceAddress -> Source address
          2- Copy_u16DestinationAddress -> Destination address
          3- Copy_u16BlockLength -> Block length
    output: STD_TYPES_ERROR 
*/
extern STD_TYPES_ERROR DMA_errStart (u32 Copy_u16SourceAddress,u32 Copy_u16DestinationAddress, u16 Copy_u16BlockLength);



#endif
