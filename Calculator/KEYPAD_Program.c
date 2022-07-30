/*
 * KEYPAD_Program.c
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


u8 KEYPAD_Au8Keys[KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM]=	{{'7','8','9','/'},
															 {'4','5','6','*'},
															 {'1','2','3','-'},
															 {'c','0','=','+'}};

	// Row output
	// Col Input pull-up
u8 HKEYPAD_u8GetPressedKey (void)
{
	u8 local_u8RowCounter,local_u8ColCounter,local_u8PinValue, local_u8KeyValue=KEYPAD_u8_KEY_NOT_PRESSED;
	u8 local_u8Flag=KEYPAD_u8_FLAG_DOWN;
	for (local_u8RowCounter=0; local_u8RowCounter<KEYPAD_u8_ROW_NUM;local_u8RowCounter++)
	{
		MDIO_voidSetPinValue(KEYPAD_PORT, local_u8RowCounter, LOW);

		for (local_u8ColCounter=0;local_u8ColCounter<KEYPAD_u8_COL_NUM;local_u8ColCounter++)
		{
			local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, (local_u8ColCounter+4));
			if (local_u8PinValue==0)
			{
				_delay_ms(20);
				local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, (local_u8ColCounter+4));
				while(local_u8PinValue==0)
				{
					local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, (local_u8ColCounter+4));
				}
				local_u8KeyValue=KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];
				local_u8Flag=KEYPAD_u8_FLAG_UP;
				break;
			}
		}
		MDIO_voidSetPinValue(KEYPAD_PORT, local_u8RowCounter, HIGH);
		if (local_u8Flag==KEYPAD_u8_FLAG_UP)
		{
			break;
		}

	}

	return local_u8KeyValue;
}


