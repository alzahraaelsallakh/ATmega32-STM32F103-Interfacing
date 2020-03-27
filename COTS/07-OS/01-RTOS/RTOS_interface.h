/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 11 Feb 2020                          */
/* Layer: OS                                  */
/* Component: RTOS                            */
/* File Name: RTOS_config.h                   */
/**********************************************/


#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

#define RTOS_u8RUNNING 1U
#define RTOS_u8SUSPEND 2U

extern void RTOS_voidInit (void);
extern void RTOS_voidStartOS(void);
extern void RTOS_voidCreateTask(u32 Copy_u32Priority,f32 Copy_u32Periodicity,void(*Copy_HandlerPtr)(void), u32 Copy_u32FirstDelay, u8 Copy_u8InitialState);
extern void RTOS_voidDeleteTask(u8 Copy_u8TaskID);
extern void RTOS_voidSuspendTask (u8 Copy_u8TaskID);
extern void RTOS_voidResumeTask (u8 Copy_u8TaskID);

#endif