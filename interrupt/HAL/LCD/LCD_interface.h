/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                 *************************/
/**************    SWC:LCD                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void HLCD_VoidInit(void);

void HLCD_VoidSendChar(u8 copy_u8char);

void HLCD_VoidSendCommand(u8 copy_u8command);

void HLCD_VoidSendString(u8 copy_u8Char[]);

void HLCD_VoidSendNumber(u32 copy_u8Char);

void HLCD_VoidGotoXY(u8 copy_U8RowPos ,u8 copy_U8ColPos);

void HLCD_VoidDraw(u8 *copy_u8char, u8 copy_u8Location,u8 copy_u8Xpos ,u8 copy_u8Ypos);






#define RETURN_TO_HOME      HLCD_VoidSendCommand(0b00000010);
#define FUNCTIONSET  		0b00111000
#define DISPLAYON			0b00001111
#define DISPLAYCLEAR  		0b00000001













#endif
