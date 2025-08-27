/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hamdi Emad Hamdi
 *  Layer   : MCAL
 *  SWC     : ADC
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stdio.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

static u16 *ADC_pu16AsynchConversionResult = NULL;
static void (*ADC_pvNotificationFunc)(void) = NULL;
static u8 ADC_u8ISRState;
static u8 *ADC_pu8ChainChannel;
static u8 ADC_u8ChainSize;
static u8 ADC_u8Index;
static u8 ADC_u8State = IDLE;

void ADC_voidInit(void)
{
#if ADC_VREF == AREF
    CLR_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);

#elif ADC_VREF == AVCC
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);

#elif ADC_VREF == INTERNAL_2_56
    SET_BIT(ADMUX, ADMUX_REFS0);
    SET_BIT(ADMUX, ADMUX_REFS1);

#else
#error "Wrong ADC_VREF config"

#endif
#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
    CLR_BIT(ADMUX, ADMUX_ADLAR);

#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
    SET_BIT(ADMUX, ADMUX_ADLAR);

#else
#error "Wrong ADC_ADJUSTMENT config"

#endif
    ADCSRA &= ADC_PRE_MASK;
    ADCSRA |= ADC_PRESCALLER;
#if ADC_STATUS == ADC_DISABLE
    CLR_BIT(ADSAR, ADCSRA_ADEN);
#elif ADC_STATUS == ADC_ENABLE
    SET_BIT(ADCSRA, ADCSRA_ADEN);
#else
#error "Wrong ADC_STATUS config"
#endif

#if INT_STATUS == INT_DISABLE
    CLR_BIT(ADCSRA, ADCSRA_ADIE);
#elif INT_STATUS == INT_ENABLE
    SET_BIT(ADCSRA, ADCSRA_ADIE);
#else
#error "Wrong INT_STATUS config"
#endif
}

void ADC_voidEnable(void)
{
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

void ADC_voidDisable(void)
{
    CLR_BIT(ADCSRA, ADCSRA_ADEN);
}

void ADC_voidInterruptEnable(void)
{
    SET_BIT(ADCSRA, ADCSRA_ADIE);
}

void ADC_voidInterruptDisable(void)
{
    CLR_BIT(ADCSRA, ADCSRA_ADIE);
}

u8 ADC_u8SetPrescaler(u8 Copy_u8Prescaler)
{
    u8 Local_u8ErrorState = OK;

    if (Copy_u8Prescaler < 8)
    {
    	    ADCSRA &= ADC_PRE_MASK;
    	    ADCSRA |= Copy_u8Prescaler;
    }

    return Local_u8ErrorState;
}

u8 ADC_u8GetResultSync(u8 Copy_u8Channel, u16 *Copy_pu16Result)
{
    u8 Local_u8ErrorState = OK;
    u32 Local_u32TimeoutCounter = 0;
    if (Copy_pu16Result != NULL)
    {
        if (ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;
            ADMUX &= ADC_CH_MASK;
            ADMUX |= Copy_u8Channel;
            SET_BIT(ADCSRA, ADCSRA_ADSC);
            while (((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
            {
                Local_u32TimeoutCounter++;
            }
            if (Local_u32TimeoutCounter == ADC_TIMEOUT)
            {
                Local_u8ErrorState = TIMEOUT_STATE;
            }
            else
            {
                SET_BIT(ADCSRA, ADCSRA_ADIF);
#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
                *Copy_pu16Result = (ADCL | (ADCH << 8));

#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
                *Copy_pu16Result = ADCH;
#else
#error "Wrong ADC_ADJUSTMENT config"

#endif
            }
            ADC_u8State = IDLE;
        }
        else
        {
            Local_u8ErrorState = BUSY_STATE;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_pu16Result, void (*Copy_pvNotificationFunc)(void))
{
    u8 Local_u8ErrorState = OK;
    if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
    {
        if (ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;
            ADC_u8ISRState = SINGLE_CHANNEL_ASYNCH;
            ADC_pu16AsynchConversionResult = Copy_pu16Result;
            ADC_pvNotificationFunc = Copy_pvNotificationFunc;
            ADMUX &= ADC_CH_MASK;
            ADMUX |= Copy_u8Channel;
            SET_BIT(ADCSRA, ADCSRA_ADSC);
            SET_BIT(ADCSRA, ADCSRA_ADIE);
        }
        else
        {
            Local_u8ErrorState = BUSY_STATE;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }

    return Local_u8ErrorState;
}

u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain)
{
    u8 Local_u8ErrorState = OK;

    if ((Copy_Chain != NULL) && (Copy_Chain->Channel != NULL) && (Copy_Chain->NotificationFunc != NULL) && (Copy_Chain->Result))
    {
        if (ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;
            ADC_u8ISRState = CHAIN_CHANNEL_ASYNCH;
            ADC_pu16AsynchConversionResult = Copy_Chain->Result;
            ADC_pu8ChainChannel = Copy_Chain->Channel;
            ADC_u8ChainSize = Copy_Chain->Size;
            ADC_pvNotificationFunc = Copy_Chain->NotificationFunc;
            ADC_u8Index = 0;
            ADMUX &= ADC_CH_MASK;
            ADMUX |= ADC_pu8ChainChannel[ADC_u8Index];
            SET_BIT(ADCSRA, ADCSRA_ADSC);
            SET_BIT(ADCSRA, ADCSRA_ADIE);
        }
        else
        {
            Local_u8ErrorState = BUSY_STATE;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    if (ADC_u8ISRState == SINGLE_CHANNEL_ASYNCH)
    {
#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        *ADC_pu16AsynchConversionResult = (ADCL | (ADCH << 8));

#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        *ADC_pu16AsynchConversionResult = ADCH;
#else
#error "Wrong ADC_ADJUSTMENT config"

#endif
        ADC_u8State = IDLE;
        ADC_pvNotificationFunc();
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    }
    else
    {
#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        *ADC_pu16AsynchConversionResult = (ADCL | (ADCH << 8));

#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        *ADC_pu16AsynchConversionResult = ADCH;
#else
#error "Wrong ADC_ADJUSTMENT config"

#endif
        ADC_u8Index++;

        if (ADC_u8Index == ADC_u8ChainSize)
        {
            ADC_u8State = IDLE;
            ADC_pvNotificationFunc();
            CLR_BIT(ADCSRA, ADCSRA_ADIE);
        }
        else
        {
            ADMUX &= ADC_CH_MASK;
            ADMUX |= ADC_pu8ChainChannel[ADC_u8Index];

            SET_BIT(ADCSRA, ADCSRA_ADSC);
        }
    }
}
