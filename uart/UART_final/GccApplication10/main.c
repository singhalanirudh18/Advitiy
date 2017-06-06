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
	
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	//UCSRB = (1<<RXEN)|(1<<TXEN);
	//UCSRB |= (1 << RXCIE);
	UCSRB = (1<<RXEN)|(1<<TXEN);
	
	UCSRC = (1<<URSEL) | (1<<USBS) | (1<<UCSZ1)|(1<<UCSZ0); // 1 stop bit,
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

	PORTC^=0xFF;
	UDR=c;
} 


int main(void)
{
	USART_Init(103); // as F_OSC = 16MHz
	sei();
	UCSRB |= (1 << RXCIE);
	USARTWriteChar('e');
	DDRC = 0xFF;
	PORTC= 0x00;
    /* Replace with your application code */
	_delay_ms(5000);
	
   char xyz[] = {'2','3','4','5'};
   int i =0;
    while (1) 
    { 
		USARTWriteChar(xyz[i]);
		PORTC^=0xFF;
		int k = xyz[i] - '0';
		_delay_ms(12000);
		i++;
		if (i==4) i=0;
		
		/*
		d= USARTReadChar();
		USARTWriteChar(d);
		*/
    }
}

ISR(USART_RXC_vect){
	//USARTWriteChar('y');
	d=UDR;
	UDR=d;
	PORTC^=0xFF;
	//d = USARTReadChar();
	//USARTWriteChar(d);
	if(d=='a'){
	//PORTC = 0xFF; //Turns ON All LEDs
    //_delay_ms(1000); //1 second delay
    //PORTC= 0x00; //Turns OFF All LEDs
    //_delay_ms(1000); //1 second delay
}}