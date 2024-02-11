/***********************************************************************/
/***********************************************************************/
/**************    Auther: Ahmed Arabe         *************************/
/**************    Layer: MCAL                 *************************/
/**************    SWC:EXTI                     *************************/
/**************    Version: 1.00               *************************/
/***********************************************************************/
/***********************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE 	3
#define RISING_EDGE		4

#define INT0			1
#define INT1			2
#define INT2			3

void EXIT_voidINT0Init(void);

void EXIT_voidINT1Init(void);

void EXIT_voidINT2Init(void);


u8 EXIT_u8INT0_SetSenseControl(u8 copy_u8sense);

u8 EXIT_u8INT1_SetSenseControl(u8 copy_u8sense);

u8 EXIT_u8INT2_SetSenseControl(u8 copy_u8sense);


u8 EXIT_u8INT_Enable(u8 copy_u8Int);

u8 EXIT_u8INT_Disable(u8 copy_u8Int);


u8 EXIT_u8Int0SetCallBack(void (*copy_Int0PtrFunc)(void));

u8 EXIT_u8Int1SetCallBack(void (*copy_Int0PtrFunc)(void));

u8 EXIT_u8Int2SetCallBack(void (*copy_Int0PtrFunc)(void));

#endif
