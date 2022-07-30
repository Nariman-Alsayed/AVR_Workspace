/*******************************************************************************************
* ! Title : Switch Program
* ! File Name : main.c
* ! Description : This file has the implementation code for controlling with switch device on led
* ! Version : V1.0
********************************************************************************************/

#include <avr/io.h>
#include <util/delay.h>


#define SET_BIT(Reg, bitnum)       (Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
#define SET_BYTE(Reg,value)        ( Reg = value )

void main (void)
{
	//Pin of_Switch is A0 -> INPUT
	//pin of_led    is A1 -> OUTPUT
	DDRA= 0b00000010;

	//1 0n A0 to activate pull up resistor
	PORTA=0b00000001;

	unsigned char pinValue=1;
	while(1)
	{
		pinValue = GET_BIT(PINA,0);
		if (pinValue==0)
		{
			//Output on led will be high
			SET_BIT(PORTA,1);
		}
		else
		{
			//Output on led will be low
			CLR_BIT(PORTA,1);
		}

	}

}



