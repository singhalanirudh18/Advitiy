/*
 * usarT_INTERRUPT_001.c
 *
 * Created: 12/02/2017 12:54:03 AM
 * Author : USER
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

//#define BAUD 9600
//#define MYUBRR F_CPU/16/BAUD-1
char d;



char USARTReadChar()
{
	

	while(!(UCSR0A & (1<<RXC)))
	{
		
	}


	return UDR0;
}

void USARTWriteChar(char c)
{
	

	while(!(UCSR0A & (1<<UDRE)))
	{
		
	}

	PORTC^=0xFF;
	UDR0=c;
} 

