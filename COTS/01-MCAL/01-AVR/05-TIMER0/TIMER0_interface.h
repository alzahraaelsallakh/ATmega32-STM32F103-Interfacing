/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: TIMER0                            */
/* File Name: TIMER0_interface.h                */
/************************************************/

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H


/* Clock Select modes */
#define TIMER0_CLOCK_SELECT_NO_SOURCE         0x00
#define TIMER0_CLOCK_SELECT_NO_PRESCALING     0x01
#define TIMER0_CLOCK_SELECT_8_PRESCALING      0x02
#define TIMER0_CLOCK_SELECT_64_PRESCALING     0x03
#define TIMER0_CLOCK_SELECT_256_PRESCALING    0x04
#define TIMER0_CLOCK_SELECT_1024_PRESCALING   0x05
#define TIMER0_CLOCK_SELECT_EXTERNAL_FALLING  0x06
#define TIMER0_CLOCK_SELECT_EXTERNAL_RISING   0x07

/*
    Description: This function shall initiate Timer driver
    Input: void
    output: void
*/
void TIMER0_voidInit(void);

/*
    Description: This function shall set call back function that is called when timer interrupt is raised
    Input: Copy_ptrCallBack is a pointer that contains the callback function, the function arguments and return are void type
    output: void
*/
void TIMER0_voidSetCallback(void(*Copy_ptrCallBack)(void));

#endif
