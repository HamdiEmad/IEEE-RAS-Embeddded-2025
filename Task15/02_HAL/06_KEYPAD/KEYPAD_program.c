/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   KEYPAD_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : KEYPAD
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

void KEYPAD_Init(void)
{
    DIO_enumConnectPullup(KEYPAD_PORT, KEYPAD_R0, DIO_PIN_HIGH);
    DIO_enumConnectPullup(KEYPAD_PORT, KEYPAD_R1, DIO_PIN_HIGH);
    DIO_enumConnectPullup(KEYPAD_PORT, KEYPAD_R2, DIO_PIN_HIGH);
    DIO_enumConnectPullup(KEYPAD_PORT, KEYPAD_R3, DIO_PIN_HIGH);

    DIO_enumSetPinDirection(KEYPAD_PORT, KEYPAD_C0, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(KEYPAD_PORT, KEYPAD_C1, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(KEYPAD_PORT, KEYPAD_C2, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(KEYPAD_PORT, KEYPAD_C3, DIO_PIN_OUTPUT);

    DIO_enumSetPinValue(KEYPAD_PORT, KEYPAD_C0, DIO_PIN_HIGH);
    DIO_enumSetPinValue(KEYPAD_PORT, KEYPAD_C1, DIO_PIN_HIGH);
    DIO_enumSetPinValue(KEYPAD_PORT, KEYPAD_C2, DIO_PIN_HIGH);
    DIO_enumSetPinValue(KEYPAD_PORT, KEYPAD_C3, DIO_PIN_HIGH);
}

u8 KEYPAD_u8GetPressed(void)
{

    u8 LOC_u8ReturnData = NOTPRESSED;
    u8 LOC_u8GetPressed;
    u8 LOC_u8Row;
    u8 LOC_u8Col;

    for (LOC_u8Col = 0 + KEYPAD_COL_INIT; LOC_u8Col < KEYPAD_COL_END + 1; LOC_u8Col++)
    {

        DIO_enumSetPinValue(KEYPAD_PORT, LOC_u8Col, DIO_PIN_LOW);

        for (LOC_u8Row = 0 + KEYPAD_ROW_INIT; LOC_u8Row < KEYPAD_ROW_END + 1; LOC_u8Row++)
        {

            DIO_enumGetPinValue(KEYPAD_PORT, LOC_u8Row, &LOC_u8GetPressed);
            if (LOC_u8GetPressed == 0)
            {

                _delay_ms(50);

                DIO_enumGetPinValue(KEYPAD_PORT, LOC_u8Row, &LOC_u8GetPressed);

                if (LOC_u8GetPressed == 0)

                {

                    LOC_u8ReturnData = KEYPAD_u8Buttons[LOC_u8Row - KEYPAD_ROW_INIT][LOC_u8Col - KEYPAD_COL_INIT];
                }

                DIO_enumGetPinValue(KEYPAD_PORT, LOC_u8Row, &LOC_u8GetPressed);
                while (DIO_PIN_LOW == LOC_u8GetPressed)
                {
                    DIO_enumGetPinValue(KEYPAD_PORT, LOC_u8Row, &LOC_u8GetPressed);
                }
                break;
            }
        }
        DIO_enumSetPinValue(KEYPAD_PORT, LOC_u8Col, DIO_PIN_HIGH);
    }
    return LOC_u8ReturnData;
}
