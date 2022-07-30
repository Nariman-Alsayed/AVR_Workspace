/*
 * main.c
 *
 *  Created on: May 23, 2022
 *      Author: User
 */
/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: abdelrahmanhossam
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


	u8 G_u8Custom1[] = {0x10, 0x14, 0x11, 0x1F, 0x00, 0x00, 0x00, 0x00};
	u8 G_u8Custom2[] = {0x00, 0x00, 0x00, 0x01, 0x01, 0x1F, 0x00, 0x00};
	u8 G_u8Custom3[] = {0x00, 0x00, 0x01, 0x1F, 0x00, 0x0A, 0x00, 0x00};
	u8 G_u8Custom4[] = {0x10, 0x10, 0x17, 0x1D, 0x07, 0x00, 0x00, 0x00};
	u8 G_u8Custom5[] = {0x00, 0x04, 0x11, 0x1F, 0x00, 0x00, 0x00, 0x00};

	MDIO_voidSetPortDirection(PORTD,0xFF);
	MDIO_voidSetPortDirection(PORTA,0xFF);


	MDIO_voidSetPortDirection(PORTC, 0x0F);
	MDIO_voidSetPortDirection(PORTB, 0xFF);
	MDIO_voidSetPortValue(PORTC,0xFF);

	u8 local_u8KeypadValue=255;

	HLCD_voidInit();

	HLCD_voidWriteCGRAM(0,G_u8Custom1);
	HLCD_voidWriteCGRAM(1,G_u8Custom2);
	HLCD_voidWriteCGRAM(2,G_u8Custom3);
	HLCD_voidWriteCGRAM(3,G_u8Custom4);
	HLCD_voidWriteCGRAM(4,G_u8Custom5);

			while(1)
			{
				local_u8KeypadValue = HKEYPAD_u8GetPressedKey();
				if (local_u8KeypadValue != KEYPAD_u8_KEY_NOT_PRESSED)
				{
					if (local_u8KeypadValue=='8')
					{
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
					}
					else if (local_u8KeypadValue=='7')
					{
						HLCD_voidGoTo (1,10);
						HLCD_voidSendData(0); /* draw 7rf el noon */

						HLCD_voidGoTo (1,9);
						HLCD_voidSendData(1); /* draw 7rf el alf */

						HLCD_voidGoTo (1,8);
						HLCD_voidSendData(2); /* draw 7rf el raa */

						HLCD_voidGoTo (1,7);
						HLCD_voidSendData(3); /* draw 7rf el yaa */

						HLCD_voidGoTo (1,6);
						HLCD_voidSendData(4); /* draw 7rf el meem */
					}

				}
			}
}


