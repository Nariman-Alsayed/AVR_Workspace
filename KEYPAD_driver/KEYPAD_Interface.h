/*
 * KEYPAD_Interface.h
 *
 *  Created on: May 19, 2022
 *      Author: NarimanAlsayed
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


/* Definition for returning non pressed value */
#define KEYPAD_u8_KEY_NOT_PRESSED   255
#define KEYPAD_u8_FLAG_UP    1
#define KEYPAD_u8_FLAG_DOWN  0

/* Definition For Keypad Dimensions*/
#define KEYPAD_u8_ROW_NUM     4
#define KEYPAD_u8_COL_NUM     4

#define KEYPAD_PORT PORTC




	// Row output
	// Col Input pull-up
u8 HKEYPAD_u8GetPressedKey (void);


#endif /* KEYPAD_INTERFACE_H_ */
