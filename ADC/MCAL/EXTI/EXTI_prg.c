/*
 * EXTI_prg.c
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include <avr/io.h>
#include "../DIO/DIO_int.h"

#include "EXTI_int.h"
#include "EXTI_cfg.h"

void MEXTI_vInit(void)
{

#if EXTI_LINE0==ENABLE
	/* 1- Sense control    */
#if EXTI_LIN0_SENSE_CTRL==EXTI_FALLING
	/* Falling Edge for INT0 */
	SET_BIT(MCUCR, 3);
	CLR_BIT(MCUCR, 2);
#elif EXTI_LIN0_SENSE_CTRL==EXTI_RISING
	SET_BIT(MCUCR, 3);
	SET_BIT(MCUCR, 2);
#elif EXTI_LIN0_SENSE_CTRL==EXTI_ONCHANGE
	CLR_BIT(MCUCR, 3);
	SET_BIT(MCUCR, 2);
#else
#error "Sense Control must be Falling, Rising, ..."
#endif
	/* 2- Enable interrupt */
	SET_BIT(GICR, 6);
#endif

#if EXTI_LINE1==ENABLE
	/* 1- Sense control    */
	/* Falling Edge for INT0 */
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);
	/* 2- Enable interrupt */
	SET_BIT(GICR, 6);
#endif

#if EXTI_LINE2==ENABLE
	/* 1- Sense control    */
	/* Falling Edge for INT0 */
	SET_BIT(MCUCSR, 6);
	/* 2- Enable interrupt */
	SET_BIT(GICR, 6);
#endif



}

void MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo)
{

}

void MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo)
{

}

void MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo, u8 A_u8SenseCtrl)
{

}







