/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: User
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "util/delay.h"


void main (void)
{
 MDIO_voidSetPinDirection(PORTA, PIN7, OUTPUT); //Set Pin A7 to output

	 while (1)
	 {
		 MDIO_voidSetPinValue(PORTA,PIN7, HIGH); //Set Pin A7 to High
		 _delay_ms(1000);
		 MDIO_voidSetPinValue(PORTA,PIN7, LOW);  //Set Pin A7 to Low
		 _delay_ms(1000);
	 }
}


