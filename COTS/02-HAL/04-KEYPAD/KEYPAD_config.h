/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 19 Dec 2019                          */
/* Layer: HAL                                 */
/* Component: KEYPAD                          */
/* File Name: KEYPAD_config.h                 */
/**********************************************/

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/* KEYPAD NUMBER OF ROWS AND COLUMNS CONFIG*/

#define KEYPAD_u8_ROWSNUM 4
#define KEYPAD_u8_COLSNUM 4

/* KEYPAD ROWS PINS CONFIG */

#define KEYPAD_u8_R0_PORT 'A'
#define KEYPAD_u8_R0_PIN 0

#define KEYPAD_u8_R1_PORT 'A'
#define KEYPAD_u8_R1_PIN 1

#define KEYPAD_u8_R2_PORT 'A'
#define KEYPAD_u8_R2_PIN 2

#define KEYPAD_u8_R3_PORT 'A'
#define KEYPAD_u8_R3_PIN 3

/* KEYPAD COLUMNS PINS CONFIG */

#define KEYPAD_u8_C0_PORT 'A'
#define KEYPAD_u8_C0_PIN 4

#define KEYPAD_u8_C1_PORT 'A'
#define KEYPAD_u8_C1_PIN 5

#define KEYPAD_u8_C2_PORT 'A'
#define KEYPAD_u8_C2_PIN 6

#define KEYPAD_u8_C3_PORT 'A'
#define KEYPAD_u8_C3_PIN 7

/* KEYPAD COLUMNS AND ROWS PORTS AND PINS */
#define KEYPAD_u8_ROWS_PORTS  {KEYPAD_u8_R0_PORT,KEYPAD_u8_R1_PORT,KEYPAD_u8_R2_PORT,KEYPAD_u8_R3_PORT}
#define KEYPAD_u8_COLS_PORTS  {KEYPAD_u8_C0_PORT,KEYPAD_u8_C1_PORT,KEYPAD_u8_C2_PORT,KEYPAD_u8_C3_PORT}
#define KEYPAD_u8_ROWS_PINS   {KEYPAD_u8_R0_PIN,KEYPAD_u8_R1_PIN,KEYPAD_u8_R2_PIN,KEYPAD_u8_R3_PIN}
#define KEYPAD_u8_COLS_PINS   {KEYPAD_u8_C0_PIN,KEYPAD_u8_C1_PIN,KEYPAD_u8_C2_PIN,KEYPAD_u8_C3_PIN}

/* KEYPAD KEYS VALUES */
#define KEYPAD_u8_KEYS        {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KEYPAD_u8_NOKEYPRESSED 0xFF

#endif
