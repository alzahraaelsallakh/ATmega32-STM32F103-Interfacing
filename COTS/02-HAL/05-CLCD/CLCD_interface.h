/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 14 Jan 2020                          */
/* Layer: HAL                                 */
/* Component: CLCD                            */
/* File Name: CLCD_interface.h                */
/**********************************************/

#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define CLCD_LINE_1   1
#define CLCD_LINE_2   2

/* Description: This API shall initialize LCD */
extern void CLCD_voidInitialize (void);

/* Description: This API shall display data on
                                          LCD */
extern void CLCD_voidWriteData (u8 Copy_u8Data);

/* Description: This API shall send comman to 
                                          LCD */
extern void CLCD_voidWriteCmd (u8 Copy_u8Cmd);

extern void CLCD_voidGotoLocation(u8 Copy_LineNumber,u8 Copy_Postiion);

extern void CLCD_voidWriteString(u8* Copy_pu8String);

extern void CLCD_Clear();

#endif