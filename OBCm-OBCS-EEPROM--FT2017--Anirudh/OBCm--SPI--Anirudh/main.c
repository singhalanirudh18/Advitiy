/*
 * OBCm--SPI--FT2017--Anirudh.c
 *
 * Created: 27-09-2017 22:42:16
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
//#include "mag.h"
#include <stdio.h>
#include <avr/wdt.h>


int main(void)
{
	//Initializations
	
	init_UART0();
	init_UART1();
	DDRA = 0xFF;
	/*
	for(int xx = 0;xx<100;xx++)
	{
		PORTA = 0xFF;
		_delay_ms(500);
		PORTA = 0x00;
		_delay_ms(500);
		
		//led_test_m_config();
	}*/
	//Interrupt
	sei();//global interrupt enable
	init_SPI();
	uint8_t test = 'b';
	//SPI_transfer(test);
	//_delay_ms(5000);
	
	/*for (int i=0;i<5;i++)
	{
		SPI_transfer(test);
		test += 0x01;
		_delay_ms(500);
	}*/
	while(1){
	SPI_transfer(0xAA);
	_delay_ms(1000);
	SPI_transfer(0xBB);
	_delay_ms(1000);
	/*SPI_transfer(0x00);
	_delay_ms(500);
	SPI_transfer(0x01);
	_delay_ms(500);*/
	//test = test + 0x01;
	}
}

/*ISR(USART0_RX_vect){
	uint8_t send = UDR0 ;
	UDR0 = send;
	//SPI_transfer(send);
}*/