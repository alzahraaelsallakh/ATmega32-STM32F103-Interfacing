/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 2 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: NVIC                            */
/* File Name: NVIC_interface.h                */
/**********************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void NVIC_voidInitPriority(void);
void NVIC_voidSetPriority (u8 Copy_u8Idx, u8 Copy_u8Priority);
void NVIC_voidEnableExternalInterrupt (u8 Copy_u8Idx);
void NVIC_voidDisableExternalInterrupt (u8 Copy_u8Idx);

void NVIC_voidSetPendingFlag (u8 Copy_u8Idx);
void NVIC_voidClearPendingFlag (u8 Copy_u8Idx);

u8 NVIC_u8GetActiveFlag (u8 Copy_u8Idx);

#endif