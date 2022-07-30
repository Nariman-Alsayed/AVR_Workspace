/*
 * DC_Motor_Program.c
 *
 *  Created on: May 31, 2022
 *      Author: abdelrahmanhossam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DC_Motor_Interface.h"
#include <util/delay.h>

#define F_CPU 8000000UL

#define DC_MOTOR_PORT     PORTA
#define DC_MOTOR_PIN1	  PIN0
#define DC_MOTOR_PIN2	  PIN1

void HDCMOTOTR_voidInit (void)
{
	MDIO_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1, OUTPUT);
	MDIO_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2, OUTPUT);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOW); // To ensure that is low
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOW); // To ensure that is low
}

/* Depend on H.W. connections....PIN1 is right and PIN2 is left */
void HDCMOTOR_voidRotateClockWise(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOW);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, HIGH);
}

void HDCMOTOR_voidCounterRotateClockWise(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOW);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, HIGH);
}

void HDCMOTOR_voidStop(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOW);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOW);
}


