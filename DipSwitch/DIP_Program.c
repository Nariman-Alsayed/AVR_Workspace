/*
 * DIP_Program.c
 *
 *  Created on: May 24, 2022
 *      Author: NarimanAlsayed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIP_Interface.h"

u8 HDIP_u8GetPinStatus (u8 A_u8PortId, u8 A_u8PinId)
{
	return MDIO_u8GetPinValue(A_u8PortId, A_u8PinId);
}

u8 HDIP_u8GetPortStatus (u8 A_u8PortId, u8 A_u8NoOfPins)
{
	u8 local_portValue = ~(MDIO_u8GetPortValue(A_u8PortId)) ;
	local_portValue = local_portValue & (~(0xFF<<A_u8NoOfPins));
	return local_portValue;
}



void main(void)
{
	u8 L_u8Dip;
	MDIO_voidSetPortDirection(PORTA, 0xFF);
	MDIO_voidSetPortValue(PORTA, 0xFF);
	while(1)
	{

	}
}
