/*******************************************************************************************
* ! Title : 7SEG Program
* ! File Name : main.c
* ! Description : This file has the implementation code for switching on led
* ! Version : V1.0
********************************************************************************************/

#define F_CPU 80000000
//AVR Input Output Library Includes
#include<avr/io.h>
#include<util/delay.h>

void main(void)
{
	DDRC = 0xFF;
	DDRD = 0xFF;
	while(1)
	{
		//To Display Number19
		PORTC = 0b00000110;
		PORTD = 0b01101111;
		_delay_ms(100);

		//To Display Number08
		PORTC = 0b00111111;
		PORTD = 0b01111111;
		_delay_ms(100);


	}

}




