/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 11 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: PORT                            */
/* File Name: PORT_program.c                  */
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"

extern void PORT_voidPortInitialize(void)
{
  
  DDRA = PORT_u8_PORTA_DIR;
  DDRB = PORT_u8_PORTB_DIR;
  DDRC = PORT_u8_PORTC_DIR;
  DDRD = PORT_u8_PORTD_DIR;
  
  PORTA = PORT_u8_PORTA_INITIALVALUE;
  PORTB = PORT_u8_PORTB_INITIALVALUE;
  PORTC = PORT_u8_PORTC_INITIALVALUE;
  PORTD = PORT_u8_PORTD_INITIALVALUE;
}