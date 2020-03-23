/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 19 Dec 2019                          */
/* Layer: HAL                                 */
/* Component: KEYPAD                          */
/* File Name: KEYPAD_program.c                */
/**********************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"


extern u8 KEYPAD_u8GetPressedKey(void)
{
  u8 Local_u8PressedKey = KEYPAD_u8_NOKEYPRESSED;
  
  static u8 Local_u8RowsPorts [KEYPAD_u8_ROWSNUM] = KEYPAD_u8_ROWS_PORTS;
  static u8 Local_u8ColsPorts [KEYPAD_u8_COLSNUM] = KEYPAD_u8_COLS_PORTS;
  
  static u8 Local_u8RowsPins [KEYPAD_u8_ROWSNUM] =  KEYPAD_u8_ROWS_PINS;
  static u8 Local_u8ColsPins [KEYPAD_u8_COLSNUM] =  KEYPAD_u8_COLS_PINS;
  
  static u8 Local_u8KEYSArray [KEYPAD_u8_ROWSNUM] [KEYPAD_u8_COLSNUM] = KEYPAD_u8_KEYS;
  
  u8 Local_u8RowsCounter;
  u8 Local_u8ColsCounter;
  
  for (Local_u8RowsCounter = 0; Local_u8RowsCounter < KEYPAD_u8_ROWSNUM ; Local_u8RowsCounter++)
  {
    /* Set row value to 0 */
    DIO_voidSetPinValue(Local_u8RowsPorts[Local_u8RowsCounter],Local_u8RowsPins[Local_u8RowsCounter],0);
    
    /* Check each column value */
    for (Local_u8ColsCounter = 0; Local_u8ColsCounter < KEYPAD_u8_COLSNUM ; Local_u8ColsCounter++)
    {
      if (!DIO_u8GetPinValue(Local_u8ColsPorts[Local_u8ColsCounter],Local_u8ColsPins[Local_u8ColsCounter]))
      {
        Local_u8PressedKey = Local_u8KEYSArray[Local_u8RowsCounter][Local_u8ColsCounter];
      }
      while(!DIO_u8GetPinValue(Local_u8ColsPorts[Local_u8ColsCounter],Local_u8ColsPins[Local_u8ColsCounter]));
    }
    /* set row value to 1 */
    DIO_voidSetPinValue(Local_u8RowsPorts[Local_u8RowsCounter],Local_u8RowsPins[Local_u8RowsCounter],1);
  }
  
  return Local_u8PressedKey;
}