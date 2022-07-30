/*
 * LCD_int.h
 *
 *  Created on: May 19, 2022
 *      Author: mazen
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_CLEAR		0b00000001
#define LCD_LINE0		0
#define LCD_LINE1		1

#define LCD_CTRL_PORT   DIO_PORTA
#define LCD_DATA_PORT	DIO_PORTD
#define LCD_RS_PIN 		DIO_PIN0
#define LCD_RW_PIN		DIO_PIN1
#define LCD_EN_PIN		DIO_PIN2


void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vInit(void);
void HLCD_vPrintString(u8 A_u8String[] );
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(u8 A_u8LinePos, u8 A_u8LineNo);
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex);
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_u8CustomCharData[] );



#endif /* HAL_LCD_LCD_INT_H_ */
