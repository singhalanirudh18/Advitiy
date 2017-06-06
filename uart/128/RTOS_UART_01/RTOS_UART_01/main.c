#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
//#include <windows.h>
#include "osHeader.h"
int t;
int main(void)
{	t=1;
	DDRC = 0xFF; //Makes PORTC as Output
	DDRA = 0xFF;
	DDRB = 0xFF;
	PORTC = 0xFF; 
	createTask(Task1, 1, TaskId_1);
	createTask(Task2, 2, TaskId_2);
	startOS();
	return 0;
/*
	while(1) //infinite loop
	{
		PORTC = 0xFF; //Turns ON All LEDs
		_delay_ms(1000); //1 second delay
		PORTC= 0x00; //Turns OFF All LEDs
		_delay_ms(1000); //1 second delay
	}
*/	
}
void Task1()
{

	while(1)
	{
		for (int i = 0; i < t; i++)
		{
		PORTA = 0xFF; //Turns ON All LEDs
		_delay_ms(1000); //1 second delay
		PORTA= 0x00; //Turns OFF All LEDs
		_delay_ms(1000); //1 second delay
		//Stop the task
		}
		waitTask();
		
	}

}

void Task2()
{
	while(1)
	{
		for (int i = 0; i < t; i++)
		{
		PORTB = 0xFF; //Turns ON All LEDs
		_delay_ms(1000); //1 second delay
		PORTB= 0x00; //Turns OFF All LEDs
		_delay_ms(1000); //1 second delay
		}
		//start the task
		startTask(TaskId_1);
		
	}
}
