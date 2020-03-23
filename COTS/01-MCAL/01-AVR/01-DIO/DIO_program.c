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

extern void DIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
  
  switch (Copy_u8Port)
  {
    case 'A':
              if (Copy_u8Mode == 0)
              {
                //DDRA = DDRA & ~ (1 <<Copy_u8Pin);
                CLR_BIT(DDRA,Copy_u8Pin);
              }
              else
              {
                //DDRA = DDRA | (1 <<Copy_u8Pin);
                SET_BIT(DDRA,Copy_u8Pin);
              }
              break;
              
    case 'B':
              if (Copy_u8Mode == 0)
              {
                //DDRB = DDRB & ~ (1 <<Copy_u8Pin);
                CLR_BIT(DDRB,Copy_u8Pin);
              }
              else
              {
                //DDRB = DDRB | (1 <<Copy_u8Pin);
                SET_BIT(DDRB,Copy_u8Pin);
              }
              break;  
    case 'C':
              if (Copy_u8Mode == 0)
              {
                //DDRC = DDRC & ~ (1 <<Copy_u8Pin);
                CLR_BIT(DDRC,Copy_u8Pin);
              }
              else
              {
                //DDRC = DDRC | (1 <<Copy_u8Pin);
                SET_BIT(DDRC,Copy_u8Pin);
              }
              break;
    case 'D':
              if (Copy_u8Mode == 0)
              {
                //DDRD = DDRD & ~ (1 <<Copy_u8Pin);
                CLR_BIT(DDRD,Copy_u8Pin);
              }
              else
              {
                //DDRD = DDRD | (1 <<Copy_u8Pin);
                SET_BIT(DDRD,Copy_u8Pin);
              }
  }
}


extern void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
  switch (Copy_u8Port)
  {
    case 'A':
              if (Copy_u8Value == 0)
              {
                CLR_BIT(PORTA,Copy_u8Pin);
              }
              else
              {
                SET_BIT(PORTA,Copy_u8Pin);
              }
              break;
              
    case 'B':
              if (Copy_u8Value == 0)
              {
                CLR_BIT(PORTB,Copy_u8Pin);
              }
              else
              {
                SET_BIT(PORTB,Copy_u8Pin);
              }
              break;  
    case 'C':
              if (Copy_u8Value == 0)
              {
                CLR_BIT(PORTC,Copy_u8Pin);
              }
              else
              {
                SET_BIT(PORTC,Copy_u8Pin);
              }
              break;
    case 'D':
              if (Copy_u8Value == 0)
              {
                CLR_BIT(PORTD,Copy_u8Pin);
              }
              else
              {
                SET_BIT(PORTD,Copy_u8Pin);
              }
  }
  
}



extern u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
  u8 Local_u8Result;
  switch (Copy_u8Port)
  {
    case 'A':
              Local_u8Result = GET_BIT(PINA,Copy_u8Pin);
              break;
              
    case 'B':
              Local_u8Result = GET_BIT(PINB,Copy_u8Pin);
              break;  
    case 'C':
              Local_u8Result = GET_BIT(PINC,Copy_u8Pin);
              break;
    case 'D':
              Local_u8Result = GET_BIT(PIND,Copy_u8Pin);
  }
  return Local_u8Result;
}