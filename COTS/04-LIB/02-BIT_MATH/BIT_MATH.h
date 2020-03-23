/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 5 Dec 2019                           */
/* Layer: LIB                                 */
/* Component: BIT_MATH                        */
/* File Name: BIT_MATH.h                      */
/**********************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BIT_NO) (VAR|=(1 <<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR &= ~ (1 <<BIT_NO))
#define TOGGLE_BIT(VAR,BIT_NO) (VAR^= (1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&1)
#define RIGHT_CIRCULAR_SHIFT(VAR,SHIFT_VALUE) (VAR = (VAR >> SHIFT_VALUE ) | (VAR << ((sizeof(VAR)*8)-SHIFT_VALUE)))
#define LEFT_CIRCULAR_SHIFT(VAR,SHIFT_VALUE) (VAR = (VAR << SHIFT_VALUE ) | (VAR >> ((sizeof(VAR)*8)-SHIFT_VALUE)))
#define ASSIGN_BIT(VAR,BIT_NO,VAL) (VAR=(VAR& ~ (1<<BIT_NO)) | (VAL << BIT_NO))


#endif