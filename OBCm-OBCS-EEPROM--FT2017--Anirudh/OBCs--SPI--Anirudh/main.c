/*
 * OBCs--SPI--FT2017.c
 *
 * Created: 27-09-2017 22:35:46
 * Author : Anirudh Singhal
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "common.h"
#include "timer.h"
#include "uart.h"
#include "spi.h"
#include "i2c.h"
#include "led_tests.h"
#include "eeprom.h"
//#include "mag.h"
#include <stdio.h>
#include <avr/wdt.h>

int len_write = 0;
//uint8_t send_buffer[50] ;//= {'a','b','c','d','e'} ;
//uint8_t receive_buffer[50] ;
int flag = 0;

int main(void)
{
	//Initializations
	
	init_UART0();
	init_UART1();
	uint8_t a1 = 'x';
	for(int xx = 0;xx<4;xx++)
	{
		transmit_UART0(a1);
		PORTA = 0xFF;
		_delay_ms(500);
		PORTA = 0x00;
		_delay_ms(500);
		
		//led_test_m_config();
	}
	
	
	//Interrupt
	sei();//global interrupt enable
	init_SPI_slave();
	
	
	while(1){
	
	}
}

ISR(SPI_STC_vect){
	uint8_t recx = SPDR;
	//if(recx == 0xAA) transmit_UART0(recx);
	//else transmit_UART0(0xFF);
	transmit_UART0(recx);
}

