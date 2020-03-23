/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Dec 2019                           */
/* Layer: MCAL                                */
/* Component: DIO                             */
/* File Name: DIO_program.c                   */
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"

extern void DIO_voidSetPinMode(u8 Copy_u8Pin, u8 Copy_u8Mode)
{
    u8 Local_u8ReqPort = Copy_u8Pin/8;
    u8 Local_u8ReqPin = Copy_u8Pin%8;
    
    switch (Local_u8ReqPort)
    {
      case 0: ASSIGN_BIT(DDRA,Local_u8ReqPin,Copy_u8Mode); break;
      case 1: ASSIGN_BIT(DDRB,Local_u8ReqPin,Copy_u8Mode); break;
      case 2: ASSIGN_BIT(DDRC,Local_u8ReqPin,Copy_u8Mode); break;
      case 3: ASSIGN_BIT(DDRD,Local_u8ReqPin,Copy_u8Mode); break;
    }
}


extern void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value)
{
    u8 Local_u8ReqPort = Copy_u8Pin/8;
    u8 Local_u8ReqPin = Copy_u8Pin%8;
    
    switch (Local_u8ReqPort)
    {
      case 0: ASSIGN_BIT(PORTA,Local_u8ReqPin,Copy_u8Value); break;
      case 1: ASSIGN_BIT(PORTB,Local_u8ReqPin,Copy_u8Value); break;
      case 2: ASSIGN_BIT(PORTC,Local_u8ReqPin,Copy_u8Value); break;
      case 3: ASSIGN_BIT(PORTD,Local_u8ReqPin,Copy_u8Value); break;
    }
}



extern u8 DIO_u8GetPinValue(u8 Copy_u8Pin)
{
  
    u8 Local_u8ReqPort = Copy_u8Pin/8;
    u8 Local_u8ReqPin = Copy_u8Pin%8;
    
    u8 Local_u8Result;
    
    switch (Local_u8ReqPort)
    {
      case 0: Local_u8Result = GET_BIT(PINA,Local_u8ReqPin); break;
      case 1: Local_u8Result = GET_BIT(PINB,Local_u8ReqPin); break;
      case 2: Local_u8Result = GET_BIT(PINC,Local_u8ReqPin); break;
      case 3: Local_u8Result = GET_BIT(PIND,Local_u8ReqPin); break;
    }

  return Local_u8Result;
}