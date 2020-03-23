/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 12 Dec 2019                          */
/* Layer: HAL                                 */
/* Component: SEVENSEG                        */
/* File Name: SEVENSEG_config.h               */
/**********************************************/

#ifndef SEVENSEG_CONFIG_H
#define SEVENSEG_CONFIG_H

/* Choose Common Anode SEVENSEG_u8_MODE = 0, Common Cathode SEVENSEG_u8_MODE = 1 */
#define SEVENSEG_u8_MODE 0
   
/* Config of Enable Pins */
#define SEVENSEG_u8_SEGMENTONE_ENABLE_PIN 0
#define SEVENSEG_u8_SEGMENTTWO_ENABLE_PIN 1

/* Config of Enable Ports */
#define SEVENSEG_u8_SEGMENTONE_ENABLE_PORT 'C'
#define SEVENSEG_u8_SEGMENTTWO_ENABLE_PORT 'C'

/* Config for SEVENSEG Pins*/

#define SEVENSEG_u8_PIN_A_NUMBER 1 
#define SEVENSEG_u8_PORT_A 'A'

#define SEVENSEG_u8_PIN_B_NUMBER 0
#define SEVENSEG_u8_PORT_B 'A'

#define SEVENSEG_u8_PIN_C_NUMBER 5
#define SEVENSEG_u8_PORT_C 'A'

#define SEVENSEG_u8_PIN_D_NUMBER 6
#define SEVENSEG_u8_PORT_D 'A'

#define SEVENSEG_u8_PIN_E_NUMBER 7
#define SEVENSEG_u8_PORT_E 'A'

#define SEVENSEG_u8_PIN_F_NUMBER 2
#define SEVENSEG_u8_PORT_F 'A'

#define SEVENSEG_u8_PIN_G_NUMBER 3
#define SEVENSEG_u8_PORT_G 'A'

#define SEVENSEG_u8_PIN_H_NUMBER 4
#define SEVENSEG_u8_PORT_H 'A'

/* SEVENSEG Initial Value */
#define SEVENSEG_u8_INITIAL_VALUE 0


#endif