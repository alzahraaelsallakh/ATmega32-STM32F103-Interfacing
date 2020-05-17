/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 17 May 2020                            */
/* Layer: MCAL                                  */
/* Component: AC                                */
/* File Name: AC_private.h                      */
/************************************************/

#ifndef AC_PRIVATE_H
#define AC_PRIVATE_H

/* Macros configurations */

#define AC_u8_POSITIVE_PIN_INPUT_AIN0					0
#define AC_u8_POSITIVE_PIN_INPUT_VOLTAGE_BAND_GAP		1

#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL0	 		0
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL1	 		1
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL2	 		2
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL3	 		3
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL4	 		4
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL5	 		5
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL6	 		6
#define AC_u8_NEGATIVE_PIN_INPUT_ADC_CHANNEL7	 		7
#define AC_u8_NEGATIVE_PIN_INPUT_AIN1	  				8

#define AC_u8_INTERRUPT_ENABLE							0
#define AC_u8_INTERRUPT_DISABLE							1

#define AC_u8_INTERRUPT_MODE_TOGGLE						0
#define AC_u8_INTERRUPT_MODE_FALLING					2
#define AC_u8_INTERRUPT_MODE_RISING	  					3

#define AC_u8_INPUT_CAPTURE_ENABLE	  					0
#define AC_u8_INPUT_CAPTURE_DISABLE	  					1


/* Register pins */

/* SFIOR register */
#define ACME_PIN										3

/* ACSR register */
#define ACIE_PIN										3
#define ACO_PIN											5
#define BAND_GAP_PIN									6

#endif
