/*
 * LCD_Program.c
 *
 *  Created on: May 23, 2022
 *      Author: User
 */

#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include <util/delay.h>

#define FUNCTION_SET    0b00111100
#define DISPLAY_CONTROL 0b00001100
#define DISPLAY_CLEAR   0b00000001
#define ENTRY_MODE_SET  0b00000110

#define LCD_ROW_1   127
#define LCD_ROW_2   191

void HLCD_voidSendCommand(u8 A_u8Cmd)
{
	/* Control RS and RW Pins */
	MDIO_voidSetPinValue(CONTROL_PORT,PIN0,LOW);
	MDIO_voidSetPinValue(CONTROL_PORT,PIN1,LOW);

	/* Write Command on the data pins */
	MDIO_voidSetPortValue(DATA_PORT,A_u8Cmd);

	/* Pulse on the enable pin */
	MDIO_voidSetPinValue(CONTROL_PORT,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(CONTROL_PORT,PIN2,LOW);
	_delay_ms(1);
}

void HLCD_voidSendData(u8 A_u8Data)
{
	/* Control RS and RW Pins */
	MDIO_voidSetPinValue(CONTROL_PORT,PIN0,HIGH);
	MDIO_voidSetPinValue(CONTROL_PORT,PIN1,LOW);

	/* Write Command on the data pins */
	MDIO_voidSetPortValue(DATA_PORT,A_u8Data);

	/* Pulse on the enable pin */
	MDIO_voidSetPinValue(CONTROL_PORT,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(CONTROL_PORT,PIN2,LOW);
	_delay_ms(1);
}

void HLCD_voidInit(void)
{
	//wait for more than 30ms
	_delay_ms(30);

	//Function Set 0b00111100
	HLCD_voidSendCommand(FUNCTION_SET);

	//wait for more than 39 us
	_delay_ms(1);

	//Display ON/OFF Control 0b00001100
	HLCD_voidSendCommand(DISPLAY_CONTROL);

	//wait for more than 39 us
	_delay_ms(1);

	//Display Clear 0b00000001
	HLCD_voidSendCommand(DISPLAY_CLEAR);

	//wait for more than 1.53 ms
	_delay_ms(2);

	// Entry Mode Set 0b00000110
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}

void HLCD_voidClearDisplay(void)
{
	//Display Clear 0b00000001
	HLCD_voidSendCommand(DISPLAY_CLEAR);

	//wait for more than 1.53 ms
	_delay_ms(2);
}


void HLCD_voidSendString(u8 *A_u8PtrString)
{
	while (*A_u8PtrString > 0) // Check end of string
	{
		// Send Char then Move Pointer to next Char
		HLCD_voidSendData(*A_u8PtrString++);
	}
}




void HLCD_voidGoToPosition(u8 A_u8RowNum,u8 A_u8ColNum)
{
	switch (A_u8RowNum)
	{
	case LCD_LINE_1: HLCD_voidSendCommand(LCD_ROW_1+A_u8ColNum); break;
	case LCD_LINE_2: HLCD_voidSendCommand(LCD_ROW_2+A_u8ColNum); break;
	}
	//wait for more than 39 usec
	_delay_ms(1);
}

void HLCD_voidDisplayNumber(s32 A_s32Number)
{
	u32 local_u32Number=1;
	if (A_s32Number==0)
	{
		HLCD_voidSendData('0');
	}
	if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number *=-1;
	}
	while (A_s32Number!=0)
	{
		local_u32Number = ((local_u32Number * 10)+(A_s32Number % 10));
		A_s32Number = A_s32Number /10;
	}
	while (local_u32Number!=1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number=local_u32Number/10;
	}
}

void main (void)
{
	MDIO_voidSetPortDirection(PORTD, 0xFF);
	MDIO_voidSetPortDirection(PORTA, 0xFF);


	HLCD_voidInit();

	HLCD_voidSendString("Abdelrahman");
	HLCD_voidGoToPosition(LCD_LINE_2,1);
	//HLCD_voidDisplayNumber(-537);
	while(1){

	}
}


