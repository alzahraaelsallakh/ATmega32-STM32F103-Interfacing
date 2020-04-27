/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 22 Apr 2020                            */
/* Layer: HAL                                   */
/* Component: NOKIA                             */
/* File Name: NOKIA_program.c                   */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "NOKIA_interface.h"
#include "NOKIA_config.h"
#include "NOKIA_private.h"


/*
    Description: This function shall initiate NOKIA
    Input: void
    output: STD_TYPES_ERROR
 */
STD_TYPES_ERROR NOKIA_errInit (void)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	/*
	 * Initialization commands:
	 * 1- Reset pulse
	 * 2- Go to extended mode
	 * 3- Configure extended commands
	 * 4- Go back to normal mode
	 *  */

	/* 1- Reset pulse*/
	/* High for 2ms then Low for 2ms then High */
	DIO_voidSetPinValue(NOKIA_RST_PORT,NOKIA_RST_PIN,1);
	STK_voidBusyDelay(2000);

	DIO_voidSetPinValue(NOKIA_RST_PORT,NOKIA_RST_PIN,0);
	STK_voidBusyDelay(2000);

	DIO_voidSetPinValue(NOKIA_RST_PORT,NOKIA_RST_PIN,1);

	/* 2- Go to extended mode */
	/* Horizontal mode */
	NOKIA_voidWriteCommand(0b00100001);

	/* 3- Configure extended commands */
	/* VLCD temperature coefficient 2 -> Typical curve */
	NOKIA_voidWriteCommand(0b00000110);
	/* Bias system */
	NOKIA_voidWriteCommand(0b00010011);
	/* Set Vop -> Contrast (SW potentiometer) */
	NOKIA_voidWriteCommand(0xBE);


	/* 4- Go back to normal mode */
	NOKIA_voidWriteCommand(0b00100000);

	/******************* End of Init commands ******************/

	/* Display control command */
	/* Normal display mode */
	NOKIA_voidWriteCommand(0b00001100);


	return Local_errStatus;
}


/*
    Description: This function shall display data on Nokia LCD
    Input:
    		1- Copy_u8DataArray -> Pointer to data to be displayed
    output: STD_TYPES_ERROR
 */
STD_TYPES_ERROR NOKIA_errDisplay (u8 * Copy_u8DataArray)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	/* X = 0 and Y = 0 */
	NOKIA_voidWriteCommand(0b01000000); /* Y = 0 */
	NOKIA_voidWriteCommand(0b10000000); /* X = 0 */

	u16 Local_u8PixelIterator;

	for (Local_u8PixelIterator = 0; Local_u8PixelIterator < 504; Local_u8PixelIterator++)
	{
		NOKIA_voidWriteData(Copy_u8DataArray[Local_u8PixelIterator]);
	}


	return Local_errStatus;
}

static void NOKIA_voidWriteData (u8 Copy_u8Data)
{

	u8 dummy;

	/* Clear CE pin */
	DIO_voidSetPinValue(NOKIA_CE_PORT,NOKIA_CE_PIN,0);

	/* DC = 1 for data */
	DIO_voidSetPinValue(NOKIA_DC_PORT,NOKIA_DC_PIN,1);

	/* Send data over SPI */
	SPI1_errSendRecvSynch(Copy_u8Data, &dummy);

	/* Set CE Pin */
	DIO_voidSetPinValue(NOKIA_CE_PORT,NOKIA_CE_PIN,1);

}

static void NOKIA_voidWriteCommand (u8 Copy_u8Command)
{
	u8 dummy;

	/* Clear CE pin */
	DIO_voidSetPinValue(NOKIA_CE_PORT,NOKIA_CE_PIN,0);

	/* DC = 1 for data */
	DIO_voidSetPinValue(NOKIA_DC_PORT,NOKIA_DC_PIN,0);

	/* Send data over SPI */
	SPI1_errSendRecvSynch(Copy_u8Command, &dummy);

	/* Set CE Pin */
	DIO_voidSetPinValue(NOKIA_CE_PORT,NOKIA_CE_PIN,1);
}
