/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Dec 2019                           */
/* Layer: MCAL                                */
/* Component: DIO                             */
/* File Name: DIO_interface.h                 */
/**********************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


extern void DIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
extern void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
extern u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif