/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: INTBLG                          */
/* File Name: INTGLB_program.c                */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "INTGLB_interface.h"
#include "INTGLB_config.h"
#include "INTGLB_register.h"
#include "INTGLB_private.h"


/*
 * Description: A function to enable global interrupts
 * Input: void
 * Output: void
 */
void INTGLB_voidEnableGlobal (void)
{
  SET_BIT(SREG,SREG_I);
}

/*
 * Description: A function to disable global interrupts
 * Input: void
 * Output: void
 */
void INTGLB_voidDisableGlobal (void)
{
  CLR_BIT(SREG,SREG_I);
}