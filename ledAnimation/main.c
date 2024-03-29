/*******************************************************************************************
* ! Title : Led Program
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
	DDRA = 0xFF;
	while(1)
	{
		PORTA = 0xff;
		_delay_ms(100);
		PORTA = 0b00000001;
		_delay_ms(100);
		PORTA = 0b00000010;
		_delay_ms(100);
		PORTA = 0b00000100;
		_delay_ms(100);
		PORTA = 0b00001000;
		_delay_ms(100);
		PORTA = 0b00010000;
		_delay_ms(50);
		PORTA = 0b00100000;
		_delay_ms(50);
		PORTA = 0b01000000;
		_delay_ms(50);
		PORTA = 0b10000000;
		_delay_ms(50);
	}

}
