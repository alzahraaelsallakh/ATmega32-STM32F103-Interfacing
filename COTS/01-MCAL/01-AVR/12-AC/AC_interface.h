/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 17 May 2020                            */
/* Layer: MCAL                                  */
/* Component: AC                                */
/* File Name: AC_interface.h                    */
/************************************************/

#ifndef AC_INTERFACE_H
#define AC_INTERFACE_H


#define AC_u8_ANALOG_COMPARATOR_OUTPUT_POS_GREATER_NEG		1
#define AC_u8_ANALOG_COMPARATOR_OUTPUT_NEG_GREATER_POS		2


/*
    Description: This function shall initiate AC
    Input: void
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR AC_errAnalogCompInit (void);

/*
    Description: This function shall get the output of the analog comparator synchronous
    Input:
    	1- Copy_u8AnalogComOutput -> Pointer to hold the output value
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR AC_errGetAnalogCompOutputValueSynch (u8 * Copy_u8AnalogComOutput);

/*
    Description: This function shall get the output of the analog comparator synchronous
    Input:
    	1- Copy_u8AnalogComOutput -> Pointer to hold the output value
    	2- Copy_NotifyPosGreaterNeg -> Callback function to be called if the positive value is greater than the negative value
    	3- Copy_NotifyNegGreaterPos -> Callback function to be called if the negative value is greater than the positive value
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR AC_errGetAnalogCompOutputValueAsynch (u8 * Copy_u8AnalogComOutput, void (* Copy_NotifyPosGreaterNeg)(void),void (* Copy_NotifyNegGreaterPos)(void));

/*
    Description: This function shall disable AC
    Input: void
    output: STD_TYPES_ERROR
*/
extern STD_TYPES_ERROR AC_errAnalogCompDisable (void);

#endif
