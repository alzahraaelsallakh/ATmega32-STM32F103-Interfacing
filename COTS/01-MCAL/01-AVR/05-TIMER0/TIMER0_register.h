/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: TIMER0                            */
/* File Name: TIMER0_register.h                 */
/************************************************/

#ifndef TIMER0_REGISTER_H
#define TIMER0_REGISTER_H

#define TCCR0 	*((volatile u8*) 0x53)
#define TCNT0 	*((volatile u8*) 0x52)
#define TIMSK 	*((volatile u8*) 0x59)
#define TIFR 		*((volatile u8*) 0x58)



#endif
