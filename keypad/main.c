/*******************************************************************************************
* ! Title : Keypad Program
* ! File Name : main.c
* ! Description : This file has the implementation code for controlling the keypad device
* ! Version : V1.0
********************************************************************************************/
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char         u8;
typedef unsigned short int    u16;
typedef unsigned long int     u32;

typedef signed char           s8;
typedef signed short int      s16;
typedef signed long int       s32;

typedef float                 f32;
typedef double                f64;

//Definition for returning non pressed value
#define KEYPAD_U8_KEY_NOT_PRESSED  0xFF
#define KEYPAD_U8_KEY_FLAG_UP      1
#define KEYPAD_U8_KEY_FLAG_DOWN    0

//Definition for Keypad Dimensions
#define KEYPAD_8u_ROW_NUM          4
#define KEYPAD_8u_COL_NUM          4

#define SET_BIT(Reg, bitNum)       (Reg |= 1 << bitNum)
#define CLR_BIT(Reg, bitNum)       (Reg &= ~(1 << bitNum))
#define TOGGLE_BIT(Reg, bitNum)    (Reg ^= (1 << bitNum))
#define GET_BIT(Reg, bitNum)       ((Reg >> bitNum) & 0x01)
#define SET_BYTE(Reg,value)        ( Reg =  value )

unsigned char KEYPAD_Au8Keys[4][4] = {{'7', '8', '9', '/'},
		                              {'4', '5', '6', '*'},
		                              {'1', '2', '3', '-'},
		                              {'7', '8', '9', '+'}};


unsigned char HKEYPAD_u8_GetPressed_Key(void)
{
	unsigned char local_u8RowCounter,
	              local_u8ColCounter,
				  local_u8PinValue  ,
				  local_u8KeyValue = KEYPAD_U8_KEY_NOT_PRESSED;
	unsigned char local_u8Flag = KEYPAD_U8_KEY_FLAG_DOWN;

	for(local_u8RowCounter = 0 ; local_u8RowCounter < KEYPAD_8u_ROW_NUM ; local_u8RowCounter++)
	{
		CLR_BIT(PORTC, local_u8RowCounter);
		for(local_u8ColCounter = 0 ; local_u8ColCounter < KEYPAD_8u_COL_NUM ; local_u8ColCounter++)
		{
			local_u8PinValue = GET_BIT(PINC, (local_u8ColCounter + 4));
			if(local_u8PinValue == 0)
			{
				_delay_ms(100);
				local_u8PinValue = GET_BIT(PINC, (local_u8ColCounter + 4));

				//to prevent repeated number
				while(local_u8PinValue == 0)
				{
					local_u8PinValue = GET_BIT(PINC, (local_u8ColCounter + 4));
				}
				local_u8KeyValue = KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];
				local_u8Flag = KEYPAD_U8_KEY_FLAG_UP;
				break;
			}

		}
		SET_BIT(PORTC, local_u8RowCounter);
		if(local_u8Flag == KEYPAD_U8_KEY_FLAG_UP)
		{
			break;
		}
	}


}



void main (void)
{
	DDRC = 0x0F;
	DDRB = 0xFF;

	PORTC = 0xFF;

	unsigned char local_u8KeypadValue;
	while(1)
	{
		local_u8KeypadValue = HKEYPAD_u8_GetPressed_Key();
		if(local_u8KeypadValue != KEYPAD_U8_KEY_NOT_PRESSED)
		{
			if(local_u8KeypadValue      == '8')
			{
				PORTB = 0xFF;
			}
			else if(local_u8KeypadValue == '7')
			{
				PORTB = 0b01111111;
			}
			else if(local_u8KeypadValue == '6')
			{
				 PORTB = 0b00111111;
			}
			else if(local_u8KeypadValue == '5')
			{
				PORTB = 0b00011111;
			}
			else if(local_u8KeypadValue == '4')
			{
				PORTB = 0b00001111;
			}
			else if(local_u8KeypadValue == '3')
			{
				PORTB = 0b00000111;
			}
			else if(local_u8KeypadValue == '2')
			{
				PORTB = 0b00000011;
			}
			else if(local_u8KeypadValue == '1')
			{
				PORTB = 0b00000001;
			}
			else if(local_u8KeypadValue == '0')
			{
				PORTB = 0b00000000;
			}
		}
	}
}

