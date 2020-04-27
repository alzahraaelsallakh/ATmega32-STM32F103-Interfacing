/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */
/* Layer: MCAL                                */
/* Component: STK                             */
/* File Name: STK_program.c                   */
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_register.h"
#include "STK_private.h"


void (*SysTick_CallBack) (void);

void STK_voidInitialize (void)
{
  /* Enable Systick Interrupt - Clock = AHB/8 */
  /* Stop Systick */
  
  STK_CTRL = 0x00000002;
}

void STK_voidStart (u32 Copy_u32Value)
{
  /* Load Value Into Load Register */
  STK_LOAD = Copy_u32Value;
  
  /* Clear Value Register */
  STK_VAL = 0;
  
  /* Start System Timer */
  SET_BIT(STK_CTRL,0);
}

void STK_voidBusyDelay(u32 Copy_u32Microseconds)
{
	/* Disable interrupt */
	CLR_BIT(STK_CTRL,1);

	/* Load "Load register" and clear "Value" */
	STK_LOAD = Copy_u32Microseconds;
	STK_VAL = 0;

	/* Enable STK */
	SET_BIT(STK_CTRL,0);

	/* Wait flag */
	while (GET_BIT(STK_CTRL,16) == 0);

}

void STK_voidSetCallBack(void(*Copy_Ptr)(void))
{
    SysTick_CallBack = Copy_Ptr;
}

void SysTick_Handler (void)
{
  SysTick_CallBack();
}
