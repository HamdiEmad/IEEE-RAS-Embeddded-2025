/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_programe.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : DC_MOTOR
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DCMOTOR_interface.h"

u8 DCMOTOR_u8Control(DCMOTOR_CONFIG *DcMotor, u8 Copy_u8State)
{
	DIO_enumSetPinDirection(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, DIO_PIN_OUTPUT);

    u8 Local_u8ErrorState = DIO_OK;

    switch (Copy_u8State)
    {
    case DCMOTOR_FOR:
    		DIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, DIO_PIN_LOW);
    		DIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, DIO_PIN_HIGH);
        break;
    case DCMOTOR_BACK:
    		DIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, DIO_PIN_LOW);
    		DIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, DIO_PIN_HIGH);
        break;
    case DCMOTOR_STOP:
    		DIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, DIO_PIN_LOW);
    		DIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, DIO_PIN_LOW);
        break;
    default:
        Local_u8ErrorState = DIO_NOK;
    }

    return Local_u8ErrorState;
}
