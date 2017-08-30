/*
 * i2c.c
 *
 * Created: 15-07-2017 21:31:43
 *  Author: Aniruddha Ranade
 */ 
#include <avr/io.h>
#include "i2c.h"
#include "common.h"


void TWI_init_master(void) // Function to initialize master for I2C
{
	//sei();

	TWSR = 0;
	TWCR = 0;
	TWBR = (F_CPU / 200000UL - 16) / 2; // Bit rate
	//TWSR=(0<<TWPS1)|(0<<TWPS0); // Setting prescalar bits
	// SCL freq= F_CPU/(16+2(TWBR).4^TWPS)

}

void TWI_start(void) //Function to send I2C start command
{
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= 0x08); // Check for the acknowledgement
}

void TWI_repeated_start(void) // Function to send I2C repeated start command. Scarcely used
{
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // wait till restart condition is transmitted
	while((TWSR & 0xF8)!= 0x10); // Check for the acknoledgement
}

void TWI_write_address(unsigned char data)//Function for Master side to send slave address for I2C
{

	TWDR=data; // Address and write instruction
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT)))// Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8)!= 0x18);  // Check for the acknowledgement

}

void TWI_read_address(unsigned char data) //Function for slave side to read address sent by Master
{
	TWDR=data; // Address and read instruction
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
	while((TWSR & 0xF8)!= 0x40);  // Check for the acknoledgement
}

void TWI_write_data(unsigned char data)//Function to write data on I2C data line
{
	TWDR=data; // put data in TWDR
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x28); // Check for the acknoledgement
}

void TWI_read_data(void) //Function to read data from I2C data line
{
	char recv_data;
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x58); // Check for the acknoledgement
	recv_data=TWDR;//PORTA=recv_data;
	//if(UniversalCycles % CyclesToCollectData == 0){transmit_UART0(recv_data);}
	
}

void TWI_stop(void)//Function to stop data transmission
{
	// Clear TWI interrupt flag, Put stop condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
}
