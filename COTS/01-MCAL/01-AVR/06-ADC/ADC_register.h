/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: ADC                               */
/* File Name: ADC_register.h                    */
/************************************************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define ADMUX   *((volatile u8*) 0x27)
#define ADCSRA  *((volatile u8*) 0x26)
#define ADCH    *((volatile u8*) 0x25)
#define ADCL    *((volatile u8*) 0x24)
#define ADC     *((volatile u16*) 0x24)

#endif
