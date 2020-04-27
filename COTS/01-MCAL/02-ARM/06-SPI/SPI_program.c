/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 22 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: SPI                               */
/* File Name: SPI_program.c                     */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_register.h"
#include "SPI_private.h"


/*
    Description: This function shall initiate SPI
    Input: void
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR SPI1_errInit (void)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	/*
	 * Phase -> Write then read
	 * Polarity -> Idle low
	 * Master mode (APB2 clock / 4)
	 * SPI enable and MSB first
	 *SS managed by SW (NSS pin is disconnected from uC)
	 * */
	SPI1->CR1 = 0x034D;

	return Local_errStatus;
}

/*
    Description: This function shall send/receive 8 bits of data through SPI
    Input:
    		1- Copy_u8SentData -> Data to be sent
    		2- Copy_u8ReceivedData -> Pointer to hold received data
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR  SPI1_errSendRecvSynch(u8 Copy_u8SentData,u8 *Copy_u8ReceivedData)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;


	/* Send data*/
	SPI1->DR = Copy_u8SentData;

	/* Wait busy flag */
	while(GET_BIT(SPI1->SR,SR_BSY) == 1);

	/* Receive data */
	*Copy_u8ReceivedData = SPI1->DR;

	return Local_errStatus;
}


