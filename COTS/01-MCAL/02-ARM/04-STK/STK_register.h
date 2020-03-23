/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: STK                             */
/* File Name: STK_register.h                  */
/**********************************************/


#ifndef STK_REGISTER_H
#define STK_REGISTER_H


#define STK_CTRL    * ( (volatile u32*) 0xE000E010)
#define STK_LOAD    * ( (volatile u32*) 0xE000E014)
#define STK_VAL     * ( (volatile u32*) 0xE000E018)

#endif