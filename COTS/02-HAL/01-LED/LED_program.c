/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 10 Dec 2019                          */
/* Layer: HAL                                 */
/* Component: LED                             */
/* File Name: LED_program.c                   */
/**********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidSetLedON (void)
{
  DIO_voidSetPinValue(LED_u8_PORT,LED_u8_PIN,LED_u8_MODE);
}
void LED_voidSetLedOff (void)
{
  /* Toggle Bit */
  DIO_voidSetPinValue(LED_u8_PORT,LED_u8_PIN, LED_u8_MODE ^ 0x01);
}