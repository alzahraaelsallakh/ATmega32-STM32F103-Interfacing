/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 26 Feb 2020                            */
/* Layer: MCAL                                  */
/* Component: TIMER0                            */
/* File Name: TIMER0_program.c                  */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "INTGLB_interface.h"

#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"



static void (*Timer0_Callback)(void);

/*
    Description: This function shall initiate Timer driver
    Input: void
    output: void
*/
void TIMER0_voidInit(void)
{
  /* Timer0/Counter overflow interrupt enable */
  SET_BIT(TIMSK,0);
  
  /* Global interrupts enable */
  INTGLB_voidEnableGlobal();
  
  /* Setting timer preload value */
  TCNT0 = PRELOAD_VALUE;
  
  /* Setting timer prescaler */
  TCCR0 &= TIMER0_CLOCK_SELECT_CLEAR;
  TCCR0 |= TIMER0_CLOCK_SELECT;
  
}

/*
    Description: This function shall set call back function that is called when timer interrupt is raised
    Input: Copy_ptrCallBack is a pointer that contains the callback function, the function arguments and return are void type
    output: void
*/
void TIMER0_voidSetCallback(void(*Copy_ptrCallBack)(void))
{
  /* Assigning the callback function */
  Timer0_Callback = Copy_ptrCallBack;
}

void __vector_11(void)
{
  /* Calling timer callback function */
  Timer0_Callback();
  /* Setting timer preload value */
  TCNT0 = PRELOAD_VALUE;
}