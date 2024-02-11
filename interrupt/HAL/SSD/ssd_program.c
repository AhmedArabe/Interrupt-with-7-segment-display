/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                  *************************/
/**************    SWC: 7_Segment Display      *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_register.h"
#include "ssd_interface.h"

#include "ssd_config.h"
#include "ssd_private.h"
#include  "avr/delay.h"

u8 number[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};


u8 ssd_u8Enable(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8_ErrorState =0;

	if(Copy_u8Pin <= DIO_u8_PIN7)
	{

#if COM_TYPE == CATHOD
		DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8_PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8_PIN_LOW);
#endif
#if COM_TYPE == ANODE
		DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8_PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8_PIN_HIGH);
#endif
	}
	else
	{
		Local_u8_ErrorState=1;
	}
	return Local_u8_ErrorState;
}


u8 ssd_u8Disable(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8_ErrorState =0;


	if(Copy_u8Pin <= DIO_u8_PIN7)
	{
#if COM_TYPE ==CATHOD
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8_PIN_HIGH);
#endif

#if COM_TYPE ==ANODE
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8_PIN_LOW);
#endif
	}
	else
	{
		Local_u8_ErrorState=1;
	}
	return Local_u8_ErrorState;

}


u8 ssd_u8SendNumber(u8 Copy_u8Port,u8 Copy_u8Number)
{
	u8 Local_u8_ErrorState =0;
	if(Copy_u8Number <= 9) //number[9]
	{

		DIO_u8SetPortDirection(Copy_u8Port,DIO_u8_PORT_OUTPUT);

		switch (Copy_u8Port)
		{

#if COM_TYPE ==CATHOD

		case DIO_u8_PORTA :DIO_u8SetPortValue(DIO_u8_PORTA,number[Copy_u8Number]); break;
		case DIO_u8_PORTB :DIO_u8SetPortValue(DIO_u8_PORTB,number[Copy_u8Number]); break;
		case DIO_u8_PORTC :DIO_u8SetPortValue(DIO_u8_PORTC,number[Copy_u8Number]); break;
		case DIO_u8_PORTD :DIO_u8SetPortValue(DIO_u8_PORTD,number[Copy_u8Number]); break;
		default : Local_u8_ErrorState=1;
#endif

#if COM_TYPE ==ANODE

		case DIO_u8_PORTA :DIO_u8SetPortValue(DIO_u8_PORTA,~Copy_u8Number); break;
		case DIO_u8_PORTB :DIO_u8SetPortValue(DIO_u8_PORTB,~Copy_u8Number); break;
		case DIO_u8_PORTC :DIO_u8SetPortValue(DIO_u8_PORTC,~Copy_u8Number); break;
		case DIO_u8_PORTD :DIO_u8SetPortValue(DIO_u8_PORTD,~Copy_u8Number); break;
		default : Local_u8_ErrorState=1;

#endif

		}

	}
	else
	{
		Local_u8_ErrorState=1;
	}
	return Local_u8_ErrorState;
}



u8 ssd_u8SendNumber_Mul(u8 Copy_u8Port,u8 Copy_u8ComPort,u8 Copy_u8Number1, u8 Copy_u8Com1, u8 Copy_u8Number2, u8 Copy_u8Com2)
{

	u8 Local_u8_ErrorState =0;
	if((Copy_u8Number1 <= number[9]) && (Copy_u8Number2 <= number[9]))
	{
		ssd_u8Disable(Copy_u8ComPort,Copy_u8Com2);
		ssd_u8Enable(Copy_u8ComPort,Copy_u8Com1);
		ssd_u8SendNumber(Copy_u8Port,Copy_u8Number1);
		_delay_ms(100);
		ssd_u8Disable(Copy_u8ComPort,Copy_u8Com1);
		ssd_u8Enable(Copy_u8ComPort,Copy_u8Com2);
		ssd_u8SendNumber(Copy_u8Port,Copy_u8Number2);
		_delay_ms(10);

	}
	else
	{
		Local_u8_ErrorState=1;
	}
	return Local_u8_ErrorState;
}

