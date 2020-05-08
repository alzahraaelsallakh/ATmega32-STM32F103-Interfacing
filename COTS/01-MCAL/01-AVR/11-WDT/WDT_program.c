/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 29 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: WDT                               */
/* File Name: WDT_program.c                     */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "WDT_interface.h"
#include "WDT_config.h"
#include "WDT_register.h"
#include "WDT_private.h"

/*
    Description: This function shall sleep WDT
    Input: 
			1- Copy_u8SleepOption -> Sleep time option for WDT
    output: STD_TYPES_ERROR
*/    
STD_TYPES_ERROR WDT_errSleep (u8 Copy_u8SleepOption)
{	
	
	/* Set WDE and WDOE bit at same time */
	WDTCR = 0b00011000;
	
	/* Clear WDE */
	WDTCR = 0;
	
	/* Set prescaling and set bit 4 for enable */
	WDTCR = (Copy_u8SleepOption | 0b1000);
}

/*
    Description: This function shall stop WDT
    Input: void
    output: STD_TYPES_ERROR
*/    
STD_TYPES_ERROR WDT_errStop (void)
{
	/* Set WDE and WDOE bit at same time */
	WDTCR = 0b00011000;
	
	/* Clear WDE */
	WDTCR = 0;
}

	