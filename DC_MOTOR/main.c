/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: User
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DC_Motor_Interface.h"
#include "util/delay.h"


void main (void)
{


	 while (1)
	 {
		 HDCMOTOR_voidRotateClockWise();
         _delay_ms(1000);
         HDCMOTOR_voidCounterRotateClockWise();
		 _delay_ms(1000);

	 }
}


