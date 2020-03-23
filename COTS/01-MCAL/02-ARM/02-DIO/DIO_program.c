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


extern void DIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
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

extern void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
  switch (Copy_u8Port)
  {
    case 'A': 
      if (Copy_u8Value == 1)
          SET_BIT(PORTA_ODR,Copy_u8Pin);
      else
        CLR_BIT(PORTA_ODR,Copy_u8Pin);
      break;
      
    case 'B': 
      if (Copy_u8Value == 1)
          SET_BIT(PORTB_ODR,Copy_u8Pin);
      else
        CLR_BIT(PORTB_ODR,Copy_u8Pin);
      break;
      
    case 'C': 
      if (Copy_u8Value == 1)
          SET_BIT(PORTC_ODR,Copy_u8Pin);
      else
        CLR_BIT(PORTC_ODR,Copy_u8Pin);
    
  }
}

extern u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
  u8 Local_u8Result;
  switch (Copy_u8Port)
  {
    case 'A':
      Local_u8Result = GET_BIT(PORTA_IDR,Copy_u8Pin);
      break;
    case 'B':
      Local_u8Result = GET_BIT(PORTB_IDR,Copy_u8Pin);
      break;
    case 'C':
      Local_u8Result = GET_BIT(PORTC_IDR,Copy_u8Pin);
  }
  
  return Local_u8Result;
}