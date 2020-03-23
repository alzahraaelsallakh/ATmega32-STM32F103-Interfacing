/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 22 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: RCC                             */
/* File Name: RCC_interface.h                 */
/**********************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

extern void RCC_voidInit (void);
extern void RCC_voidEnablePeripheralClock(u8 Copy_u8Bus, u8 Copy_u8Peripheral);
extern void RCC_voidDisablePeripheralClock(u8 Copy_u8Bus, u8 Copy_u8Peripheral);

#endif