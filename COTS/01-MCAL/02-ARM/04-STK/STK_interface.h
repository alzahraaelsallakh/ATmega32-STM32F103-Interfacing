/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: STK                             */
/* File Name: STK_interface.h                 */
/**********************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_voidInitialize (void);
void STK_voidStart (u32 Copy_u32Value);
void STK_voidSetCallBack(void(*Copy_Ptr)(void));

#endif