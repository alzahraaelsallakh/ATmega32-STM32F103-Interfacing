/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 17 May 2020                            */
/* Layer: MCAL                                  */
/* Component: AC                                */
/* File Name: AC_config.h                       */
/************************************************/

#ifndef AC_CONFIG_H
#define AC_CONFIG_H


/*
 * Options:
 *		1- AC_u8_POSITIVE_PIN_INPUT_AIN0
 *		2- AC_u8_POSITIVE_PIN_INPUT_VOLTAGE_BAND_GAP
 * */
#define AC_u8_POSITIVE_PIN_INPUT_STATE							AC_u8_POSITIVE_PIN_INPUT_VOLTAGE_BAND_GAP

#define AC_u8_NEGATIVE_PIN_INPUT_STATE							AC_u8_NEGATIVE_PIN_INPUT_AIN1

#define AC_u8_ANALOG_COMPARATOR_INTERRUPT_INIT					AC_u8_INTERRUPT_DISABLE

#define AC_u8_ANALOG_COMPARATOR_INTERRUPT_TRIGGER_SRC_INIT		AC_u8_INTERRUPT_MODE_TOGGLE

#define AC_u8_ANALOG_COMPARATOR_IC_INIT_MODE

#endif
