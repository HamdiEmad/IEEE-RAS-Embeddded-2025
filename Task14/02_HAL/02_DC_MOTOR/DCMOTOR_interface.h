/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : HAL
 *  SWC    : DC_MOTOR
 *
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#define DCMOTOR_FOR 0
#define DCMOTOR_BACK 1
#define DCMOTOR_STOP 2

typedef struct
{
    u8 Copy_u8DcMotorPort;
    u8 Copy_u8DcMotorPinA;
    u8 Copy_u8DcMotorPinB;
} DCMOTOR_CONFIG;

u8 DCMOTOR_u8Control(DCMOTOR_CONFIG *DcMotor, u8 Copy_u8State);

#endif
