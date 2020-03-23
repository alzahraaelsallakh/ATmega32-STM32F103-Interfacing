/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 09 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: UART                              */
/* File Name: UART_config.h                     */
/************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* Configuration options of parity
   1- UART_PARITY_DISABLED
   2- UART_PARITY_EVEN
   3- UART_PARITY_ODD
 */
#define UART_u8_PARITY     UART_PARITY_DISABLED

/* Configuration options of baudrate
   1- UART_BAUDRATE_4800
   2- UART_BAUDRATE_9600
   3- UART_BAUDRATE_115200
 */
#define UART_u8_BAUDRATE   UART_BAUDRATE_9600

/* Configuration options of stop bits
   1- UART_STOP_1_BIT
   2- UART_STOP_2_BIT
 */
#define UART_u8_STOP_BITS  UART_STOP_1_BIT

/* Configuration options of system frequency
   1- UART_SYSTEM_FREQ_8M
   2- UART_SYSTEM_FREQ_12M
   3- UART_SYSTEM_FREQ_16M
 */
#define UART_u8_SYSTEM_FREQ UART_SYSTEM_FREQ_8M



#define UART_u32_TIME_OUT_THRESHOLD    10000UL

#endif
