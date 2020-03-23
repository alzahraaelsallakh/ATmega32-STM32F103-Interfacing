/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 21 Feb 2020                            */
/* Layer: HAL                                   */
/* Component: LEDMATRIX                         */
/* File Name: LEDMATRIX_config.h                */
/************************************************/

#ifndef LEDMATRIX_CONFIG_H
#define LEDMATRIX_CONFIG_H


/*
  LEDMATRIX_MODE options are:
  1- COMMON_CATHODE
  2- COMMON_ANODE
*/
#define LEDMATRIX_MODE              COMMON_CATHODE

/*
  LEDMATRIX_COMMON options are:
  1- COMMON_ROW
  2- COMMON_COLUMN
*/
#define LEDMATRIX_COMMON            COMMON_ROW

#if LEDMATRIX_COMMON == COMMON_ROW

#define LEDMATRIX_COL0_YELLOW_PIN   0
#define LEDMATRIX_COL0_RED_PIN      16
#define LEDMATRIX_COL1_YELLOW_PIN   1
#define LEDMATRIX_COL1_RED_PIN      17
#define LEDMATRIX_COL2_YELLOW_PIN   2
#define LEDMATRIX_COL2_RED_PIN      18
#define LEDMATRIX_COL3_YELLOW_PIN   3
#define LEDMATRIX_COL3_RED_PIN      19
#define LEDMATRIX_COL4_YELLOW_PIN   4
#define LEDMATRIX_COL4_RED_PIN      20
#define LEDMATRIX_COL5_YELLOW_PIN   5
#define LEDMATRIX_COL5_RED_PIN      21
#define LEDMATRIX_COL6_YELLOW_PIN   6
#define LEDMATRIX_COL6_RED_PIN      22
#define LEDMATRIX_COL7_YELLOW_PIN   7
#define LEDMATRIX_COL7_RED_PIN      23

#define LEDMATRIX_ROW0PIN   8
#define LEDMATRIX_ROW1PIN   9
#define LEDMATRIX_ROW2PIN   10
#define LEDMATRIX_ROW3PIN   11
#define LEDMATRIX_ROW4PIN   12
#define LEDMATRIX_ROW5PIN   13
#define LEDMATRIX_ROW6PIN   14
#define LEDMATRIX_ROW7PIN   15

#else

#define LEDMATRIX_ROW0_YELLOW_PIN   0
#define LEDMATRIX_ROW0_RED_PIN      8
#define LEDMATRIX_ROW1_YELLOW_PIN   1
#define LEDMATRIX_ROW1_RED_PIN      9
#define LEDMATRIX_ROW2_YELLOW_PIN   2
#define LEDMATRIX_ROW2_RED_PIN      10
#define LEDMATRIX_ROW3_YELLOW_PIN   3
#define LEDMATRIX_ROW3_RED_PIN      11
#define LEDMATRIX_ROW4_YELLOW_PIN   4
#define LEDMATRIX_ROW4_RED_PIN      12
#define LEDMATRIX_ROW5_YELLOW_PIN   5
#define LEDMATRIX_ROW5_RED_PIN      13
#define LEDMATRIX_ROW6_YELLOW_PIN   6
#define LEDMATRIX_ROW6_RED_PIN      14
#define LEDMATRIX_ROW7_YELLOW_PIN   7
#define LEDMATRIX_ROW7_RED_PIN      15

#define LEDMATRIX_COL0PIN   8
#define LEDMATRIX_COL1PIN   9
#define LEDMATRIX_COL2PIN   10
#define LEDMATRIX_COL3PIN   11
#define LEDMATRIX_COL4PIN   12
#define LEDMATRIX_COL5PIN   13
#define LEDMATRIX_COL6PIN   14
#define LEDMATRIX_COL7PIN   15

#endif


#endif
