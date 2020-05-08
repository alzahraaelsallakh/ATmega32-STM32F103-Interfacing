/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 29 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: WDT                               */
/* File Name: WDT_interface.h                   */
/************************************************/

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H



/*
    Description: This function shall sleep WDT
    Input: 
			1- Copy_u8SleepOption -> Sleep time option for WDT
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR WDT_errSleep (u8 Copy_u8SleepOption);

/*
    Description: This function shall stop WDT
    Input: void
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR WDT_errStop (void);


#endif
