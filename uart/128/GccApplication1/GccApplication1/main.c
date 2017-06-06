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


int main(void)
{
	USART_Init(103); // as F_OSC = 16MHz
	sei();
	UCSR0B |= (1 << RXCIE);
	USARTWriteChar('e');
	DDRC = 0xFF;
	PORTC= 0x00;
    /* Replace with your application code */
   char xyz[] = {'0','a','b','c'};
   int i =0;
    while (1) 
    { /*
		USARTWriteChar(xyz[i]);
		//PORTC^=0xFF;
		_delay_ms(10000);
		i++;
		if (i==3) i=0;
		
		/*
		d= USARTReadChar();
		USARTWriteChar(d);
		*/
		
		//USARTWriteChar('a');
		//_delay_ms(1000);
    }
}

ISR(USART0_RX_vect){
	//USARTWriteChar('y');
	d=UDR0;
	UDR0=d;
	PORTC^=0xFF;
	//d = USARTReadChar();
	//USARTWriteChar(d);
	if(d=='a'){
	//PORTC = 0xFF; //Turns ON All LEDs
    //_delay_ms(1000); //1 second delay
    //PORTC= 0x00; //Turns OFF All LEDs
    //_delay_ms(1000); //1 second delay
}}