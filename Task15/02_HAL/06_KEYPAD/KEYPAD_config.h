/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KEYPAD_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : KEYPAD
 *
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_ROW_INIT DIO_PIN0
#define KEYPAD_ROW_END DIO_PIN3

#define KEYPAD_COL_INIT DIO_PIN4
#define KEYPAD_COL_END DIO_PIN7

#include "STD_TYPES.h"

u8 KEYPAD_u8Buttons[4][4] = {{'7', '8', '9', '/'},
                             {'4', '5', '6', '*'},
                             {'1', '2', '3', '-'},
                             {'?', '0', '=', '+'}};

#define KEYPAD_PORT DIO_PORTD

#define KEYPAD_R0 DIO_PIN0
#define KEYPAD_R1 DIO_PIN1
#define KEYPAD_R2 DIO_PIN2
#define KEYPAD_R3 DIO_PIN3

#define KEYPAD_C0 DIO_PIN4
#define KEYPAD_C1 DIO_PIN5
#define KEYPAD_C2 DIO_PIN6
#define KEYPAD_C3 DIO_PIN7

#endif
