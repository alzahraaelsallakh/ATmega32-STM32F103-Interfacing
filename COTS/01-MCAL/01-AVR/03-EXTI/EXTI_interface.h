/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: EXTI                            */
/* File Name: EXTI_interface.h                */
/**********************************************/

/* Preporcessor File Guard */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define EXTI_u8_INT0  0
#define EXTI_u8_INT1  1
#define EXTI_u8_INT2  2

#define EXTI_u8_LOW_LEVEL     0
#define EXTI_u8_ON_CHANGE     1
#define EXTI_u8_FALLING_EDGE  2
#define EXTI_u8_RISING_EDGE   3


/*
 * Description: A function to initailize external interrupts int0, int1 and int2
 *              according to the precompiled configurations
 * Input: void
 * Output: void
 */
extern void EXTI_voidInit(void);


/*
 * Description: A function to set enable of external interrupts int0,int1 and int2
 * Input: Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorIntEnable(u8 Copy_u8Idx);

/*
 * Description: A function to set disable of external interrupts int0,int1 and int2
 * Input: Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorIntDisable(u8 Copy_u8Idx);

/*
 * Description: A function to set the required sense level of external interrupts int0,int1 and int2
 * Input: 1- Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 *        2- required sense level, Ranges are:
 *                          1- EXTI_u8_LOW_LEVEL
 *                          2- EXTI_u8_ON_CHANGE
 *                          3- EXTI_u8_FALLING_EDGE
 *                          3- EXTI_u8_RISING_EDGE
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorSetSenseLevel(u8 Copy_u8Idx,u8 Copy_u8SenseLevel);

/*
 * Description: A function to set the required address of ISR application function of int0, int1 and int2
 * Input: 1- Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 *        2- Pointer to the required callback application function
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorSetCallBack(u8 Copy_u8Idx, void (*Copy_ptrCallBack)(void));

#endif