/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

/*
 * LCD_Interface.h
 *
 *  Created on: May 19, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define DATA_PORT	  PORTD
#define CONTROL_PORT  PORTA

#define LCD_LINE_1  1
#define LCD_LINE_2  2

void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidSendCommand(u8 A_u8Cmd);
void HLCD_voidInit(void);
void HLCD_voidSendString(u8 *A_u8PtrString);
void HLCD_voidClearDisplay(void);
void HLCD_voidGoToPosition(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidDisplayNumber(s32 A_s32Number);
void HLCD_voidGoTo(u8 A_u8Row,u8 A_u8Col);
void HLCD_voidWriteCGRAM ( u8 A_u8PatternIdx, u8 *A_u8PatternValue);


#endif /* LCD_INTERFACE_H_ */
