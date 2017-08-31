# Magnetometer Interfacing
## Introduction
Magnetometer is a device which gives us earth's magnetic field at a point. In Pratham HMR2300 of Honeywell sensor products was used it's datasheet can be found [here](https://github.com/singhalanirudh18/advitaya/blob/master/OBCm--MAG--FT2017--Anirudh/hmr2300_Magnetometer.pdf).
*Our objective is to get earth's magnetometer in meaningful data format*.
## Interfacing
Our magnetometer has a procedure for polling. When we poll the magnetometer it gives sends us 6 bytes 2 corresponding to each axis.
For poling we have to send the following command :-
```C
transmit_string_UART1("*00P\r");
```
We use UART1 because in Pratham's case UART1 of the OBC was connected to the Magnetometer.
## Flow of Code
1. **Polling** :- Poll magnetometer for data.
2. **Storage** :- Store the data received from the magnetometer.
3. **Processing** :- Process the data.
## Functions Used
1.**Polling** - To poll the magnetometer I have defined mag_poll() whose implementation is as following :-
```C
void mag_poll(){
	n=0;
	transmit_string_UART1("*00P\r");
}
```
Where n keeps track of the number of bytes received.

2.**Storage**-Storage of the data is done in ISR(Interrupt Service Routine). Implementation is as follows:-
 ```C
 ISR(USART1_RX_vect)
{
	maginfo = UDR1;
	transmit_UART0(maginfo);
	if(hex== 1){
	B[n]= maginfo;
	n++;
	if (n==6) {
		mag_value();
	}
	}
```
When n=6 i.e. all the bytes have been received we call mag_value() for data processing.

3.**Processing** - Implementatin of mag_value() is as follows:-
First extract 2 bytes corresponding to each axis of magnetic field :-
```C
void mag_value(){
	
	int Bxh = B[0];
	int Bxl = B[1];
	int Byh = B[2];
	int Byl = B[3];
	int Bzh = B[4];
  int Bzl = B[5];
```
After this we get the value corresponding to each axis. 
```C
Bx = Bxh*16*16 + Bxl;
By = Byh*16*16 + Byl;
Bz = Bzh*16*16 + Bzl;
```
Then finally we scale down Bx to get a floating point number corresponding to magnetic field in gauss. 
```C
BX = (Bx/30000.0)*2.0;
BY = (By/30000.0)*2.0;
BZ = (Bz/30000.0)*2.0;
}
```
After calling this function global varibles BX ,BY and BZ have been updated.
## Tests to check the data
1. Cross check the data from ASCII function of magnetometer.
2. Reverse the direction of axis and check whether value of corresponding axis becomes negative or not.
3. Cross check the magnitude of magnetic field. It should be of the order of the known value of magnetic field.
