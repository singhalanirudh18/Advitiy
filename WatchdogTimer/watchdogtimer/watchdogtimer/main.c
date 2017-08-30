/*
 * watchdogtimer.c
 *
 * Created: 26-08-2017 18:54:48
 * Author : Anirudh Singhal
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "uart.h"
#include "led_tests.h"
#include <stdio.h>
#include <avr/wdt.h>
#include "timer.h"
uint8_t wd;
void f(void){
	wd=0x00;
	for (int i=0;i<5;i++)
	{
		_delay_ms(100);
		wd= wd + 0x01;
		transmit_UART0(wd);
	}
}

int main(void)
{
    init_UART0();
    init_UART1();
   /* transmit_UART0(0xfa);
    transmit_UART0(MCUCSR);
    MCUCSR&=~(_BV(WDRF)); */
   transmit_UART0(wd);
    for(int xx = 0;xx<1;xx++)
    {
	    _delay_ms(2000);
	    led_test_m_config();
    }
    //Interrupt
    sei();//global interrupt enable
    /*
	transmit_UART0(0xff);
   // wdt_reset();
    _delay_ms(1000);
    transmit_UART0(MCUCSR);
    transmit_UART0(WDTCR);
    //WDTCR |= _BV(WDE)| _BV(WDP2) |_BV(WDP1)  ;
    //WDTCR = 0x0f;
    //wdt_enable(20);
	watch_dog(2);
	transmit_UART0(0xff);
    //_delay_ms(1000);
    transmit_UART0(MCUCSR);
    transmit_UART0(WDTCR);
    */
	/*while(1){
		watch_dog(7);
	while(1){
	
		
	    _delay_ms(50);
	    //transmit_UART0(0xfe);
	    //transmit_UART0(MCUCSR);
		transmit_UART0('y');
	}
	}
	transmit_UART0('x');*/
	//watch_dog(7);
	//{f();};
	//wdt_disable();
	//transmit_UART0(0xff);
	//
	while (1)
	{	
		timer_reset_two_sec(); // global reset of counter to 0 always first line of the loop
		/* part whose time needs to be checked 
		order should be :-
		wdt_enable(time)
		wdt_reset()
		do the thing
		wdt_disable();
		*/
		wdt_enable(WDTO_2S);
		wdt_reset();
		f();
		
		
		wdt_disable();
		timer_wait_reset(); // waits if the time is less than 2 sec always the last line of the loop where the time has to be checked
		transmit_UART0(0xff);
	}

}

