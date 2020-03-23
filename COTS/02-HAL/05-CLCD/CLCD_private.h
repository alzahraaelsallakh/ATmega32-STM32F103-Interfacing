/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 14 Jan 2020                          */
/* Layer: HAL                                 */
/* Component: CLCD                            */
/* File Name: CLCD_private.h                  */
/**********************************************/

#ifndef CLCD_PRIVATE_H
#define CLCD_PRIVATE_H


#define CLCD_LINE_1_CMD       0x80
#define CLCD_LINE_2_CMD       0xC0

#define FOUR_BITS_MODE        0
#define EIGHT_BITS_MODE       1

static void CLCD_voidSetDataPort (u8 Copy_u8Data);
static void CLCD_voidSetHalfDataPort (u8 Copy_u8Data);

#endif