/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 22 Apr 2020                            */
/* Layer: HAL                                   */
/* Component: NOKIA                             */
/* File Name: NOKIA_interface.h                 */
/************************************************/

#ifndef NOKIA_INTERFACE_H
#define NOKIA_INTERFACE_H



/*
    Description: This function shall initiate NOKIA
    Input: void
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR NOKIA_errInit (void);


/*
    Description: This function shall display data on Nokia LCD
    Input:
    		1- Copy_u8DataArray -> Pointer to data to be displayed
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR NOKIA_errDisplay (u8 * Copy_u8DataArray);


#endif
