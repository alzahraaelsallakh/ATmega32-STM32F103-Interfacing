/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */ 
/* Layer: MCAL                                */  
/* Component: EXTI                            */                
/* File Name: EXTI_config.h                   */ 
/**********************************************/

/* Preprocessor File Guard */
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*
 * Options:   1- ENABLED
 *            2- DISABLED 
 * */
#define EXTI_u8_INT0_CONTROL          ENABLED

/*
 * Options:   1- ENABLED
 *            2- DISABLED 
 * */
#define EXTI_u8_INT1_CONTROL          ENABLED

/*
 * Options:   1- ENABLED
 *            2- DISABLED 
 * */
#define EXTI_u8_INT2_CONTROL          ENABLED


/*
 * Options:   1- LOW_LEVEL
 *            2- ON_CHANGE
 *            3- FALLING_EDGE
 *            4- RISING_EDGE 
 * */
#define EXTI_u8_INT0_SENSE            FALLING_EDGE

/*
 * Options:   1- LOW_LEVEL
 *            2- ON_CHANGE
 *            3- FALLING_EDGE
 *            4- RISING_EDGE 
 * */
#define EXTI_u8_INT1_SENSE            FALLING_EDGE

/*
 * Options:   1- FALLING_EDGE
 *            2- RISING_EDGE
 * */
#define EXTI_u8_INT2_SENSE            FALLING_EDGE


#endif 