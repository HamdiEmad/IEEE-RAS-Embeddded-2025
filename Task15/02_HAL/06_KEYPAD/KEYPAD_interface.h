/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KEYPAD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : KEYPAD
 *
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define NOTPRESSED 0xff

void KEYPAD_Init(void);
u8 KEYPAD_u8GetPressed(void);

#endif
