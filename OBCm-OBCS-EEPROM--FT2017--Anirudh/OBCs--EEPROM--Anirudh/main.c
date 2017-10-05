/*
 * OBCs-EEPROM.c
 *
 * Created: 05/10/2017 8:02:29 PM
 * Author : USER
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
#include <stdio.h>
#include <avr/wdt.h>

int flag =0;
uint8_t send_buffer[5] ;//= {'a','b','c','d','e'};
uint8_t receive_buffer[5] ;
int index=0;
int start=0;
int main(void)
{
    /* Replace with your application code */
    init_UART0();
	init_UART1();
	uint8_t a1 = 'x';
	for(int xx = 0;xx<1;xx++)
	{
		transmit_UART0(a1);
		PORTA = 0xFF;
		_delay_ms(500);
		PORTA = 0x00;
		_delay_ms(500);
		
		//led_test_m_config();
	}
	sei();
	init_SPI_slave();
	ioinit();
	//uint8_t send_buffer[5] = {'a','b','c','d','e'};
	//uint8_t receive_buffer[5] ;
	int len_write = 5;
	uint32_t write_addr = 0;
	//send_buffer[0]='a';
	//_delay_ms(10000);
	
	/*transmit_UART0('b');
	int yy = eeprom_write_bytes(write_addr,len_write,send_buffer);
	transmit_UART0('d');
	int zz = eeprom_read_bytes(write_addr,len_write,receive_buffer);
	for (int i =0 ; i<len_write ; i++ )
	{
		uint8_t rr = receive_buffer[i];
		transmit_UART0(rr);
		_delay_ms(500);
	}*/
	while (1) 
    {
		transmit_UART0(0xff);
		_delay_ms(250);
		if(flag == 1){
			transmit_UART0('b');
			int yy = eeprom_write_bytes(write_addr,len_write,send_buffer);
			transmit_UART0('d');
			int zz = eeprom_read_bytes(write_addr,len_write,receive_buffer);
			for (int i =0 ; i<len_write ; i++ )
			{
				uint8_t rr = receive_buffer[i];
				transmit_UART0(rr);
				_delay_ms(50);
			}
			flag=0;
		}
		
    }
}

ISR(SPI_STC_vect){
	uint8_t recx = SPDR;
	if(recx == 0x01 && start==0) {
		start = 1;
		index = 0;
		send_buffer[index] = recx;
		transmit_UART0(send_buffer[index]);
		index++;
		
	}
	else if (start ==1){
		send_buffer[index] = recx;
		//transmit_UART0(recx);
		transmit_UART0(send_buffer[index]);
		index ++;
	}
	if(index==5){
		flag = 1;
		start = 0;
		index = 0;
		/*for (int i = 0; i<5;i++)
		{
			transmit_UART0(send_buffer[i]);
			flag = 1;
			start =0;
			index = 0;
		}*/
	}
	//if(recx == 0xAA) transmit_UART0(recx);
	//else transmit_UART0(0xFF);
	//transmit_UART0(recx);
	
}