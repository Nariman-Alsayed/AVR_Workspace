/*
 * ADC_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_int.h"
#include "ADC_cfg.h"

#include <avr/io.h>



void MADC_vInit(void)
{
	/* 1- Reference voltage selection */
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
	/* 2- Data Adjustment direction  */
	CLR_BIT(ADMUX, ADLAR);
	/* 3- Select Prescaler Bits    */
	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER) ;
	/* 4- Auto trigger Enable     */
	/*  4a- Select Auto trigger source  */
	CLR_BIT(ADCSRA, ADATE);
	/* 5- Interrupt Enable/disable    */
	CLR_BIT(ADCSRA, ADIE);
	/* 6- Enable ADC peripheral   */
	SET_BIT(ADCSRA, ADEN);
}

u16  MADC_u16AnalogRead(u8 A_u8ChannelNo )
{

	/* 1- Select Channel   */
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
	/* 3- Poll on Flag     */
	while( GET_BIT(ADCSRA, ADIF) != 1 ){}
	/* 4- Clear Flag       */
	SET_BIT(ADCSRA, ADIF);
	/* 5- return ADC Data  */
	return ADC;
}
