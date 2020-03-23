/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: TIMER0                            */
/* File Name: TIMER0_private.h                  */
/************************************************/

#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TIMER0_CLOCK_SELECT_CLEAR 0xF8

void __vector_11(void) __attribute__((signal));

#endif
