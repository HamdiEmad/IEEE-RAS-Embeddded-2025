/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_register.h / ADC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_PRE_MASK 0b11111000
#define ADC_CH_MASK 0b11100000

#define ADMUX *((volatile u8 *)0x27)

#define ADMUX_REFS1 7
#define ADMUX_REFS0 6
#define ADMUX_ADLAR 5

#define ADCSRA  *((volatile u8 *)0x26)

#define ADCSRA_ADEN  7
#define ADCSRA_ADSC  6
#define ADCSRA_ADATE 5
#define ADCSRA_ADIF  4
#define ADCSRA_ADIE  3
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0

#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)
#define ADC_DATA_RE *((volatile u16 *)0x24)

#define SFIOR *((volatile u8 *)0x50)

#define SFIOR_ADTS2 7
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5

#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH 1

#endif
