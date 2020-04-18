/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 09 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: UART                              */
/* File Name: UART_private.h                    */
/************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART_PARITY_DISABLED    0U
#define UART_PARITY_EVEN        2U
#define UART_PARITY_ODD         3U

#define UART_BAUDRATE_4800      0U
#define UART_BAUDRATE_9600      1U
#define UART_BAUDRATE_115200    2U

#define UART_STOP_1_BIT         0U
#define UART_STOP_2_BIT         1U

#define UART_SYSTEM_FREQ_8M     0U
#define UART_SYSTEM_FREQ_12M    1U
#define UART_SYSTEM_FREQ_16M    2U

/*
	Registers' Bits
*/

#define UCSRA_U2X		  1
#define UCSRA_TX_CMP	  6
#define UCSRA_RX_CMP	  7
						  
#define UCSRB_UCSZ2		  2
#define UCSRB_TX_EN		  3
#define UCSRB_RX_EN		  4
#define UCSRB_UDRIE		  5
#define UCSRB_TX_INT_EN	  6
#define UCSRB_RX_INT_EN	  7
						  
#define UCSRC_UCSZ0		  1
#define UCSRC_UCSZ1		  2
#define UCSRC_USBS		  3
#define UCSRC_UPM0		  4
#define UCSRC_URSEL		  7

#endif
