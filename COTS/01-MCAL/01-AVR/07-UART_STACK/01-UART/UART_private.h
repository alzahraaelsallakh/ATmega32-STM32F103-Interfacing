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

#endif
