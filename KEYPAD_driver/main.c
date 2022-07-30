/*
 * main.c
 *
 *  Created on: May 19, 2022
 *      Author: NarimanAlsayed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "util/delay.h"
#define  F_CPU 8000000UL


void main (void)
{
	MDIO_voidSetPortDirection(PORTC, 0x0F);
	MDIO_voidSetPortDirection(PORTB, 0xFF);
	MDIO_voidSetPortValue(PORTC,0xFF);

		u8 local_u8KeypadValue=255;
			while(1)
			{
				local_u8KeypadValue = HKEYPAD_u8GetPressedKey();
				if (local_u8KeypadValue != KEYPAD_u8_KEY_NOT_PRESSED)
				{
					if (local_u8KeypadValue=='8')
					{
						MDIO_voidSetPortValue(PORTB,0xFF);
					}
					else if (local_u8KeypadValue=='7')
					{
						MDIO_voidSetPortValue(PORTB,0b01111111);
					}
					else if (local_u8KeypadValue=='6')
					{
						MDIO_voidSetPortValue(PORTB,0b00111111);
					}
					else if (local_u8KeypadValue=='5')
					{
						MDIO_voidSetPortValue(PORTB,0b00011111);
					}
					else if (local_u8KeypadValue=='4')
					{
						MDIO_voidSetPortValue(PORTB,0b00001111);
					}
					else if (local_u8KeypadValue=='3')
					{
						MDIO_voidSetPortValue(PORTB,0b00000111);
					}
					else if (local_u8KeypadValue=='2')
					{
						MDIO_voidSetPortValue(PORTB,0b00000011);
					}
					else if (local_u8KeypadValue=='1')
					{
						MDIO_voidSetPortValue(PORTB,0b00000001);
					}
					else if (local_u8KeypadValue=='0')
					{
						MDIO_voidSetPortValue(PORTB,0b00000000);
					}
				}
			}
}

