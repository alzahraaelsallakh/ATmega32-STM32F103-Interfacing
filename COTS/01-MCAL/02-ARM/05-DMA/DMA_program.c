/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 30 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: DMA                               */
/* File Name: DMA_program.c                     */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_register.h"
#include "DMA_private.h"


/*
    Description: This function shall initiate channel 1
    Input: void
    output: STD_TYPES_ERROR 
*/
extern STD_TYPES_ERROR DMA_errInit (void)
{
  /* 
      Enable M2M
      Data size 32 bit
      MINC and PINC = 1
      No circular
      DIR CPAR -> CMAR
      Enable Transmission complete interrupt
  */
  
  DMA -> Channel[0].CCR = 0x00007AC2;
}

/*
    Description: This function shall start channel 1
    Input: 
          1- Copy_u32SourceAddress -> Source address
          2- Copy_u32DestinationAddress -> Destination address
          3- Copy_u16BlockLength -> Block length
    output: STD_TYPES_ERROR 
*/
extern STD_TYPES_ERROR DMA_errStart (u32 Copy_u32SourceAddress,u32 Copy_u32DestinationAddress, u16 Copy_u16BlockLength)
{
  DMA -> Channel[0].CPAR = Copy_u32SourceAddress;
  DMA -> Channel[0].CMAR = Copy_u32DestinationAddress;
  DMA -> Channel[0].CNDTR = Copy_u16BlockLength;
  
  /* Enable Transmission */
  DMA -> Channel[0].CCR |= 1;
}

