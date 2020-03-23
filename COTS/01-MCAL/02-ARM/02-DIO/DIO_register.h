/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 22 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: DIO                             */
/* File Name: DIO_register.h                 */
/**********************************************/


#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H


/* PORT A */
#define PORTA_BASE_ADDRESS 0x40010800

#define PORTA_CRL    *((u32*)(PORTA_BASE_ADDRESS + 0x00))
#define PORTA_CRH    *((u32*)(PORTA_BASE_ADDRESS + 0x04))
#define PORTA_IDR    *((u32*)(PORTA_BASE_ADDRESS + 0x08))
#define PORTA_ODR    *((u32*)(PORTA_BASE_ADDRESS + 0x0C))
#define PORTA_BSRR   *((u32*)(PORTA_BASE_ADDRESS + 0x10))
#define PORTA_BRR    *((u32*)(PORTA_BASE_ADDRESS + 0x14))
#define PORTA_LCKR   *((u32*)(PORTA_BASE_ADDRESS + 0x18))

/* PORT B */
#define PORTB_BASE_ADDRESS 0x40010C00

#define PORTB_CRL    *((u32*)(PORTB_BASE_ADDRESS + 0x00))
#define PORTB_CRH    *((u32*)(PORTB_BASE_ADDRESS + 0x04))
#define PORTB_IDR    *((u32*)(PORTB_BASE_ADDRESS + 0x08))
#define PORTB_ODR    *((u32*)(PORTB_BASE_ADDRESS + 0x0C))
#define PORTB_BSRR   *((u32*)(PORTB_BASE_ADDRESS + 0x10))
#define PORTB_BRR    *((u32*)(PORTB_BASE_ADDRESS + 0x14))
#define PORTB_LCKR   *((u32*)(PORTB_BASE_ADDRESS + 0x18))

/* PORT C */
#define PORTC_BASE_ADDRESS 0x40011000

#define PORTC_CRL    *((u32*)(PORTC_BASE_ADDRESS + 0x00))
#define PORTC_CRH    *((u32*)(PORTC_BASE_ADDRESS + 0x04))
#define PORTC_IDR    *((u32*)(PORTC_BASE_ADDRESS + 0x08))
#define PORTC_ODR    *((u32*)(PORTC_BASE_ADDRESS + 0x0C))
#define PORTC_BSRR   *((u32*)(PORTC_BASE_ADDRESS + 0x10))
#define PORTC_BRR    *((u32*)(PORTC_BASE_ADDRESS + 0x14))
#define PORTC_LCKR   *((u32*)(PORTC_BASE_ADDRESS + 0x18))

#endif