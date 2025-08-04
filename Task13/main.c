/*
 * main.c
 *
 *  Created on: Aug 4, 2025
 *      Author: Hamdi Emad Hamdi
 */

#include "STD_TYPES.h"
#include "BIT_MATH.H"

#include "LED_interface.h"
#include "SSD_interface.h"

#include "util/delay.h"

int main()
{
	LED_Type RED = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
	LED_Type YELLOW = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};
	LED_Type GREEN = {LED_PORTA, LED_PIN2, ACTIVE_HIGH};

	LED_voidInit(RED);
	LED_voidInit(YELLOW);
	LED_voidInit(GREEN);

	SSD_Type tens = {SSD_COMMON_ANODE, SSD_PORTC, SSD_PORTD, SSD_PIN0};
	SSD_Type units = {SSD_COMMON_ANODE, SSD_PORTC, SSD_PORTD, SSD_PIN1};

	SSD_voidInitialDataPort(units);

	while (1)
	{
		LED_voidOn(RED);
		SSD_voidCount(units, tens, 15, SSD_DOWN);
		LED_voidOff(RED);

		LED_voidOn(YELLOW);
		SSD_voidCount(units, tens, 5, SSD_DOWN);
		LED_voidOff(YELLOW);

		LED_voidOn(GREEN);
		SSD_voidCount(units, tens, 10, SSD_DOWN);
		LED_voidOff(GREEN);
	}
}
