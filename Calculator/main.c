/*
 * main.c
 *
 *  Created on: May 22, 2022
 *      Author: NarimanAlsayed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "LCD_Interface.h"
#include "util/delay.h"
#define  F_CPU 8000000UL


void main (void)
{
	MDIO_voidSetPortDirection(PORTA, 0x0F);
	//MDIO_voidSetPortDirection(PORTB, 0xFF);
	MDIO_voidSetPortValue(PORTA,0xFF);

		u8 local_u8KeypadValue=255;
			while(1)
			{
				local_u8KeypadValue = HKEYPAD_u8GetPressedKey();
				if (local_u8KeypadValue != KEYPAD_u8_KEY_NOT_PRESSED)
				{
					HLCD_voidDisplayNumber(local_u8KeypadValue);
				}
			}
}



