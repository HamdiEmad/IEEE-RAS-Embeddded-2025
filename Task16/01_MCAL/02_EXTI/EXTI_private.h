/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR_REG *((volatile u8 *)0x5B)
#define GIFR_REG *((volatile u8 *)0x5A)
#define MCUCR_REG *((volatile u8 *)0x55)
#define MCUCSR_REG *((volatile u8 *)0x54)
#define SREG_REG  *((volatile u8 *) 0x5F)

#define NULL 0

#endif
