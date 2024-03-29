/*
 * spi.c
 *
 * Created: 31-03-2012 15:29:46
 *  Author: Hussain
 */ 

/**
 * @file spi.c
 * @brief Interfacing with the SPI bus
 */

#include "spi.h"
#include "common.h"

void init_SPI_slave(void)
{
  ///Set the Direction register for the SPI pins
  DDR_SPI &= 0xF0;
  DDR_SPI = _BV(SPIDI);
  
  ///Enable SPI, Interrupt, Slave 
  ///@todo Check frequency 
  SPCR = (1<<SPIE) |(1<<SPE);
}

void init_SPI(void)
{
  ///Set MOSI and SCK output, all others input
  DDR_SPI &= 0xF0;
  DDR_SPI = _BV(SPICLK) | _BV(SPIDO);
  
  DDR_CS |= _BV(SLAVE) | _BV(CC1020);
  ///Switch off all devices
  PORT_CS |=_BV(SLAVE) | _BV(CC1020);

  ///Enable SPI, Master, set clock rate
  ///@todo Check frequency 
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}

void init_SPI_trans(uint8_t CS_pin){
  
  ///Pull the CS_pin on the corresponding port low
  PORT_CS |=_BV(SLAVE)|_BV(CC1020);
  cbi (PORT_CS, CS_pin);
}

void SPI_send(char* str, uint16_t size) 
{
  uint16_t i = 0;
  ///In while loop:
  while(i<size)
  {
	 ///* Send one char
    SPDR = str[i];
	 ///* Wait for SPIF flag to be set (TX complete)
    while(!(SPSR & (1<<SPIF)));
    i++;
  }
  return;
}

uint8_t SPI_transfer(uint8_t transmit_byte)
{
  SPDR = transmit_byte;
  ///Wait for Transmission to complete
  while(!(SPSR & (1<<SPIF)));
  ///return received Byte
  return SPDR;
}

void end_SPI(void)
{
  ///Pull the CS_pin on the corresponding port low
  PORT_CS |=_BV(SLAVE)|_BV(CC1020);	
}