#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "EXTI-config.h"
#include "EXTI_private.h"


void (*EXIT_INT0PtrFunc) (void)=NULL;
void (*EXIT_INT1PtrFunc) (void)=NULL;
void (*EXIT_INT2PtrFunc) (void)=NULL;

void EXIT_voidINT0Init(void)
{
#if INT0_SENSE == FALLING_EDGE
	/*set sense control for INT0 as falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE == RISING_EDGE
	/*set sense control for INT0 as rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE == ON_CHANGE
	/*set sense control for INT0 as on change */
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE == LOW_LEVEL
	/*set sense control for INT0 as Low level*/
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#else
#error "Wrong input of sense control"

#endif

#if INT0_INITIAL_STATE ==ENABELD
	/*peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong input of initial state"
#endif

}

void EXIT_voidINT1Init(void)
{

#if INT1_SENSE == FALLING_EDGE   // falling edge
	/*set sense control for INT1 as falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == RISING_EDGE   // rising edge
	/*set sense control for INT1 as rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == ON_CHANGE   // On change
	/*set sense control for INT1 as on change*/
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == LOW_LEVEL   // Low level
	/*set sense control for INT1 as Low level */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#else
#error "Wrong input of sense control"
#endif


#if INT1_INITIAL_STATE==ENABELD
	/*peripheral interrupt enable for INT1*/
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE==DISABLED
	/*peripheral interrupt disable for INT1*/
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong input of initial state"
#endif


}


void EXIT_voidINT2Init(void)
{


#if INT2_SENSE == FALLING_EDGE   // falling edge
	/*set sense control for INT2 as falling edge*/
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENSE == RISING_EDGE   // rising edge
	/*set sense control for INT2 as rising edge*/
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "Wrong input of sense control"
#endif

#if INT2_INITIAL_STATE ==ENABELD
	/*peripheral interrupt enable for INT2*/
	SET_BIT(GICR,GICR_INT2);

#elif INT2_INITIAL_STATE ==DISABLED
	/*peripheral interrupt disable for INT2*/
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong input of initial state"
#endif

}


u8 EXIT_u8INT0_SetSenseControl(u8 copy_u8sense)
{
	u8 Local_u8Error_State=OK ;
	switch(copy_u8sense)
	{
	case RISING_EDGE :  SET_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00); break;
	case FALLING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00); break;
	case ON_CHANGE   :	CLR_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00); break;
	case LOW_LEVEL	 :	CLR_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00); break;
	default : Local_u8Error_State=NOK;
	}
	return Local_u8Error_State;
}

u8 EXIT_u8INT1_SetSenseControl(u8 copy_u8sense)
{
	u8 Local_u8Error_State=OK ;
	switch(copy_u8sense)
	{
	case RISING_EDGE :  SET_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;
	case FALLING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
	case ON_CHANGE   :	CLR_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;
	case LOW_LEVEL	 :	CLR_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
	default : Local_u8Error_State=NOK;
	}
	return Local_u8Error_State;
}


u8 EXIT_u8INT2_SetSenseControl(u8 copy_u8sense)
{
	u8 Local_u8Error_State=OK ;
	switch(copy_u8sense)
	{
	case RISING_EDGE :  SET_BIT(MCUCSR,MCUCSR_ISC2); break;
	case FALLING_EDGE: 	CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
	default : Local_u8Error_State=NOK;
	}
	return Local_u8Error_State;
}

u8 EXIT_u8INT_Enable(u8 copy_u8Int)
{
	u8 Local_u8Error_State=OK ;
	if(copy_u8Int == INT0)
	{
		SET_BIT(GICR,GICR_INT0);
	}
	else if (copy_u8Int == INT1)
	{
		SET_BIT(GICR,GICR_INT1);
	}
	else if(copy_u8Int == INT2)
	{
		SET_BIT(GICR,GICR_INT2);
	}
	else
	{
		Local_u8Error_State=NOK;
	}
	return Local_u8Error_State;


}

u8 EXIT_u8INT_Disable(u8 copy_u8Int)
{
	u8 Local_u8Error_State=OK ;
	if(copy_u8Int == INT0)
	{
		CLR_BIT(GICR,GICR_INT0);
	}
	else if (copy_u8Int == INT1)
	{
		CLR_BIT(GICR,GICR_INT1);
	}
	else if(copy_u8Int == INT2)
	{
		CLR_BIT(GICR,GICR_INT2);
	}
	else
	{
		Local_u8Error_State=NOK;
	}
	return Local_u8Error_State;

}



/*call back function of int0*/
u8 EXIT_u8Int0SetCallBack(void (*copy_Int0PtrFunc)(void))
{
	u8 Local_u8Error_State=OK ;
	if(copy_Int0PtrFunc!=NULL)
	{
		EXIT_INT0PtrFunc=copy_Int0PtrFunc;
	}
	else
	{
		Local_u8Error_State=NULL_POINTER;
	}
	return Local_u8Error_State;
}


/*ISR OF INT0*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)

{
	if(EXIT_INT0PtrFunc!=NULL)
	{
		EXIT_INT0PtrFunc();
	}
	else
	{
		//do nothing
	}
}


/*call back function of int1*/
u8 EXIT_u8Int1SetCallBack(void (*copy_Int1PtrFunc)(void))
{
	u8 Local_u8Error_State=OK ;
	if(copy_Int1PtrFunc!=NULL)
	{
		EXIT_INT1PtrFunc=copy_Int1PtrFunc;
	}
	else
	{
		Local_u8Error_State=NULL_POINTER;
	}
	return Local_u8Error_State;
}

/*ISR OF INT2*/
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)

{
	if(EXIT_INT1PtrFunc!=NULL)
	{
		EXIT_INT1PtrFunc();
	}
	else
	{
		//do nothing
	}
}



/*call back function of int2*/
u8 EXIT_u8Int2SetCallBack(void (*copy_Int2PtrFunc)(void))
{
	u8 Local_u8Error_State=OK ;
	if(copy_Int2PtrFunc!=NULL)
	{
		EXIT_INT2PtrFunc=copy_Int2PtrFunc;
	}
	else
	{
		Local_u8Error_State=NULL_POINTER;
	}
	return Local_u8Error_State;
}

/*ISR OF INT2*/
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)

{
	if(EXIT_INT2PtrFunc!=NULL)
	{
		EXIT_INT2PtrFunc();
	}
	else
	{
		//do nothing
	}
}

