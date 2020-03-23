/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 14 Jan 2020                          */
/* Layer: HAL                                 */
/* Component: CLCD                            */
/* File Name: CLCD_config.h                   */
/**********************************************/

#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H


#define CLCD_u8_RS_PORT 'D'
#define CLCD_u8_RS_PIN   0

#define CLCD_u8_RW_PORT 'D'
#define CLCD_u8_RW_PIN  1

#define CLCD_u8_E_PORT  'D'
#define CLCD_u8_E_PIN    2

#define CLCD_u8_DATA_PORT 'A'

#define CLCD_u8_D0_PIN     0 
#define CLCD_u8_D1_PIN     1
#define CLCD_u8_D2_PIN     2
#define CLCD_u8_D3_PIN     3
#define CLCD_u8_D4_PIN     4
#define CLCD_u8_D5_PIN     5
#define CLCD_u8_D6_PIN     6
#define CLCD_u8_D7_PIN     7


/*
 * Options: 1- FOUR_BITS_MODE
 *          2- EIGHT_BITS_MODE
 * */
#define CLCD_u8_DATA_LENGTH FOUR_BITS_MODE

#endif