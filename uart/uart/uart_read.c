/*
 * usarT_INTERRUPT_001.c
 *
 * Created: 12/02/2017 12:54:03 AM
 * Author : USER
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
//#define BAUD 9600
//#define MYUBRR F_CPU/16/BAUD-1
char d;
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


int main(void)
{
	USART_Init(95);
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(USART_RXC_vect){
	//c=UDR;
	//UDR=c;
	d = USARTReadChar();
}