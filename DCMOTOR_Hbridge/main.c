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
 MDIO_voidSetPinDirection(PORTA, PIN0, OUTPUT); //Set Pin A7 to output
 MDIO_voidSetPinDirection(PORTA, PIN1, OUTPUT); //Set Pin A6 to output

	 while (1)
	 {
		 HDCMOTOR_voidfunctionClockWise(PORTA, PIN0, PIN1);
         _delay_ms(50);
         HDCMOTOR_voidfunctionUntiClockWise(PORTA, PIN0, PIN1);
		 _delay_ms(50);
	 }
}


