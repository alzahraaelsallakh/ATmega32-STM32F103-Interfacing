/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 22 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: RCC                             */
/* File Name: RCC_program.c                   */
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_register.h"
#include "RCC_private.h"
#include "RCC_config.h"


extern void RCC_voidInit (void)
{
  /* 
  HSI -> off
  PLL -> off
  HSE -> on
  CSS -> off 
  */
  CR = 0x00010000;
    
  /*
  SysClk -> HSE
  AHB, APB1, APB2 -> No division
  MCO -> Not connected 
  */  
  CFGR = 0x00000001;
  
}

extern void RCC_voidEnablePeripheralClock(u8 Copy_u8Bus, u8 Copy_u8Peripheral)
{
  switch (Copy_u8Bus)
  {
    case 0: /* AHB */
      SET_BIT(AHBENR, Copy_u8Peripheral); break;
    case 1: /* APB1 */
      SET_BIT(APB1_ENR , Copy_u8Peripheral); break;
    case 2: /* APB2 */
      SET_BIT(APB2_ENR , Copy_u8Peripheral);
  }
}
extern void RCC_voidDisablePeripheralClock(u8 Copy_u8Bus, u8 Copy_u8Peripheral)
{
  switch (Copy_u8Bus)
  {
    case 0: /* AHB */
      CLR_BIT(AHBENR, Copy_u8Peripheral); break;
    case 1: /* APB1 */
      CLR_BIT(APB1_ENR, Copy_u8Peripheral); break;
    case 2: /* APB2 */
      CLR_BIT(APB2_ENR, Copy_u8Peripheral);
  }  
}