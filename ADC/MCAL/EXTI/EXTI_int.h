/*
 * EXTI_int.h
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_


void MEXTI_vInit(void);
void MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo);
void MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo);
void MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo, u8 A_u8SenseCtrl);



#endif /* MCAL_EXTI_EXTI_INT_H_ */
