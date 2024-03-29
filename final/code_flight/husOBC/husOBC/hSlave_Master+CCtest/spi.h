/*
 * spi.h
 *
 * Created: 18-04-2012 01:42:18
 *  Author: Hussain
 */ 

/**
 * @file spi.h
 * @brief Contains the various pin/port definitions and procedures for spi.
 */

#ifndef SPI_H_
#define SPI_H_

#include "common.h"

/** @defgroup SPI Pins
 */
//@{
/// Port with SPI pins
#define PORT_SPI		PORTB
/// DDR for chip select port
#define DDR_SPI			DDRB
/// Port B bit 3: data in (data from MMC)
#define SPIDI	PB3
/// Port B bit 2: data out (data to MMC)
#define SPIDO	PB2	
/// Port B bit 1: clock
#define SPICLK	PB1
#define SPISS	PB0
//@}

/** @defgroup PORT_PIN
 *  @brief Gives the ports and pins corresponding to chip selects for SPI on master
 */
//@{
/// Port with chip select pins
#define PORT_CS             PORTB
/// DDR for chip select port
#define DDR_CS              DDRB
#define SLAVE               PB0
#define CC1020              PB0
//@}

/** @brief Initialise slave SPI for the Slave MuC
 */
void init_SPI_slave(void);

/** @brief Initialise master SPI for the Master MuC
 */
void init_SPI(void);
/**
 *  @brief   Initiates SPI for the required device
 *  @param   CS_pin Chip select pin to be selected.
 */
void init_SPI_trans(uint8_t CS_pin);

/**
 * 
 * @brief  Send data on SPI
 * @param str Character pointer to string
 * @param size Size of string
 */
void SPI_send(char* str, uint16_t size);

/** @brief  Transfer a byte through SPI and return the byte received
 *  @param  Byte to transfer
 *  @return Received Byte
 */
uint8_t SPI_transfer(uint8_t transmit_byte);

/** @brief  End SPI 
 */
void end_SPI(void);

#endif /* SPI_H_ */