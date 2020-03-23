/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 22 Dec 2019                          */
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
  switch (Copy_u8Port)
  {
    case 'A':
      /* CRL */
      if (Copy_u8Pin <= 7)
      {
        /* Clear 4 bits */
        PORTA_CRL &= ~(0b1111 << (Copy_u8Pin *4));
        /* Set Copy_u8Mode in 4 bits */
        PORTA_CRL |=  (Copy_u8Mode   << (Copy_u8Pin * 4));
      }  
      /* CRH */
      else if (Copy_u8Pin <= 15)
      {
        /* Copy_u8Pin 8 is corresponding to pin 0 */
        Copy_u8Pin = Copy_u8Pin - 8;
        /* Clear 4 bits */
        PORTA_CRH &= ~(0b1111 << (Copy_u8Pin *4));
        /* Set Copy_u8Mode in 4 bits */
        PORTA_CRH |=  (Copy_u8Mode   << (Copy_u8Pin * 4));
      }
      break;
      
    case 'B':
      /* CRL */
      if (Copy_u8Pin <= 7)
      {
        /* Clear 4 bits */
        PORTB_CRL &= ~(0b1111 << (Copy_u8Pin *4));
        /* Set Copy_u8Mode in 4 bits */
        PORTB_CRL |=  (Copy_u8Mode   << (Copy_u8Pin * 4));
      }  
      /* CRH */
      else if (Copy_u8Pin <= 15)
      {
        /* Copy_u8Pin 8 is corresponding to pin 0 */
        Copy_u8Pin = Copy_u8Pin - 8;
        /* Clear 4 bits */
        PORTB_CRH &= ~(0b1111 << (Copy_u8Pin *4));
        /* Set Copy_u8Mode in 4 bits */
        PORTB_CRH |=  (Copy_u8Mode   << (Copy_u8Pin * 4));
      }
      break;
      
    case 'C':

      if ((Copy_u8Pin >= 13) && (Copy_u8Pin <= 15))
      {
        /* Copy_u8Pin 8 is corresponding to pin 0 */
        Copy_u8Pin = Copy_u8Pin - 8;
        /* Clear 4 bits */
        PORTC_CRH &= ~(0b1111 << (Copy_u8Pin *4));
        /* Set Copy_u8Mode in 4 bits */
        PORTC_CRH |=  (Copy_u8Mode   << (Copy_u8Pin * 4));
      }
  }
}

extern void DIO_voidSetPinValue(u8 Copy_u8Value)
{
  
  u8 Local_u8ReqPort = Copy_u8Pin/16;
  u8 Local_u8ReqPin = Copy_u8Pin/=%16;
  
  switch (Local_u8ReqPort)
  {
    case 0: ASSIGN_BIT(PORTA_ODR,Local_u8ReqPin,Copy_u8Value); break;
    case 1: ASSIGN_BIT(PORTB_ODR,Local_u8ReqPin,Copy_u8Value); break;
    case 2:
      Local_u8ReqPin += 13;
      ASSIGN_BIT(PORTC_ODR,Local_u8ReqPin,Copy_u8Value); break;  
  }
  

}

extern u8 DIO_u8GetPinValue(u8 Copy_u8Pin)
{
  
  u8 Local_u8ReqPort = Copy_u8Pin/16;
  u8 Local_u8ReqPin = Copy_u8Pin/=%16;
  
  u8 Local_u8Result;
  
  switch (Local_u8ReqPort)
  {
    case 0: Local_u8Result = GET_BIT(PORTA_IDR,Local_u8ReqPin); break;
    case 1: Local_u8Result = GET_BIT(PORTB_IDR,Local_u8ReqPin); break;
    case 2:
      Local_u8ReqPin += 13;
      Local_u8Result = GET_BIT(PORTC_IDR,Local_u8ReqPin); break;  
  }
  
  
  return Local_u8Result;
}