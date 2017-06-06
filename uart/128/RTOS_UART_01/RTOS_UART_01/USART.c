/*
 * USART.c
 *
 * Created: 31-05-2017 22:55:24
 *  Author: Anirudh Singhal
 */ 
void USART_Init(unsigned int ubrr)
{
	
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	//UCSRB = (1<<RXEN)|(1<<TXEN);
	//UCSRB |= (1 << RXCIE);
	UCSR0B = (1<<RXEN)|(1<<TXEN);
	
	UCSR0C = (1<<USBS) | (1<<UCSZ1)|(1<<UCSZ0); // 1 stop bit,
}


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
