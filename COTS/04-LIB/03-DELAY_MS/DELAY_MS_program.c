/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 11 Dec 2019                          */
/* Layer: LIB                                 */
/* Component: DELAY_MS                        */
/* File Name: DELAY_MS_program.c              */
/**********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DELAY_MS_interface.h"

/* Time Mandatory =  Context Switching + Calculations Time + Return Time */
#define TM 0.009605 
/* Iteration Time */
#define T1  0.004375

void Delay_ms(u32 value)
{
  u32 i;
  u32 count = (value - TM) / T1;
  
  for (i = 0; i<count; i++) 
  {
    asm("NOP");
  }
  
}