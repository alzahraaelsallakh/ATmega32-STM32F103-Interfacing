/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 22 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: DIO                             */
/* File Name: DIO_interface.h                 */
/**********************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_u8_PIN0   0 
#define DIO_u8_PIN1   1 
#define DIO_u8_PIN2   2 
#define DIO_u8_PIN3   3 
#define DIO_u8_PIN4   4 
#define DIO_u8_PIN5   5 
#define DIO_u8_PIN6   6 
#define DIO_u8_PIN7   7 
#define DIO_u8_PIN8   8 
#define DIO_u8_PIN9   9 
#define DIO_u8_PIN10  10
#define DIO_u8_PIN11  11
#define DIO_u8_PIN12  12
#define DIO_u8_PIN13  13
#define DIO_u8_PIN14  14
#define DIO_u8_PIN15  15
#define DIO_u8_PIN16  16
#define DIO_u8_PIN17  17
#define DIO_u8_PIN18  18
#define DIO_u8_PIN19  19
#define DIO_u8_PIN20  20
#define DIO_u8_PIN21  21
#define DIO_u8_PIN22  22
#define DIO_u8_PIN23  23
#define DIO_u8_PIN24  24
#define DIO_u8_PIN25  25
#define DIO_u8_PIN26  26
#define DIO_u8_PIN27  27
#define DIO_u8_PIN28  28
#define DIO_u8_PIN29  29
#define DIO_u8_PIN30  30
#define DIO_u8_PIN31  31
#define DIO_u8_PIN32  32
#define DIO_u8_PIN33  33
#define DIO_u8_PIN34  34

extern void DIO_voidSetPinMode(u8 Copy_u8Pin, u8 Copy_u8Mode);
extern void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value);
extern u8 DIO_u8GetPinValue( u8 Copy_u8Pin);

#endif