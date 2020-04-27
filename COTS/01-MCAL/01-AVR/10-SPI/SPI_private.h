/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 27 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: SPI                               */
/* File Name: SPI_private.h                     */
/************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* SPCR bits */
#define SPCR_SPIE	7
#define SPCR_SPE	6
#define SPCR_DORD	5
#define SPCR_MSTR	4
#define SPCR_CPOL	3
#define SPCR_CPHA	2
#define SPCR_SPR1	1
#define SPCR_SPR0	0

/* SPSR bits */
#define SPSR_SPIF	7
#define SPSR_WCOL	6
#define SPSR_SPI2X	0


/* Configurations */

/* Master/Slave mode */
#define SPI_u8_MASTER	0
#define SPI_u8_SLAVE	1

/* Data order */
#define SPI_u8_MSB		0
#define SPI_u8_LSB		1

/* Clock polarity */
#define SPI_u8_RAISING_EDGE     0
#define SPI_u8_FALLING_EDGE     1

/* Clock phase */
#define SPI_u8_SAMPLE           0
#define SPI_u8_SETUP            1

/* Clock rate -> Master mode */
#define SPI_u8_CLK_OVER_4       0
#define SPI_u8_CLK_OVER_16      1
#define SPI_u8_CLK_OVER_64      2
#define SPI_u8_CLK_OVER_128     3
#define SPI_u8_HCLK_OVER_2      4
#define SPI_u8_HCLK_OVER_8      5
#define SPI_u8_HCLK_OVER_32     6
#define SPI_u8_HCLK_OVER_64     7


/* For interrupts use */
void __vector_12(void)  __attribute__((signal));

#define ISR(NO)        void __vector_##NO(void) __attribute__((signal)); \
							void __vector_##NO(void)
#endif
