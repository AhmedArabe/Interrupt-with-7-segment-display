/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: HAL                  *************************/
/**************    SWC: 7_Segment Display      *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef  SSD_INTERFACE_H_
#define  SSD_INTERFACE_H_


#define CATHOD		0
#define ANODE		1

u8 ssd_u8Enable(u8 Copy_u8Port , u8 Copy_u8Pin);

u8 ssd_u8Disable(u8 Copy_u8Port , u8 Copy_u8Pin);

u8 ssd_u8SendNumber(u8 Copy_u8Port,u8 Copy_u8Number);

u8 ssd_u8SendNumber_Mul(u8 Copy_u8Port,u8 Copy_u8ComPort,u8 Copy_u8Number1, u8 Copy_u8Com1, u8 Copy_u8Number2, u8 Copy_u8Com2);



#endif
