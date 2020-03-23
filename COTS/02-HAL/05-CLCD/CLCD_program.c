/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 14 Jan 2020                          */
/* Layer: HAL                                 */
/* Component: CLCD                            */
/* File Name: CLCD_program.c                  */
/**********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

static void CLCD_voidSetEnablePulse ();

/* Description: This API shall initialize LCD */
extern void CLCD_voidInitialize (void)
{
    Delay_ms(40);
    #if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE 
    
      /* Set RS = 0 */
      DIO_voidSetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
      /* Set RW = 0 */
      DIO_voidSetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
      /* Send 0010 */
      CLCD_voidSetHalfDataPort(0b0010);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();
      /* Send 0010 */
      CLCD_voidSetHalfDataPort(0b0010);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();
      /* DB7 = N >> Number of Lines, starting from 0 */
      /* DB6 = F >> Size of Font */
      CLCD_voidSetHalfDataPort(0b1100);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();
      
    #elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE 
      /* DB3 = N >> Number of Lines, starting from 0 */
      /* DB4 = F >> Size of Font */
      CLCD_voidWriteCmd(0b00111000);
      
    #else #error "Wrong Data Length Choice"
    
    #endif
      /* DB2 = D >> Display On/Off */
      /* DB1 = C >> Show Cursor */
      /* DB0 = B >> Blinking Cursor On/ Off*/
      CLCD_voidWriteCmd(0b00001100);
      
      CLCD_voidWriteCmd(0b00000001);
}

extern void CLCD_Clear()
{
	CLCD_voidWriteCmd(0b00000001);
}


/* Description: This API shall display data on
                                          LCD */
extern void CLCD_voidWriteData (u8 Copy_u8Data)
{
    /* Set RS = 1 */
    DIO_voidSetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
    /* Set RW = 0 */
    DIO_voidSetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
    
    #if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
    
      /* Set high order 4 bits of cmd */
      CLCD_voidSetHalfDataPort (Copy_u8Data >> 4);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();
      /* Set low order 4 bits of cmd */
      CLCD_voidSetHalfDataPort (Copy_u8Data);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();

    
    #elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE 
      /* Set data on data port */
      CLCD_voidSetDataPort (Copy_u8Cmd);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse();
    
    #else #error "Wrong Data Length Choice"
    
    #endif
    
}

/* Description: This API shall send comman to 
                                          LCD */
extern void CLCD_voidWriteCmd (u8 Copy_u8Cmd)
{
    /* Set RS = 0 */
    DIO_voidSetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
    /* Set RW = 0 */
    DIO_voidSetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
    
    #if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
    
      /* Set high order 4 bits of cmd */
      CLCD_voidSetHalfDataPort (Copy_u8Cmd >> 4);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();
      /* Set low order 4 bits of cmd */
      CLCD_voidSetHalfDataPort (Copy_u8Cmd);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse ();

    
    #elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE 
      /* Set data on data port */
      CLCD_voidSetDataPort (Copy_u8Cmd);
      /* Send Enable Pulse */
      CLCD_voidSetEnablePulse();
    
    #else #error "Wrong Data Length Choice"
    
    #endif
    
    
}


static void CLCD_voidSetEnablePulse ()
{
      /* Enable pulse */  
      DIO_voidSetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
      Delay_ms(1);
      DIO_voidSetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
      Delay_ms(1);
}

static void CLCD_voidSetHalfDataPort (u8 Copy_u8Data)
{
    u8 Local_u8BitVal;
    
    Local_u8BitVal = GET_BIT(Copy_u8Data,0);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,1);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,2);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,3);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);
}

static void CLCD_voidSetDataPort (u8 Copy_u8Data)
{
    u8 Local_u8BitVal;
    
    Local_u8BitVal = GET_BIT(Copy_u8Data,0);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D0_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,1);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D1_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,2);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D2_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,3);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D3_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,4);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,5);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,6);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);
    Local_u8BitVal = GET_BIT(Copy_u8Data,7);
    DIO_voidSetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);
}

extern void CLCD_voidGotoLocation(u8 Copy_LineNumber,u8 Copy_Postiion)
{
	if(Copy_LineNumber == CLCD_LINE_1)
	{
		CLCD_voidWriteCmd(CLCD_LINE_1_CMD + Copy_Postiion);
	}
	else if(Copy_LineNumber == CLCD_LINE_2)
	{
		CLCD_voidWriteCmd(CLCD_LINE_2_CMD + Copy_Postiion);
	}
	else{}
}


extern void CLCD_voidWriteString(u8 *Copy_pu8String)
{
	u8 Local_u8Index=0;
	while (Copy_pu8String[Local_u8Index] != '\0')
	{
		CLCD_voidWriteData(Copy_pu8String[Local_u8Index]);
		Local_u8Index++;

	}
}