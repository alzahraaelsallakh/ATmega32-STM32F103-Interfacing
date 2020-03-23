/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 22 Dec 2019                          */
/* Layer: MCAL                                */
/* Component: RCC                             */
/* File Name: RCC_register.h                  */
/**********************************************/


#ifndef RCC_REGISTER_H
#define RCC_REGISTER_H


#define BASE_ADDRESS 0x40021000

#define CR        *((u32*) (BASE_ADDRESS + 0x00))
#define CFGR      *((u32*) (BASE_ADDRESS + 0x04))
#define CIR       *((u32*) (BASE_ADDRESS + 0x08))
#define APB2RSTR  *((u32*) (BASE_ADDRESS + 0x0C))
#define APB1RSTR  *((u32*) (BASE_ADDRESS + 0x10))
#define AHBENR    *((u32*) (BASE_ADDRESS + 0x14))
#define APB2_ENR  *((u32*) (BASE_ADDRESS + 0x18))
#define APB1_ENR  *((u32*) (BASE_ADDRESS + 0x1C))
#define BDCR      *((u32*) (BASE_ADDRESS + 0x20))
#define CSR       *((u32*) (BASE_ADDRESS + 0x24))


#endif