/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/ADC_int.h"

#include <util/delay.h>

int main(void)
{
	MADC_vInit();
	HLCD_vInit();

	u16 adc_value = 0 ;


	while(1)
	{

		adc_value = MADC_u16AnalogRead(CHANNEL_03);

		HLCD_vSendCommand(LCD_CLEAR);

		HLCD_vPrintNumber(adc_value);

		_delay_ms(250);

	}
}
