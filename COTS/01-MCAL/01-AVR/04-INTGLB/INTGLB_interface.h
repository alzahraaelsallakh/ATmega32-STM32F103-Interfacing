/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: INTBLG                          */
/* File Name: INTGLB_interface.h              */
/**********************************************/

/* preprocessor File Gurad */
#ifndef INTGLB_INTERFACE_H
#define INTGLB_INTERFACE_H


/*
 * Description: A function to enable global interrupts
 * Input: void
 * Output: void
 */
void INTGLB_voidEnableGlobal (void);

/*
 * Description: A function to disable global interrupts
 * Input: void
 * Output: void
 */
void INTGLB_voidDisableGlobal (void);

#endif