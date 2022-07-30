/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

/*
 * LCD_Program.c
 *
 *  Created on: May 19, 2022
 *      Author: abdelrahmanhossam
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

#define MAX_IDX_OF_ROWS 1
#define MAX_IDX_OF_COL  15
#define FIRST_ROW_IDX   0
#define FIRST_ROW_START 0x00
#define SEC_ROW_START   0x40
#define SET_AC_MASK     0x80

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


void HLCD_voidGoTo(u8 A_u8Row,u8 A_u8Col)
{
	u8 L_u8DdramAddress;
	u8 L_u8Command;

	/* Valid Range */
	if ( (A_u8Row <= MAX_IDX_OF_ROWS) && (A_u8Col <= MAX_IDX_OF_COL) )
	{
		if (A_u8Row == FIRST_ROW_IDX)
		{
			L_u8DdramAddress = FIRST_ROW_START + A_u8Col;
		}

		else
		{
			L_u8DdramAddress = SEC_ROW_START + A_u8Col;
		}

		L_u8Command = L_u8DdramAddress | SET_AC_MASK;

		HLCD_voidSendCommand(L_u8Command);
	}

	else
	{
		/* Do Nothing */
	}
}


void HLCD_voidWriteCGRAM ( u8 A_u8PatternIdx, u8 *A_u8PatternValue)
{
	u8 L_u8LoopIterator;

	/* Step 1: Set AC on CGRAM */
	switch (A_u8PatternIdx)
	{
		case 0  : HLCD_voidSendCommand(0x40); break;
		case 1  : HLCD_voidSendCommand(0x48); break;
	 // default : /* Report Error */        ; break;
	}

	/* Step 2: Write pattern  */
	for (L_u8LoopIterator =0; L_u8LoopIterator<8;L_u8LoopIterator++)
	{
		HLCD_voidSendData(A_u8PatternValue[L_u8LoopIterator]);
	}
}



void main (void)
{

	u8 G_u8Custom1[] = {0x10, 0x14, 0x11, 0x1F, 0x00, 0x00, 0x00, 0x00};
	u8 G_u8Custom2[] = {0x00, 0x00, 0x00, 0x01, 0x01, 0x1F, 0x00, 0x00};
	u8 G_u8Custom3[] = {0x00, 0x00, 0x01, 0x1F, 0x00, 0x0A, 0x00, 0x00};
	u8 G_u8Custom4[] = {0x10, 0x10, 0x17, 0x1D, 0x07, 0x00, 0x00, 0x00};
	u8 G_u8Custom5[] = {0x00, 0x04, 0x11, 0x1F, 0x00, 0x00, 0x00, 0x00};

	MDIO_voidSetPortDirection(PORTD,0xFF);
	MDIO_voidSetPortDirection(PORTA,0xFF);

	HLCD_voidInit();

	HLCD_voidWriteCGRAM(0,G_u8Custom1);
	HLCD_voidWriteCGRAM(1,G_u8Custom2);
	HLCD_voidWriteCGRAM(2,G_u8Custom3);
	HLCD_voidWriteCGRAM(3,G_u8Custom4);
	HLCD_voidWriteCGRAM(4,G_u8Custom5);


	HLCD_voidGoTo (0,10);
	HLCD_voidSendData(0); /* draw 7rf el noon */

	HLCD_voidGoTo (0,9);
	HLCD_voidSendData(1); /* draw 7rf el alf */

	HLCD_voidGoTo (0,8);
	HLCD_voidSendData(2); /* draw 7rf el raa */

	HLCD_voidGoTo (0,7);
	HLCD_voidSendData(3); /* draw 7rf el yaa */

	HLCD_voidGoTo (0,6);
	HLCD_voidSendData(4); /* draw 7rf el meem */




	//HLCD_voidSendString("Nariman");
	//HLCD_voidGoToPosition(LCD_LINE_2,1);
	//HLCD_voidDisplayNumber(-537);
	while(1){

	}
}
