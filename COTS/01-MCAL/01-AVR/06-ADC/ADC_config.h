/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_config.h                      */
/************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* 
    Configuration for Vref 
    1- ADC_u8_AVCC_Vref
    2- ADC_u8_AREF_Vref
    3- ADC_u8_INTERNAL_Vref
*/
#define ADC_u8_VREF ADC_u8_AVCC_Vref

/*
    Configuration for prescaler
    1-
*/


/*
    Configuration for resolution
    1- ADC_u8_8BITS_RESOLUTION
    2- ADC_u8_10BITS_RESOLUTION
*/
#define ADC_u8_RESOLUTION ADC_u8_8BITS_RESOLUTION

/* Configuration of timeout for ADC conversion synchronous function */
#define ADC_u32TIME_OUT_COUNT       (u32) 40000

#endif
