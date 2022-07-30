/*
 * EXTI_cfg.h
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_


#define EXTI_LINE0			ENABLE
#define EXTI_LINE1			DISABLE
#define EXTI_LINE2			DISABLE

/**
 * Options:
 * EXTI_FALLING ,
 * EXTI_RISING,
 * EXTI_ONCHANGE
 */
#define EXTI_LIN0_SENSE_CTRL  EXTI_RISING


#endif /* MCAL_EXTI_EXTI_CFG_H_ */
