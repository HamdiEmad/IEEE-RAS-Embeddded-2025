/*
 * main.c
 *
 *  Created on: Aug 25, 2025
 *      Author: hamdy
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"

int main() {
	u8 end = 0;
	LED_Type LEDs[8];
	for (u8 i = 0; i < 8; i++) {
		LEDs[i].Port = DIO_PORTB;
		LEDs[i].Pin = i;
		LEDs[i].Active_State = ACTIVE_HIGH;
		LED_voidInit(LEDs[i]);
	}

	LCD_voidInit();
	LCD_voidSendString("    ADC TEST");

	u16 POT_value = 0, percentage = 0;
	char value[7], prc[7];
	ADC_voidInit();

	while (1) {
		LCD_voidSetPosition(2, 1);
		ADC_u8GetResultSync(ADC_CHANNEL0, &POT_value);
		sprintf(value, "%d", POT_value);
		strcat(value, "  ");
		LCD_voidSendString(value);

		LCD_voidSetPosition(2, 11);
		percentage = (POT_value / 1023.0) * 100;
		sprintf(prc, "%d", percentage);
		strcat(prc, "% ");
		LCD_voidSendString(prc);

		if (POT_value >= 7 * 1023 / 8)
			end = 8;

		else if (POT_value >= 6 * 1023 / 8 && POT_value < 7 * 1023 / 8)
			end = 7;

		else if (POT_value >= 5 * 1023 / 8 && POT_value < 6 * 1023 / 8)
			end = 6;

		else if (POT_value >= 4 * 1023 / 8 && POT_value < 5 * 1023 / 8)
			end = 5;

		else if (POT_value >= 3 * 1023 / 8 && POT_value < 4 * 1023 / 8)
			end = 4;

		else if (POT_value >= 2 * 1023 / 8 && POT_value < 3 * 1023 / 8)
			end = 3;

		else if (POT_value >= 1 * 1023 / 8 && POT_value < 2 * 1023 / 8)
			end = 2;

		else if (POT_value >=      50      && POT_value < 1 * 1023 / 8)
			end = 1;
		else if (POT_value < 50)
			end = 0;

		for (u8 i = 0; i < end; i++) {
			LED_voidOn(LEDs[i]);
		}
		for (u8 i = end; i < 8; i++) {
			LED_voidOff(LEDs[i]);
		}
	}
}
