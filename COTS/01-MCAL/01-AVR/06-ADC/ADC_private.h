/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_private.h                     */
/************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX_CHANNEL_CLEAR 0xE0

/* Max number of allowed channels */
#define MAX_NUMBER_OF_CHANNELS 31

/* Macros for ADMUX register bits */
#define ADMUX_REFS1_BIT       7
#define ADMUX_REFS0_BIT       6
#define ADMUX_ADLAR_BIT       5
#define ADMUX_MUX4_BIT        4
#define ADMUX_MUX3_BIT        3
#define ADMUX_MUX2_BIT        2
#define ADMUX_MUX1_BIT        1
#define ADMUX_MUX0_BIT        0

/* Macros for ADCSRA bits */
#define ADCSRA_ADEN_BIT       7
#define ADCSRA_ADSC_BIT       6
#define ADCSRA_ADATE_BIT      5
#define ADCSRA_ADIF_BIT       4
#define ADCSRA_ADIE_BIT       3
#define ADCSRA_ADPS2_BIT      2
#define ADCSRA_ADPS1_BIT      1
#define ADCSRA_ADPS0_BIT      0

/* Macros for resolution */
#define ADC_u8_8BITS_RESOLUTION   1
#define ADC_u8_10BITS_RESOLUTION  2

/* Macros for ADC complete conversion state */
#define ADC_u8_STATE_IDLE   1
#define ADC_u8_STATE_BUSY   2

/* Macros for ISR state */
#define ADC_u8_SINGLE_CONVERSION  1
#define ADC_u8_CHAIN_CONVERSION   2

#endif
