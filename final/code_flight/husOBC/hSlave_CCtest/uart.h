/*
 * uart.h
 *
 * Created: 31-03-2012 14:39:20
 *  Author: Hussain
 */ 

/**
 * @file uart.h
 * @brief Contains the various pin/port definitions and procedures for uart.
 */

#ifndef UART_H_
#define UART_H_

#include "common.h"

void init_UART0(void );

void transmit_UART0(char data);

uint8_t receive_UART0(void);

void send_preflight(char *data, uint16_t size);

void transmit_string_UART0(char *buffer);

void transmit_ASCII_UART0(char data);

#endif /* UART_H_ */