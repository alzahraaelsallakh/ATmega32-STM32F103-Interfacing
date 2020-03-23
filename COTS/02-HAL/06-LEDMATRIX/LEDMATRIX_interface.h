/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 21 Feb 2020                            */
/* Layer: HAL                                   */
/* Component: LEDMATRIX                         */
/* File Name: LEDMATRIX_interface.h             */
/************************************************/

#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H

#define COMMON_CATHODE  1
#define COMMON_ANODE    2

#define COMMON_ROW      1
#define COMMON_COLUMN   2

#define LEDMATRIX_ROW0  0 
#define LEDMATRIX_ROW1  1
#define LEDMATRIX_ROW2  2
#define LEDMATRIX_ROW3  3
#define LEDMATRIX_ROW4  4
#define LEDMATRIX_ROW5  5 
#define LEDMATRIX_ROW6  6
#define LEDMATRIX_ROW7  7

#define LEDMATRIX_COL0  0 
#define LEDMATRIX_COL1  1
#define LEDMATRIX_COL2  2
#define LEDMATRIX_COL3  3
#define LEDMATRIX_COL4  4
#define LEDMATRIX_COL5  5 
#define LEDMATRIX_COL6  6
#define LEDMATRIX_COL7  7

#define YELLOW          1
#define RED             2


/*
    Description: This function shall initiate LEDMATRIX, by turning off all leds
    Input: void
    output: void
*/
extern void LEDMATRIX_voidInit ();

/*
    Description: This function shall enable specific common to be ready to turn leds on it
    Input: Copy_u8CommonNum which represents common number, its options are:
        1- LEDMATRIX_ROWx where x = 0:7
        2- LEDMATRIX_COLx where x = 0:7

    output: void
*/
extern void LEDMATRIX_voidEnableCommon(u8 Copy_u8CommonNum);

/*
    Description: This function shall enable specific color row/column to be ready to turn leds on it
    Input: 
          1) Copy_u8ColorNum which represents color row/column number, its options are:
            1- LEDMATRIX_ROWx where x = 0:7
            2- LEDMATRIX_COLx where x = 0:7
          2) Copy_u8Color which represents required color of led, its options are:
            1- YELLOW
            2- RED
    output: void
*/
extern void LEDMATRIX_voidEnableColor(u8 Copy_u8ColorNum,u8 Copy_u8Color);

/*
    Description: This function shall disable specific color row/column 
    Input: Copy_u8ColorNum which represents color row/column number, its options are:
        1- LEDMATRIX_ROWx where x = 0:7
        2- LEDMATRIX_COLx where x = 0:7
    output: void
*/
extern void LEDMATRIX_voidDisableColor(u8 Copy_u8ColorNum);

#endif
