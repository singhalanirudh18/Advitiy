/*
 * led_tests.c
 *
 * Created: 24-07-2017 22:02:20
 *  Author: Aniruddha Ranade
 */ 

#include "common.h"
#include "led_tests.h"
#include "uart.h"
#include <avr/io.h>

void led_test_m_config(void)
{
	DDRA=0x0F;
	
	transmit_string_UART0("_a_");
		
	PORTA = 0x0F;
	_delay_ms(200);
	PORTA = 0xF0;
	_delay_ms(200);

	transmit_string_UART0("_b_");
		
	PORTA = 0x0F;
	_delay_ms(200);
	PORTA = 0xF0;
	_delay_ms(200);
	
	transmit_string_UART0("_c_");
	
	PORTA = 0x0F;
	_delay_ms(200);
	PORTA = 0xF0;
	_delay_ms(200);
	
	transmit_string_UART0("_d_");
	
	PORTA = 0x0F;
	_delay_ms(200);
	PORTA = 0xF0;
	_delay_ms(200);
	
	PORTA = 0x00; 
	_delay_ms(200);
	
}

void led_test_m_a(void)
{
	PORTA |= 0b10000000;
	transmit_string_UART0(" led_a ");
	_delay_ms(200);
	PORTA &= 0b01111111;
	_delay_ms(200);
}

void led_test_m_b(void)
{
	PORTA |= 0b01000000;
	transmit_string_UART0(" led_b ");
	_delay_ms(200);
	PORTA &= 0b10111111;
	_delay_ms(200);
}

void led_test_m_c(void)
{
	PORTA |= 0b00100000;
	transmit_string_UART0(" led_c ");
	_delay_ms(200);
	PORTA &= 0b11011111;
	_delay_ms(200);
}

void led_test_m_d(void)
{
	PORTA |= 0b00010000;
	transmit_string_UART0(" led_d ");
	_delay_ms(200);
	PORTA &= 0b11101111;
	_delay_ms(200);
}