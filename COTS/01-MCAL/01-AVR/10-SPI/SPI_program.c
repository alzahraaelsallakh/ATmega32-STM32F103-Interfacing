/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 27 Apr 2020                            */
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


/* Global pointers */

static u8 * SPI_u8SentBuffer = NULL;
static u8 * SPI_u8ReceivedBuffer = NULL;
static u8 SPI_u8BufferSize;
static u8 SPI_u8BufferIndex;
static u8 SPI_u8BusyFlag;

static void (*SPI_PtrNotifyFn)(void) = NULL;


/*
    Description: This function shall initiate SPI
    Input: void
    output: STD_TYPES_ERROR
 */
STD_TYPES_ERROR SPI_errInit (void)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	/* Choosing master/slave mode */
#if SPI_u8_SELECT_MODE == SPI_u8_MASTER
	SET_BIT(SPCR,SPCR_MSTR);
	/* Setting clock rate */
#if SPI_u8_CLK_RATE   ==  SPI_u8_CLK_OVER_4
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPCR_SPR0);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_CLK_OVER_16
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_CLK_OVER_64
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_CLK_OVER_128
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_HCLK_OVER_2
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_HCLK_OVER_8
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_HCLK_OVER_32
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8_CLK_RATE   ==  SPI_u8_HCLK_OVER_2
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#endif

#elif SPI_u8_SELECT_MODE == SPI_u8_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#endif

	/* Selecting data order */
#if   SPI_u8_DATA_ORDER == SPI_u8_MSB
	CLR_BIT(SPCR,SPCR_DORD);
#elif SPI_u8_DATA_ORDER == SPI_u8_LSB
	SET_BIT(SPCR,SPCR_DORD);
#endif

	/* Selecting clock polarity */
#if   SPI_u8_CLK_POL    == SPI_u8_FALLING_EDGE
	SET_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8_CLK_POL    == SPI_u8_RAISING_EDGE
	CLR_BIT(SPCR,SPCR_CPOL);
#endif

	/* Selecting clock phase */
#if   SPI_u8_CLK_PHASE  == SPI_u8_SAMPLE
	CLR_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8_CLK_PHASE  == SPI_u8_SETUP
	SET_BIT(SPCR,SPCR_CPHA);
#endif

	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);


	return Local_errStatus;

}

/*
    Description: This function shall send byte synchronously
    Input:
    		1- Copy_u8SentByte -> Byte to be sent
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR SPI_errSendDataByteSynch(u8 Copy_u8SentByte)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;


	u16 Local_u16TimeOutCounter = 0;

	SPDR = Copy_u8SentByte;

	/* Check collision flag */
	if (GET_BIT(SPSR,SPSR_WCOL) == 1)
	{
		Local_errStatus = STD_TYPES_ERROR_NOK;
	}

	/* Wait until transmission is completed */
	while( (GET_BIT(SPSR,SPSR_SPIF) == 0) && (Local_u16TimeOutCounter < SPI_u16_TIMEOUT) )
	{
		Local_u16TimeOutCounter++;
	}
	if (Local_u16TimeOutCounter >= SPI_u16_TIMEOUT)
	{
		Local_errStatus = STD_TYPES_ERROR_NOK;
	}

	return Local_errStatus;
}

/*
    Description: This function shall receive byte synchronously
    Input:
    		1- Copy_u8ReceivedByte -> Pointer to hold received data
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR SPI_errReceiveDataByteSynch(u8 * Copy_u8ReceivedByte)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	u16 Local_u16TimeOutCounter = 0;

	/* Checking for NULL pointer */
	if(Copy_u8ReceivedByte == NULL)
	{
		Local_errStatus = STD_TYPES_ERROR_NULL_POINTER;
	}
	else
	{
		/* Wait until Transmission is completed */
		while( (GET_BIT(SPSR,SPSR_SPIF) == 0) && (Local_u16TimeOutCounter < SPI_u16_TIMEOUT) )
		{
			Local_u16TimeOutCounter++;
		}
		if(Local_u16TimeOutCounter >= SPI_u16_TIMEOUT)
		{
			Local_errStatus = STD_TYPES_ERROR_NOK;
		}
		else
		{
			*Copy_u8ReceivedByte = SPDR;
		}
	}

	return Local_errStatus;
}

/*
    Description: This function shall send and receive byte synchronously
    Input:
    		1- Copy_u8SentByte -> Byte to be sent
    		2- Copy_u8ReceivedByte -> Pointer to hold received data
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR SPI_errSendReceiveByteSynch(u8 Copy_u8SentByte, u8 * Copy_u8ReceivedByte)
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	u16 Local_u16TimeOutCounter = 0;

	/* Checking for NULL pointer */
	if(Copy_u8ReceivedByte == NULL)
	{
		Local_errStatus = STD_TYPES_ERROR_NULL_POINTER;
	}
	else
	{
		/* Writing data into data register */
		SPDR = Copy_u8SentByte;

		/* Checking collision flag */
		if( GET_BIT(SPSR,SPSR_WCOL) == 1)
		{
			Local_errStatus = STD_TYPES_ERROR_NOK;
		}

		/* Wait until transmission is completed */
		while( (GET_BIT(SPSR,SPSR_SPIF) == 0) && (Local_u16TimeOutCounter < SPI_u16_TIMEOUT) )
		{
			Local_u16TimeOutCounter++;
		}

		if(Local_u16TimeOutCounter >= SPI_u16_TIMEOUT)
		{
			Local_errStatus = STD_TYPES_ERROR_NOK;
		}
		else
		{
			*Copy_u8ReceivedByte = SPDR;
		}
	}

	return Local_errStatus;
}

/*
    Description: This function shall send and receive byte asynchronously
    Input:
    		1- Copy_u8SentBuffer -> Pointer to hold sent data buffer
    		2- Copy_u8ReceivedBuffer -> Pointer to hold received data buffer
    		3- Copy_u8BufferSize -> Size of buffer
    		4- Copy_ptrCallBackFn -> Pointer to callback function
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR SPI_errSendReceiveBufferAsynch(u8 * Copy_u8SentBuffer, u8 * Copy_u8ReceivedBuffer, u8 Copy_u8BufferSize,void (*Copy_ptrCallBackFn)(void))
{
	STD_TYPES_ERROR Local_errStatus = STD_TYPES_ERROR_OK;

	/* Checking for NULL pointer */
	if (Copy_u8SentBuffer == NULL || Copy_u8ReceivedBuffer == NULL || Copy_ptrCallBackFn == NULL)
	{
		Local_errStatus = STD_TYPES_ERROR_NULL_POINTER;
	}
	else if (SPI_u8BusyFlag == 1)
	{
		Local_errStatus = STD_TYPES_ERROR_NOK;
	}
	else
	{
		/* Set busy flag */
		SPI_u8BusyFlag = 1;

		/* Initialize global pointers */
		SPI_u8SentBuffer = Copy_u8SentBuffer;
		SPI_u8ReceivedBuffer = Copy_u8ReceivedBuffer;
		SPI_u8BufferSize = Copy_u8BufferSize;
		SPI_PtrNotifyFn = Copy_ptrCallBackFn;

		/* Sending first byte */
		SPDR = SPI_u8SentBuffer[SPI_u8BufferIndex];

		/* Enable SPI interrupt */
		SET_BIT(SPCR,SPCR_SPIE);
	}


	return Local_errStatus;
}

ISR(12)
{
	/* Reading data byte */
	SPI_u8ReceivedBuffer[SPI_u8BufferIndex] = SPDR;

	/* Incrementing buffer index */
	SPI_u8BufferIndex++;

	/* Checking if buffer index is equal to buffer size or not */
	if (SPI_u8BufferIndex == SPI_u8BufferSize)
	{

		/* Disable SPI interrupt */
		CLR_BIT(SPCR,SPCR_SPIE);

		/* Clear buffer index */
		SPI_u8BufferIndex = 0;

		/* Call notification function */
		SPI_PtrNotifyFn();

		/* Clear busy flag */
		SPI_u8BusyFlag = 0;
	}
	else
	{
		/* Sending next byte */
		SPDR = SPI_u8SentBuffer[SPI_u8BufferIndex];
	}
}


