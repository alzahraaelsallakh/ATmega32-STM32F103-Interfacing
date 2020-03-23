/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Dec 2019                           */
/* Layer: LIB                                 */
/* Component: STD_TYPES                       */
/* File Name: STD_TYPES.h                     */
/**********************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
typedef long double f96;

typedef enum Error 
{
  OK,
  NOK,
  NULLPOINTER
  
}ErrorStatus;


#define STD_TYPES_ERROR_NOK             1
#define STD_TYPES_ERROR_OK              2
#define STD_TYPES_ERROR_NULL_POINTER    3

#define NULL ((void*)0)

#endif