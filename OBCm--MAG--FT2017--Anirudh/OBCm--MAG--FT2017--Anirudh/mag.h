/*
 * mag.h
 *
 * Created: 23-08-2017 22:15:27
 *  Author: Anirudh Singhal
 */ 


#ifndef MAG_H_
#define MAG_H_

volatile char maginfo;
//volatile int n;
void mag_ASCII();

void mag_Binary();

void mag_serial_number();

void mag_poll();

void mag_continous();

void mag_BaudRate9600();

void mag_value();

void mag_zero_on();

void mag_zero_off();

void mag_zero_toggle();

void mag_global_WE();


#endif /* MAG_H_ */