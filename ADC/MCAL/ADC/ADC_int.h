/*
 * ADC_int.h
 *
 *  Created on: Jul 5, 2022
 *      Author: mazen
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define CHANNEL_00		0
#define CHANNEL_01		1
#define CHANNEL_02		2
#define CHANNEL_03		3
#define CHANNEL_04		4
#define CHANNEL_05		5
#define CHANNEL_06		6
#define CHANNEL_07		7




void MADC_vInit(void);
u16  MADC_u16AnalogRead(u8 A_u8ChannelNo );




#endif /* MCAL_ADC_ADC_INT_H_ */
