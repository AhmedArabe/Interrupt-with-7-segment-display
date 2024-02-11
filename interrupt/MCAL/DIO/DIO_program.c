#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_register.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8Error_Sate =0;
	if(Copy_u8Pin <=DIO_u8_PIN7)
	{
		if(Copy_u8Direction ==DIO_u8_PIN_OUTPUT)
		{
			switch (Copy_u8Port)
			{
			case DIO_u8_PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8_PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8_PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8_PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
			default :Local_u8Error_Sate=1 ;

			}
		}
		else if(Copy_u8Direction ==DIO_u8_PIN_INPUT)
		{
			switch (Copy_u8Port)
			{
			case DIO_u8_PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8_PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8_PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8_PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
			default :Local_u8Error_Sate=1 ;

			}
		}
		else
		{
			Local_u8Error_Sate=1 ;
		}
	}
	else
	{
		Local_u8Error_Sate=1;
	}
	return Local_u8Error_Sate;
}



u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{

	u8 Local_u8_ErrorState=0;

	switch (Copy_u8Port)
	{
	case DIO_u8_PORTA : DDRA =Copy_u8Direction; break;
	case DIO_u8_PORTB : DDRB =Copy_u8Direction; break;
	case DIO_u8_PORTC : DDRC =Copy_u8Direction; break;
	case DIO_u8_PORTD : DDRD =Copy_u8Direction; break;
	default :Local_u8_ErrorState=1;
	}
	return Local_u8_ErrorState;

}



u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8_ErrorState=0;
	if(Copy_u8Pin <=DIO_u8_PIN7)
	{
		if(Copy_u8Value ==DIO_u8_PIN_HIGH)
		{
			switch (Copy_u8Port)
			{
			case DIO_u8_PORTA :SET_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8_PORTB :SET_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8_PORTC :SET_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8_PORTD :SET_BIT(PORTD,Copy_u8Pin); break;
			default :Local_u8_ErrorState =1 ;
			}
		}
		else if(Copy_u8Value ==DIO_u8_PIN_LOW)
		{
			switch (Copy_u8Port)
			{
			case DIO_u8_PORTA :CLR_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8_PORTB :CLR_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8_PORTC :CLR_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8_PORTD :CLR_BIT(PORTD,Copy_u8Pin); break;
			default :Local_u8_ErrorState =1 ;

			}
		}
		else
		{
			Local_u8_ErrorState=1;
		}
	}
	else
	{
		Local_u8_ErrorState=1;

	}
	return Local_u8_ErrorState;

}




u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{

	u8 Local_u8_ErrorState=0;

	switch (Copy_u8Port)
	{
	case DIO_u8_PORTA : PORTA =Copy_u8Value; break;
	case DIO_u8_PORTB : PORTB =Copy_u8Value; break;
	case DIO_u8_PORTC : PORTC =Copy_u8Value; break;
	case DIO_u8_PORTD : PORTD =Copy_u8Value; break;
	default :Local_u8_ErrorState=1;
	}
	return Local_u8_ErrorState;



}

u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin, u8 *Copy_Pu8Vlaue)
{
	u8 Local_u8_ErrorState=0;
	if((Copy_Pu8Vlaue != NULL)&&(Copy_u8Pin <=DIO_u8_PIN7))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8_PORTA : *Copy_Pu8Vlaue =GET_BIT(PINA , Copy_u8Pin); break;
		case DIO_u8_PORTB : *Copy_Pu8Vlaue =GET_BIT(PINB , Copy_u8Pin); break;
		case DIO_u8_PORTC : *Copy_Pu8Vlaue =GET_BIT(PINC , Copy_u8Pin); break;
		case DIO_u8_PORTD : *Copy_Pu8Vlaue =GET_BIT(PIND , Copy_u8Pin); break;
		default :Local_u8_ErrorState=1;
		}
	}
	else
	{
		Local_u8_ErrorState=1;
	}

	return Local_u8_ErrorState;

}
