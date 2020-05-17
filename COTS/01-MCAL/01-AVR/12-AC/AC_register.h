/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 17 May 2020                            */
/* Layer: MCAL                                  */
/* Component: AC                                */
/* File Name: AC_register.h                     */
/************************************************/

#ifndef AC_REGISTER_H
#define AC_REGISTER_H

#define SFIOR		*((volatile u8*)0x50)

#define ACSR		*((volatile u8*)0x28)

#define ADMUX		*((volatile u8*)0x27)

#endif
