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
#include "GIE_Interface.h"
#include "EXTI_Interface.h"
#include "util/delay.h"
#define F_CPU 8000000UL

void main (void)
{
	MDIO_voidSetPinDirection(PORTD,PIN2, INPUT); /* to declare INT0 */
	MDIO_voidSetPinDirection(PORTA,PIN0, OUTPUT); /* To check result of interrupt */
	MDIO_voidSetPinValue(PORTD,PIN2,HIGH);

	MGIE_voidEnable();
	MEXTI_voidSenseControl(EXTI_LINE0, EXTI_FALLING);
	MEXTI_voidEnable(EXTI_LINE0);


	 while (1)
	 {

	 }
}

volatile u8 global_u8Flag;
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
//	u8 local_u8value=MDIO_u8GetPinValue(PORTA, 0);
//	MDIO_voidSetPinValue(PORTA,PIN0,(~local_u8value));

	if (global_u8Flag==0)
	{
		MDIO_voidSetPinValue(PORTA,PIN0,LOW);
		global_u8Flag=1;
	}
	else
	{
		MDIO_voidSetPinValue(PORTA,PIN0,HIGH);
		global_u8Flag=0;
	}

}



