/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 27 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: SPI                               */
/* File Name: SPI_register.h                    */
/************************************************/

#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#define SPCR      *((volatile u8 *)0x2D)
#define SPSR      *((volatile u8 *)0x2E)
#define SPDR      *((volatile u8 *)0x2F)

#endif
