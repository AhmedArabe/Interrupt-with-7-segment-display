/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                 *************************/
/**************    SWC:LCD                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "avr/delay.h"




void HLCD_VoidInit(void)
{

	/* set Port direction output */
	DIO_u8SetPortDirection(HLCD_U8_DATA_PORT,DIO_u8_PORT_OUTPUT);
	/* RS DIR OUT*/
	DIO_u8SetPinDirection(HLCD_U8_CONTROL_PORT,HLCD_U8_RS_PIN,DIO_u8_PIN_OUTPUT);
	/* RW DIR OUT*/
	DIO_u8SetPinDirection(HLCD_U8_CONTROL_PORT,HLCD_U8_RW_PIN,DIO_u8_PIN_OUTPUT);
	/* EN DIR OUT*/
	DIO_u8SetPinDirection(HLCD_U8_CONTROL_PORT,HLCD_U8_EN_PIN,DIO_u8_PIN_OUTPUT);

	_delay_ms(40);
	/* function set 8_bit mode , 2-Line ,font_type 5*7 */
	HLCD_VoidSendCommand(FUNCTIONSET);
	_delay_ms(1);

	/* Display on/off control*/
	HLCD_VoidSendCommand(DISPLAYON);
	_delay_ms(1);

	/* display Clear*/
	HLCD_VoidSendCommand(DISPLAYCLEAR);
	_delay_ms(2);

	/* return to home*/
	HLCD_VoidSendCommand(0b00000010);
}


void HLCD_VoidSendChar(u8 copy_u8char)
{
	/*     RS=1   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_RS_PIN,DIO_u8_PIN_HIGH);
	/*     RW=0   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_RW_PIN,DIO_u8_PIN_LOW);

	/*     Data   */
	DIO_u8SetPortValue(HLCD_U8_DATA_PORT,copy_u8char);

	/*     EN=1   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_EN_PIN,DIO_u8_PIN_HIGH);
	/*       delay 2ms  */
	_delay_ms(2);
	/*     EN=0   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_EN_PIN,DIO_u8_PIN_LOW);
	/*       delay 2ms  */
	_delay_ms(2);

}



void HLCD_VoidSendCommand(u8 copy_u8command)

{
	/*     RS=0   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_RS_PIN,DIO_u8_PIN_LOW);
	/*     RW=0   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_RW_PIN,DIO_u8_PIN_LOW);

	/*     Command   */
	DIO_u8SetPortValue(HLCD_U8_DATA_PORT,copy_u8command);

	/*     EN=1   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_EN_PIN,DIO_u8_PIN_HIGH);
	/*     delay 2ms  */
	_delay_ms(2);
	/*     EN=0   */
	DIO_u8SetPinValue(HLCD_U8_CONTROL_PORT,HLCD_U8_EN_PIN,DIO_u8_PIN_LOW);
	/*     delay 2ms  */
	_delay_ms(2);

}


void HLCD_VoidSendString(u8 copy_u8Char[])
{
	u8 i=0;
	while(copy_u8Char[i]!='\0')
	{
		HLCD_VoidSendChar(copy_u8Char[i]);
		i++;
	}
}



void HLCD_VoidSendNumber(u32 copy_u8Char)
{
	u32  Local_u8_revers_number = 1;

	if(copy_u8Char == 0)
	{
		HLCD_VoidSendChar(copy_u8Char+'0');
	}

	while(copy_u8Char > 0)
	{
		Local_u8_revers_number=Local_u8_revers_number*10+copy_u8Char%10;
		copy_u8Char=copy_u8Char/10;
	}

	while(Local_u8_revers_number>1)
	{
		copy_u8Char=Local_u8_revers_number % 10;
		Local_u8_revers_number=Local_u8_revers_number/10;
		HLCD_VoidSendChar(copy_u8Char+'0');

	}



}






void HLCD_VoidGotoXY(u8 copy_U8RowPos ,u8 copy_U8ColPos)
{
	if(copy_U8RowPos ==0)
	{
		HLCD_VoidSendCommand(copy_U8ColPos+128);

	}
	else if(copy_U8RowPos ==1)
	{
		HLCD_VoidSendCommand(copy_U8ColPos+128+64);

	}

}




void HLCD_VoidDraw(u8 *copy_u8char, u8 copy_u8Location,u8 copy_u8Xpos ,u8 copy_u8Ypos)
{
	u8 i=0;
	HLCD_VoidSendCommand(64+8*(copy_u8Location));//address 0 of  location 0 of CG_Ram
	for(i=0;i<8;i++)
	{
		HLCD_VoidSendChar(copy_u8char[i]);

	}
	HLCD_VoidSendCommand(0b10000000);//address 0 of DD_Ram
	HLCD_VoidGotoXY(copy_u8Xpos,copy_u8Ypos);
	HLCD_VoidSendChar(copy_u8Location); //address location 0 of CG_Ram

}



