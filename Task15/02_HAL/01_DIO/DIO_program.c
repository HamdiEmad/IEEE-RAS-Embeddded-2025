/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Hamdi Emad Hamdi
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
    {
        if (Copy_u8Direction == DIO_PIN_OUTPUT)
        {
            switch (Copy_u8PORT)
            {
            case DIO_PORTA:
                SET_BIT(DDRA_Register, Copy_u8PIN);
                break;
            case DIO_PORTB:
                SET_BIT(DDRB_Register, Copy_u8PIN);
                break;
            case DIO_PORTC:
                SET_BIT(DDRC_Register, Copy_u8PIN);
                break;
            case DIO_PORTD:
                SET_BIT(DDRD_Register, Copy_u8PIN);
                break;
            }
        }
        else if (Copy_u8Direction == DIO_PIN_INPUT)
        {
            switch (Copy_u8PORT)
            {
            case DIO_PORTA:
                CLR_BIT(DDRA_Register, Copy_u8PIN);
                break;
            case DIO_PORTB:
                CLR_BIT(DDRB_Register, Copy_u8PIN);
                break;
            case DIO_PORTC:
                CLR_BIT(DDRC_Register, Copy_u8PIN);
                break;
            case DIO_PORTD:
                CLR_BIT(DDRD_Register, Copy_u8PIN);
                break;
            }
        }
        else
        {
            LOC_enumState = DIO_NOK;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
    {
        if (Copy_u8Value == DIO_PIN_HIGH)
        {
            switch (Copy_u8PORT)
            {
            case DIO_PORTA:
                SET_BIT(PORTA_Register, Copy_u8PIN);
                break;
            case DIO_PORTB:
                SET_BIT(PORTB_Register, Copy_u8PIN);
                break;
            case DIO_PORTC:
                SET_BIT(PORTC_Register, Copy_u8PIN);
                break;
            case DIO_PORTD:
                SET_BIT(PORTD_Register, Copy_u8PIN);
                break;
            }
        }
        else if (Copy_u8Value == DIO_PIN_LOW)
        {
            switch (Copy_u8PORT)
            {
            case DIO_PORTA:
                CLR_BIT(PORTA_Register, Copy_u8PIN);
                break;
            case DIO_PORTB:
                CLR_BIT(PORTB_Register, Copy_u8PIN);
                break;
            case DIO_PORTC:
                CLR_BIT(PORTC_Register, Copy_u8PIN);
                break;
            case DIO_PORTD:
                CLR_BIT(PORTD_Register, Copy_u8PIN);
                break;
            }
        }
        else
        {
            LOC_enumState = DIO_NOK;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumGetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 *Copy_PtrData)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
    {
        switch (Copy_u8PORT)
        {
        case DIO_PORTA:
            *Copy_PtrData = GET_BIT(PINA_Register, Copy_u8PIN);
            break;
        case DIO_PORTB:
            *Copy_PtrData = GET_BIT(PINB_Register, Copy_u8PIN);
            break;
        case DIO_PORTC:
            *Copy_PtrData = GET_BIT(PINC_Register, Copy_u8PIN);
            break;
        case DIO_PORTD:
            *Copy_PtrData = GET_BIT(PIND_Register, Copy_u8PIN);
            break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumTogglePinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;

    if (Copy_u8PIN <= DIO_PIN7)
    {
        switch (Copy_u8PORT)
        {
        case DIO_PORTA:
            TOG_BIT(PORTA_Register, Copy_u8PIN);
            break;
        case DIO_PORTB:
            TOG_BIT(PORTB_Register, Copy_u8PIN);
            break;
        case DIO_PORTC:
            TOG_BIT(PORTC_Register, Copy_u8PIN);
            break;
        case DIO_PORTD:
            TOG_BIT(PORTD_Register, Copy_u8PIN);
            break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }

    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if ((Copy_u8PORT <= DIO_PORTD))
    {
        switch (Copy_u8PORT)
        {
        case DIO_PORTA:
            DDRA_Register = Copy_u8Direction;
            break;
        case DIO_PORTB:
            DDRB_Register = Copy_u8Direction;
            break;
        case DIO_PORTC:
            DDRC_Register = Copy_u8Direction;
            break;
        case DIO_PORTD:
            DDRD_Register = Copy_u8Direction;
            break;
        default:
            LOC_enumState = DIO_NOK;
            break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if ((Copy_u8PORT <= DIO_PORTD) && ((Copy_u8Value <= 255) || (Copy_u8Value == DIO_PORT_LOW) || (Copy_u8Value == DIO_PORT_HIGH)))
    {
        switch (Copy_u8PORT)
        {
        case DIO_PORTA:
            PORTA_Register = Copy_u8Value;
            break;
        case DIO_PORTB:
            PORTB_Register = Copy_u8Value;
            break;
        case DIO_PORTC:
            PORTC_Register = Copy_u8Value;
            break;
        case DIO_PORTD:
            PORTD_Register = Copy_u8Value;
            break;
        default:
            LOC_enumState = DIO_NOK;
            break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumTogglePortValue(u8 Copy_u8PORT)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if (Copy_u8PORT <= DIO_PORTD)
    {
        switch (Copy_u8PORT)
        {
        case DIO_PORTA:
            PORTA_Register = ~PORTA_Register;
            break;
        case DIO_PORTB:
            PORTB_Register = ~PORTB_Register;
            break;
        case DIO_PORTC:
            PORTC_Register = ~PORTC_Register;
            break;
        case DIO_PORTD:
            PORTD_Register = ~PORTD_Register;
            break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8PORT, u8 *Copy_PtrData)
{
    DIO_ErrorStatus LOC_enumState = DIO_OK;
    if ((Copy_u8PORT <= DIO_PORTD))
    {
        switch (Copy_u8PORT)
        {
        case DIO_PORTA:
            *Copy_PtrData = PINA_Register;
            break;
        case DIO_PORTB:
            *Copy_PtrData = PINB_Register;
            break;
        case DIO_PORTC:
            *Copy_PtrData = PINC_Register;
            break;
        case DIO_PORTD:
            *Copy_PtrData = PIND_Register;
            break;
        default:
            LOC_enumState = DIO_NOK;
            break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorStatus DIO_voidWriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value = (Copy_u8value<<4) ;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :
			PORTA_Register&=0x0f;
			PORTA_Register|=Copy_u8value;
			break ;
		case DIO_PORTB:
			PORTB_Register&=0x0f;
			PORTB_Register|=Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC_Register&=0x0f;
			PORTC_Register|=Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD_Register&=0x0f;
			PORTD_Register|=Copy_u8value;
			break ;
		default: break ;

		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;
}

DIO_ErrorStatus DIO_voidWriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value&=0x0f;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :
			PORTA_Register &= 0xf0;
			PORTA_Register |= Copy_u8value;
			break ;
		case DIO_PORTB:
			PORTB_Register &= 0xf0;
			PORTB_Register |= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC_Register &= 0xf0;
			PORTC_Register |= Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD_Register &= 0xf0;
			PORTD_Register |= Copy_u8value;
			break ;
		default: break ;

		}

	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

DIO_ErrorStatus DIO_enumConnectPullup (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case DIO_PORTA:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRA_Register,Copy_u8PIN);
				SET_BIT(PORTA_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port B */
		case DIO_PORTB:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRB_Register,Copy_u8PIN);
				SET_BIT(PORTB_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTB_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port C */
		case DIO_PORTC:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRC_Register,Copy_u8PIN);
				SET_BIT(PORTC_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTC_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port D */
		case DIO_PORTD:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRD_Register,Copy_u8PIN);
				SET_BIT(PORTD_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTD_Register,Copy_u8PIN);
			}
			break;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;


}
