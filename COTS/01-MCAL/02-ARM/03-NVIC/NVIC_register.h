/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 2 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: NVIC                            */
/* File Name: NVIC_register.h                 */
/**********************************************/

#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

/* There is only 60 External interrupts defined for ARM, no need for more than 2 registers */

/* Set Enable Register */
#define NVIC_ISER0    *((volatile u32*) 0xE000E100)
#define NVIC_ISER1    *((volatile u32*) 0xE000E104)

/* Clear Enable Register */
#define NVIC_ICER0    *((volatile u32*) 0xE000E180)
#define NVIC_ICER1    *((volatile u32*) 0xE000E184)

/* Set Pending Flag */
#define NVIC_ISPR0    *((volatile u32*) 0xE000E200)
#define NVIC_ISPR1    *((volatile u32*) 0xE000E204)

/* Clear Pending Flag */
#define NVIC_ICPR0    *((volatile u32*) 0xE000E280)
#define NVIC_ICPR1    *((volatile u32*) 0xE000E100)

/* Get Active Flag */
#define NVIC_IABR0    *((volatile u32*) 0xE000E300)
#define NVIC_IABR1    *((volatile u32*) 0xE000E304)

/* Set Priority */
/* As pointer to u8 starting from this address */
#define NVIC_IPR      ((volatile u8*) 0xE000E400)

#endif