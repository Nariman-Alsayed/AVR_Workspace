/*
 * EXTI_Program.c
 *
 *  Created on: Jun 2, 2022
 *      Author: abdelrahmanhossam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "EXTI_Interface.h"


#define EXTI_MCUCR_REG    *((volatile u8 *) 0X55)
#define EXTI_MCUCSR_REG   *((volatile u8 *) 0X54)
#define EXTI_GICR_REG     *((volatile u8 *) 0X5B)
#define EXTI_GIFR_REG     *((volatile u8 *) 0X5A)




void MEXTI_voidSenseControl (u8 A_u8EXTI_Line, u8 A_u8EXTI_Sense)
{
	switch (A_u8EXTI_Line)
	{
		case EXTI_LINE0:
						switch (A_u8EXTI_Sense)
						{
							case EXTI_LOWLEVEL:
												CLR_BIT(EXTI_MCUCR_REG,0);
												CLR_BIT(EXTI_MCUCR_REG,1);
												break;
							case EXTI_ONCHANGE:
												SET_BIT(EXTI_MCUCR_REG,0);
												CLR_BIT(EXTI_MCUCR_REG,1);
												break;
							case EXTI_FALLING:
												CLR_BIT(EXTI_MCUCR_REG,0);
												SET_BIT(EXTI_MCUCR_REG,1);
												break;
							case EXTI_RISING:
												SET_BIT(EXTI_MCUCR_REG,0);
												SET_BIT(EXTI_MCUCR_REG,1);
												break;
						}
						break;
		case EXTI_LINE1:
						switch (A_u8EXTI_Sense)
						{
							case EXTI_LOWLEVEL:
												CLR_BIT(EXTI_MCUCR_REG,2);
												CLR_BIT(EXTI_MCUCR_REG,3);
												break;
							case EXTI_ONCHANGE:
												SET_BIT(EXTI_MCUCR_REG,2);
												CLR_BIT(EXTI_MCUCR_REG,3);
												break;
							case EXTI_FALLING:
												CLR_BIT(EXTI_MCUCR_REG,2);
												SET_BIT(EXTI_MCUCR_REG,3);
												break;
							case EXTI_RISING:
												SET_BIT(EXTI_MCUCR_REG,2);
												SET_BIT(EXTI_MCUCR_REG,3);
												break;
						}
						break;
		case EXTI_LINE2:
						switch (A_u8EXTI_Sense)
						{

							case EXTI_FALLING:
												CLR_BIT(EXTI_MCUCSR_REG,6);
												break;
							case EXTI_RISING:
												SET_BIT(EXTI_MCUCSR_REG,6);
												break;
						}
						break;
	}
}
void MEXTI_voidEnable (u8 A_u8EXTI_Line)
{
	switch (A_u8EXTI_Line)
		{
			case EXTI_LINE0: SET_BIT(EXTI_GICR_REG,6); break;
			case EXTI_LINE1: SET_BIT(EXTI_GICR_REG,7); break;
			case EXTI_LINE2: SET_BIT(EXTI_GICR_REG,5); break;
		}
}
void MEXTI_voidDisable (u8 A_u8EXTI_Line)
{
	switch (A_u8EXTI_Line)
			{
			case EXTI_LINE0: CLR_BIT(EXTI_GICR_REG,6); break;
			case EXTI_LINE1: CLR_BIT(EXTI_GICR_REG,7); break;
			case EXTI_LINE2: CLR_BIT(EXTI_GICR_REG,5); break;
			}
}
