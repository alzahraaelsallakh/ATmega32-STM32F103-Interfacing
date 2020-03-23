/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 21 Feb 2020                            */
/* Layer: HAL                                   */
/* Component: LEDMATRIX                         */
/* File Name: LEDMATRIX_program.c               */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_config.h"
#include "LEDMATRIX_private.h"


/* Defining common and color pins */
#if LEDMATRIX_COMMON == COMMON_ROW
static u8 LEDMATRIX_u8CommonPins[8] = {LEDMATRIX_ROW0PIN,LEDMATRIX_ROW1PIN,LEDMATRIX_ROW2PIN,LEDMATRIX_ROW3PIN,LEDMATRIX_ROW4PIN,LEDMATRIX_ROW5PIN,LEDMATRIX_ROW6PIN,LEDMATRIX_ROW7PIN};
static u8 LEDMATRIX_u8ColorYellowPins[8] = {LEDMATRIX_COL0_YELLOW_PIN,LEDMATRIX_COL1_YELLOW_PIN,LEDMATRIX_COL2_YELLOW_PIN,LEDMATRIX_COL3_YELLOW_PIN,LEDMATRIX_COL4_YELLOW_PIN,LEDMATRIX_COL5_YELLOW_PIN,LEDMATRIX_COL6_YELLOW_PIN,LEDMATRIX_COL7_YELLOW_PIN};
static u8 LEDMATRIX_u8ColorRedPins[8] = {LEDMATRIX_COL0_RED_PIN,LEDMATRIX_COL1_RED_PIN,LEDMATRIX_COL2_RED_PIN,LEDMATRIX_COL3_RED_PIN,LEDMATRIX_COL4_RED_PIN,LEDMATRIX_COL5_RED_PIN,LEDMATRIX_COL6_RED_PIN,LEDMATRIX_COL7_RED_PIN};
#else
static u8 LEDMATRIX_u8CommonPins[8] = {LEDMATRIX_COL0PIN,LEDMATRIX_COL1PIN,LEDMATRIX_COL2PIN,LEDMATRIX_COL3PIN,LEDMATRIX_COL4PIN,LEDMATRIX_COL5PIN,LEDMATRIX_COL6PIN,LEDMATRIX_COL7PIN};
static u8 LEDMATRIX_u8ColorYellowPins[8] = {LEDMATRIX_ROW0_YELLOW_PIN,LEDMATRIX_ROW1_YELLOW_PIN,LEDMATRIX_ROW2_YELLOW_PIN,LEDMATRIX_ROW3_YELLOW_PIN,LEDMATRIX_ROW4_YELLOW_PIN,LEDMATRIX_ROW5_YELLOW_PIN,LEDMATRIX_ROW6_YELLOW_PIN,LEDMATRIX_ROW7_YELLOW_PIN};
static u8 LEDMATRIX_u8ColorRedPins[8] = {LEDMATRIX_ROW0_RED_PIN,LEDMATRIX_ROW1_RED_PIN,LEDMATRIX_ROW2_RED_PIN,LEDMATRIX_ROW3_RED_PIN,LEDMATRIX_ROW4_RED_PIN,LEDMATRIX_ROW5_RED_PIN,LEDMATRIX_ROW6_RED_PIN,LEDMATRIX_ROW7_RED_PIN};
#endif


static u8 LEDMATRIX_u8EnableCommon [8] = {0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};

/*
    Description: This function shall initiate LEDMATRIX, by turning off all leds
    Input: void
    output: void
*/
extern void LEDMATRIX_voidInit ()
{
  u8 Local_u8LoopModeIterator;

  
  /* Disabling all common pins */
  for (Local_u8LoopModeIterator = 0; Local_u8LoopModeIterator < 8; Local_u8LoopModeIterator ++)
  {
    #if LEDMATRIX_MODE == COMMON_ANODE
      DIO_voidSetPinValue(LEDMATRIX_u8CommonPins[Local_u8LoopModeIterator],0);
    #else
      DIO_voidSetPinValue(LEDMATRIX_u8CommonPins[Local_u8LoopModeIterator],1);  
    #endif
  }
}

/*
    Description: This function shall enable specific common to be ready to turn leds on it
    Input: Copy_u8CommonNum which represents common number, its options are:
        1- LEDMATRIX_ROWx where x = 0:7
        1- LEDMATRIX_COLx where x = 0:7

    output: void
*/
extern void LEDMATRIX_voidEnableCommon(u8 Copy_u8CommonNum)
{
    u8 Local_u8LoopModeIterator;
    
    for (Local_u8LoopModeIterator = 0; Local_u8LoopModeIterator < 8 ; Local_u8LoopModeIterator ++)
    {
      #if LEDMATRIX_MODE == COMMON_ANODE
      DIO_voidSetPinValue(LEDMATRIX_u8CommonPins[Local_u8LoopModeIterator],GET_BIT(LEDMATRIX_u8EnableCommon[Copy_u8CommonNum],Local_u8LoopModeIterator));
      #else
      DIO_voidSetPinValue(LEDMATRIX_u8CommonPins[Local_u8LoopModeIterator],GET_BIT(LEDMATRIX_u8EnableCommon[Copy_u8CommonNum],Local_u8LoopModeIterator) ^ 0x01);
      #endif
    }
}

/*
    Description: This function shall enable specific color row/column to be ready to turn leds on it
    Input: 
          1) Copy_u8ColorNum which represents color row/column number, its options are:
            1- LEDMATRIX_ROWx where x = 0:7
            2- LEDMATRIX_COLx where x = 0:7
          2) Copy_u8Color which represents required color of led, its options are:
            1- YELLOW
            2- RED
    output: void
*/
extern void LEDMATRIX_voidEnableColor(u8 Copy_u8ColorNum,u8 Copy_u8Color)
{
  #if LEDMATRIX_MODE == COMMON_ANODE
  if (Copy_u8Color == YELLOW)
  {
    DIO_voidSetPinValue(LEDMATRIX_u8ColorRedPins[Copy_u8ColorNum],1);
    DIO_voidSetPinValue(LEDMATRIX_u8ColorYellowPins[Copy_u8ColorNum],0);
  }
  else
  {
    DIO_voidSetPinValue(LEDMATRIX_u8ColorYellowPins[Copy_u8ColorNum],1);    
    DIO_voidSetPinValue(LEDMATRIX_u8ColorRedPins[Copy_u8ColorNum],0);
  }
  #else
  if (Copy_u8Color == YELLOW)
  {
    DIO_voidSetPinValue(LEDMATRIX_u8ColorRedPins[Copy_u8ColorNum],0);
    DIO_voidSetPinValue(LEDMATRIX_u8ColorYellowPins[Copy_u8ColorNum],1);
  }
  else
  {
    DIO_voidSetPinValue(LEDMATRIX_u8ColorYellowPins[Copy_u8ColorNum],0);    
    DIO_voidSetPinValue(LEDMATRIX_u8ColorRedPins[Copy_u8ColorNum],1);
  }
  #endif
}

/*
    Description: This function shall disable specific color row/column 
    Input: Copy_u8ColorNum which represents color row/column number, its options are:
        1- LEDMATRIX_ROWx where x = 0:7
        2- LEDMATRIX_COLx where x = 0:7
    output: void
*/
extern void LEDMATRIX_voidDisableColor(u8 Copy_u8ColorNum)
{
  #if LEDMATRIX_MODE == COMMON_ANODE
    DIO_voidSetPinValue(LEDMATRIX_u8ColorRedPins[Copy_u8ColorNum],1);
    DIO_voidSetPinValue(LEDMATRIX_u8ColorYellowPins[Copy_u8ColorNum],1);

  #else
    DIO_voidSetPinValue(LEDMATRIX_u8ColorRedPins[Copy_u8ColorNum],0);
    DIO_voidSetPinValue(LEDMATRIX_u8ColorYellowPins[Copy_u8ColorNum],0);
  #endif
}