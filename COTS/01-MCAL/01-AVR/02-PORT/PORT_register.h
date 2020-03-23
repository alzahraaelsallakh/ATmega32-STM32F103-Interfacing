/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 11 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: PORT                            */
/* File Name: PORT_register.h                 */
/**********************************************/


#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

#define DDRA    *((u8*)0x3A)
#define DDRB    *((u8*)0x37)
#define DDRC    *((u8*)0x34)
#define DDRD    *((u8*)0x31)

#define PORTA * ( (u8*) 0x3B)
#define PORTB * ( (u8*) 0x38)
#define PORTC * ( (u8*) 0x35)
#define PORTD * ( (u8*) 0x32)

#endif