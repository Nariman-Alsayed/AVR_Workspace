/*
 * EXTI_Interface.h
 *
 *  Created on: Jun 2, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_LINE0		  0
#define EXTI_LINE1		  1
#define EXTI_LINE2		  2

#define EXTI_LOWLEVEL     0
#define EXTI_ONCHANGE     1
#define EXTI_FALLING      2
#define EXTI_RISING	      3

void MEXTI_voidSenseControl (u8 A_u8EXTI_Line, u8 A_u8EXTI_Sense);
void MEXTI_voidEnable (u8 A_u8EXTI_Line);
void MEXTI_voidDisable (u8 A_u8EXTI_Line);


#endif /* EXTI_INTERFACE_H_ */
