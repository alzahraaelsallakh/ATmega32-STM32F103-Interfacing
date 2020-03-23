/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 10 Dec 2019                          */
/* Layer: HAL                                 */
/* Component: SWITCH                          */
/* File Name: SWITCH_program.c                */
/**********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"

u8 Switch_u8GetSwitchState(void)
{
  u8 Local_u8State;
  Local_u8State = DIO_u8GetPinValue(SWITCH_u8_PORT,SWITCH_u8_PIN);
  
  #if SWITCH_u8_RELEASE_STATE == 1
      TOGGLE_BIT(Local_u8State,0);
  #endif 
    
  return Local_u8State;
    
}