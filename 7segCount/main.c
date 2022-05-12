/*******************************************************************************************
* ! Title : 7SEG_Count Program
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
	while(1)
	{
		//To Display Number0
		PORTC = 0b00111111;
		_delay_ms(100);

		//To Display Number1
		PORTC = 0b00000110;
		_delay_ms(100);

		//To Display Number2
		PORTC = 0b01011011;
		_delay_ms(100);

		//To Display Number3
		PORTC = 0b01001111;
		_delay_ms(100);

		//To Display Number4
		PORTC = 0b01100110;
		_delay_ms(100);

		//To Display Number5
		PORTC = 0b01101101;
		_delay_ms(100);

		//To Display Number6
		PORTC = 0b01111101;
		_delay_ms(100);

		//To Display Number7
		PORTC = 0b00000111;
		_delay_ms(100);

		//To Display Number8
		PORTC = 0b01111111;
		_delay_ms(100);

		//To Display Number9
		PORTC = 0b01101111;
		_delay_ms(100);
	}

}


