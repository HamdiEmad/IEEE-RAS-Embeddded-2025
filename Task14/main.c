/*
 * main.c
 *
 *  Created on: Aug 8, 2025
 *      Author: Hamdi Emad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.H"

#include "DIO_interface.h"
#include "SW_interface.h"
#include "DCMOTOR_interface.h"

#include "util/delay.h"

int main() {
	SW_Type STOP = {DIO_PORTA, DIO_PIN0, SW_INPUT_PULL_UP};
	SW_Type FORWARD = {DIO_PORTA, DIO_PIN1, SW_INPUT_PULL_UP};
	SW_Type BACKWARD = {DIO_PORTA, DIO_PIN2, SW_INPUT_PULL_UP};
	SW_Type RIGHT = {DIO_PORTA, DIO_PIN3, SW_INPUT_PULL_UP};
	SW_Type LEFT = {DIO_PORTA, DIO_PIN4, SW_INPUT_PULL_UP};

	DCMOTOR_CONFIG M1 = {DIO_PORTC, DIO_PIN0, DIO_PIN1};
	DCMOTOR_CONFIG M2 = {DIO_PORTC, DIO_PIN2, DIO_PIN3};

	SW_voidInit(STOP);
	SW_voidInit(FORWARD);
	SW_voidInit(BACKWARD);
	SW_voidInit(RIGHT);
	SW_voidInit(LEFT);

	while(1) {
		if (SW_u8GetPressed(STOP)) {
			DCMOTOR_u8Control(&M1, DCMOTOR_STOP);
			DCMOTOR_u8Control(&M2, DCMOTOR_STOP);
		}

		if (SW_u8GetPressed(FORWARD)) {
			DCMOTOR_u8Control(&M1, DCMOTOR_FOR);
			DCMOTOR_u8Control(&M2, DCMOTOR_FOR);
		}

		if (SW_u8GetPressed(BACKWARD)) {
			DCMOTOR_u8Control(&M1, DCMOTOR_BACK);
			DCMOTOR_u8Control(&M2, DCMOTOR_BACK);
		}

		if (SW_u8GetPressed(RIGHT)) {
			DCMOTOR_u8Control(&M1, DCMOTOR_FOR);
			DCMOTOR_u8Control(&M2, DCMOTOR_BACK);
		}

		if (SW_u8GetPressed(LEFT)) {
			DCMOTOR_u8Control(&M1, DCMOTOR_BACK);
			DCMOTOR_u8Control(&M2, DCMOTOR_FOR);
		}

	}
}
