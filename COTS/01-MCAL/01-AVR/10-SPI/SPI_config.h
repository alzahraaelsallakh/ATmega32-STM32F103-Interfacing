/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 27 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: SPI                               */
/* File Name: SPI_config.h                      */
/************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Configurations for master/slave mode  */
/* Options:
 * 			1- SPI_u8_MASTER
 * 			2- SPI_u8_SLAVE
 */
#define SPI_u8_SELECT_MODE		SPI_u8_MASTER

/* Configurations for data order  */
/* Options:
 * 			1- SPI_u8_MSB
 * 			2- SPI_u8_LSB
 */
#define SPI_u8_DATA_ORDER		SPI_u8_MSB

/* Configurations for clock polarity  */
/* Options:
 * 			1- SPI_u8_RAISING_EDGE
 * 			2- SPI_u8_FALLING_EDGE
 */
#define SPI_u8_CLOCK_POLARITY		SPI_u8_RAISING_EDGE

/* Configurations for clock phase  */
/* Options:
 * 			1- SPI_u8_SAMPLE
 * 			2- SPI_u8_SETUP
 */
#define SPI_u8_CLOCK_PHASE		SPI_u8_SETUP

/* Configurations for clock rate -> Master mode */
/* Options:
 * 			1- SPI_u8_CLK_OVER_4
 * 			2- SPI_u8_CLK_OVER_16
 * 			3- SPI_u8_CLK_OVER_64
 * 			4- SPI_u8_CLK_OVER_128
 * 			5- SPI_u8_HCLK_OVER_2
 * 			6- SPI_u8_HCLK_OVER_8
 * 			7- SPI_u8_HCLK_OVER_32
 * 			8- SPI_u8_HCLK_OVER_64
 */
#define SPI_u8_CLOCK_RATE		SPI_u8_CLK_OVER_16

/* Configurations for time out  */
#define SPI_u16_TIMEOUT			50000

#endif
