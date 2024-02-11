/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:DIO                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define DIO_u8_PORT_OUTPUT		0xff
#define DIO_u8_PORT_INPUT		0

#define DIO_u8_PORT_HIGH		0xff
#define DIO_u8_PORT_LOW			0

#define DIO_u8_PIN_OUTPUT		1
#define DIO_u8_PIN_INPUT		0

#define DIO_u8_PIN_HIGH			1
#define DIO_u8_PIN_LOW			0

#define DIO_u8_PORTA			0
#define DIO_u8_PORTB			1
#define DIO_u8_PORTC			2
#define DIO_u8_PORTD			3

#define DIO_u8_PINA				0
#define DIO_u8_PINB				1
#define DIO_u8_PINC				2
#define DIO_u8_PIND				3

#define DIO_u8_PIN0				0
#define DIO_u8_PIN1			    1
#define DIO_u8_PIN2				2
#define DIO_u8_PIN3			    3
#define DIO_u8_PIN4				4
#define DIO_u8_PIN5				5
#define DIO_u8_PIN6			    6
#define DIO_u8_PIN7				7




u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin, u8 *Copy_Pu8Vlaue);




#endif // DIO_INTERFACE_H_
