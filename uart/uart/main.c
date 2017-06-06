/*
 * GccApplication1.c
 *
 * Created: 27/02/2017 11:08:56 PM
 * Author : USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
//#define BAUD 9600
//#define MYUBRR F_CPU/16/BAUD-1

void USART_Init(unsigned int ubrr)
{
	
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	//UCSRB = (1<<RXEN)|(1<<TXEN);
	
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<USBS) | (1<<UCSZ1)|(1<<UCSZ0);
}


char USARTReadChar()
{
	

	while(!(UCSRA & (1<<RXC)))
	{
		
	}


	return UDR;
}

void USARTWriteChar(char c)
{
	

	while(!(UCSRA & (1<<UDRE)))
	{
		
	}


	UDR=c;
}
void main()
{
	
	
	char data;

	
	

	USART_Init(95);

	while(1)
	{
		
		
		data=USARTReadChar();
          //data='a';
		//USARTWriteChar('[');
		USARTWriteChar(data);
		//_delay_ms(100);
		
		//USARTWriteChar(']');


	}
}