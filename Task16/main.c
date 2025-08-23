/*
 * main.c
 *
 *  Created on: Aug 18, 2025
 *      Author: hamdy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include <avr/interrupt.h>

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"
#include "EXTI_interface.h"

#include "util/delay.h"
	LED_Type LED = {DIO_PORTD, DIO_PIN7, ACTIVE_HIGH};
	SSD_Type SSD = {SSD_COMMON_ANODE, DIO_PORTC, DIO_PORTD, DIO_PIN0};

void Interrupt(void);

int main (){

	SW_Type LED_Toggle_SW = {DIO_PORTD, DIO_PIN2, SW_INPUT_PULL_UP};
	SW_Type SSD_Reset_SW = {DIO_PORTD, DIO_PIN3, SW_INPUT_PULL_UP};

	LED_voidInit(LED);
	LED_voidOn(LED);

	SSD_voidInitialDataPort(SSD);

	SW_voidInit(LED_Toggle_SW);
	SW_voidInit(SSD_Reset_SW);

	EXTI_voidInit();
	EXTI_voidSetCallBack(Interrupt, EXTI_LINE0);
	GIE_voidEnable();
	EXTI_voidEnableInterrupt(EXTI_LINE0);


	while (1) {
		SSD_voidCount(SSD, 9, SSD_UP);
	}
}

void Interrupt(void) {
	LED_voidToggle(LED);
	SSD_voidReset(SSD, SSD_UP, 9);
}

