/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 22 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: SPI                               */
/* File Name: SPI_register.h                    */
/************************************************/

#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H


/* SPI Registers */
typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;

}SPI_t;

/* SPI Base Address on APB2 Bus */
#define SPI1  ((volatile SPI_t*) 0x40013000)

#endif
