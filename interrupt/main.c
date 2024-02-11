#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GIE/GIE_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/SSD/ssd_interface.h"

#include "avr/delay.h"


void Int0Isr(void);
void Int1Isr(void);

volatile s8 current_value1=0, current_value2=0;
volatile s8 num1=0 ,num2=0 ;
volatile u8 LCD_flag =0;
void main (void)
{

	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_PIN_INPUT); // INT1
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_PIN_HIGH); // activate pull up

	HLCD_VoidInit(); // initialize LCD

	DIO_u8SetPortDirection(DIO_u8_PORTA,DIO_u8_PORT_OUTPUT); // initialize PORTA for SSD1

	DIO_u8SetPortDirection(DIO_u8_PORTB,DIO_u8_PORT_OUTPUT);// initialize PORTB for SSD2

	GIE_voidEnable();  // enable For Global Interrupt

	EXIT_voidINT1Init();  // initialize for INT1

	EXIT_u8Int1SetCallBack(Int1Isr);  // call back function of int1

	HLCD_VoidSendCommand(DISPLAYCLEAR);
	HLCD_VoidSendString("Count up ");
	HLCD_VoidGotoXY(1,0);
	HLCD_VoidSendString("No interrupt Fired");
	while(1)
	{
		for(num1=0;num1<=9;num1++)
		{
			ssd_u8SendNumber(DIO_u8_PORTB,num1);
			current_value1 =num1;
			for(num2=0;num2<=9;num2++)
			{
				ssd_u8SendNumber(DIO_u8_PORTA,num2);
				current_value2=num2;
				_delay_ms(500);
				if(LCD_flag ==1)
				{
					HLCD_VoidSendCommand(DISPLAYCLEAR);
					HLCD_VoidSendString("Count up ");
					HLCD_VoidGotoXY(1,0);
					HLCD_VoidSendString("No interrupt Fired");
					LCD_flag=0;

				}

			}

		}
	}
}



void Int1Isr(void)
{
	LCD_flag=1;
	s8 ssd_num1, ssd_sum2;
	HLCD_VoidSendCommand(DISPLAYCLEAR);
	HLCD_VoidSendString("Count down ");
	HLCD_VoidGotoXY(1,0);
	HLCD_VoidSendString("interrupt Fired");
	for(ssd_num1=1;ssd_num1>=0;ssd_num1--)
	{
		ssd_u8SendNumber(DIO_u8_PORTB,ssd_num1);
		for(ssd_sum2=9;ssd_sum2>=0;ssd_sum2--)
		{
			ssd_u8SendNumber(DIO_u8_PORTA,ssd_sum2);
			_delay_ms(500);
		}
	}

}
