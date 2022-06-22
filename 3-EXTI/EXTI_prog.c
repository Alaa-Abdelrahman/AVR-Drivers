/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	DIO				***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

/**
 * Global pointer to function to hold INT0 ISR address
 */

static void ( *EXTI_gpvInt0Func)(void) = NULL;

/**
 * Global pointer to function to hold INT1 ISR address
 */

static void ( *EXTI_gpvInt1Func)(void) = NULL;

/**
 * Global pointer to function to hold INT2 ISR address
 */

static void ( *EXTI_gpvInt2Func)(void) = NULL;




/**
 * the bits mask for bits ISC00, ISC01 in MCUCSR
 */

#define INT0_BITMASK  0b11111100

/**
 * the bits mask for bits ISC10, ISC11 in MCUCSR
 */

#define INT1_BITMASK  0b11110011

/**********************************************************************
 * Function : EXTI_InitStatic()
 *//**
 * \b Description:
 ** This function is used to configure External Interrupt through static configuration
 *
 * PRE-CONDITION: Must set your configuration in EXTI_config.h <br>
 *
 * POST-CONDITION: interrupt Request line was configured with interrupt sense control
 * POST-CONDITION: interrupt Request line was enabled
 *
 *
 * @param void
 *
 * @return void
 *
 * \b Example:
 * @code
 *
 * EXTI_InitStatic();
 *

  * @endcode
  ******************************************************************************/

void EXTI_InitStatic(void)
{
	/**
	 * Set sense control for INT0 to falling edge
	 */
#if INT_REQ_LINE == INT0
#define REQ_LINE0
#elif INT_REQ_LINE == INT1
#define REQ_LINE1
#elif INT_REQ_LINE == INT2
#define REQ_LINE2

#endif

#ifdef REQ_LINE0
#if INT_SENSE_CTRL == INT_FALLING_EDGE
	MCUCR &= INT0_BITMASK;
	MCUCR |= INT_FALLING_EDGE ;

#elif INT_SENSE_CTRL == INT_RISING_EDGE
	MCUCR &= INT0_BITMASK;
	MCUCR |= INT_RISING_EDGE;
#elif INT_SENSE_CTRL == INT_ONCHANGE
	MCUCR &= INT0_BITMASK;
	MCUCR |= INT_ONCHANGE;
#elif INT_SENSE_CTRL == INT_LOW_LEVEL
	MCUCR &= INT0_BITMASK;
	MCUCR |= INT_LOW_LEVEL;
#endif
	/**
	 * PERIPHERAL INTERRUPT ENABLE FOR INT0
	 */
	SET_BIT(GICR,GICR_INT0);
#endif

#ifdef REQ_LINE1
#if INT_SENSE_CTRL == INT_FALLING_EDGE
	MCUCR &= INT1_BITMASK;
	MCUCR |= INT_FALLING_EDGE<<MCUCR_ISC10 ;

#elif INT_SENSE_CTRL == INT_RISING_EDGE
	MCUCR &= INT1_BITMASK;
	MCUCR |= INT_RISING_EDGE<<MCUCR_ISC10;
#elif INT_SENSE_CTRL == INT_ONCHANGE
	MCUCR &= INT1_BITMASK;
	MCUCR |= INT_ONCHANGE<<MCUCR_ISC10;
#elif INT_SENSE_CTRL == INT_LOW_LEVEL
	MCUCR &= INT1_BITMASK;
	MCUCR |= INT_LOW_LEVEL<<MCUCR_ISC10;
#endif
	/**
	 * PERIPHERAL INTERRUPT ENABLE FOR INT1
	 */
	SET_BIT(GICR,GICR_INT1);
#endif

#ifdef REQ_LINE2
#if INT_SENSE_CTRL == INT_FALLING_EDGE
	CLR_BIT(MCUCSR, MCUCSR_INT2);

#elif INT_SENSE_CTRL == INT_RISING_EDGE
	SET_BIT(MCUCSR, MCUCSR_INT2);

#endif
	/**
	 * PERIPHERAL INTERRUPT ENABLE FOR INT2
	 */
	SET_BIT(GICR,GICR_INT1);
#endif

}

/**********************************************************************
 * Function : EXTI_InitDynamic()
 *//**
 * \b Description:
 ** This function is used to configure External Interrupt through Dynamic configuration
 *
 * PRE-CONDITION: pass o function an option that defined in InterruptSenseCtrl_t as first operand   <br>
 * PRE-CONDITION:  pass o function an option that defined in InterrupReqLine_t as second operand <br>
 *
 * POST-CONDITION: interrupt Request line was enabled
 *
 *
 * @param  option that defined in InterruptSenseCtrl_t as first operand as INT_FALLING_EDGE
 * @param   pass o function an option that defined in InterrupReqLine_t as second operand  as INT0
 * @return Error State
 *
 * \b Example:
 * @code
 *
 *ErrorState_t state = 0
 * state = EXTI_InitDynamic(INT_FALLING_EDGE  ,INT0);
 *
 * @endcode
 ******************************************************************************/


ErrorState_t EXTI_InitDynamic(InterruptSenseCtrl_t IntSense ,InterrupReqLine_t IntReqLine){
	ErrorState_t State = DONE;

	switch(IntReqLine)
	{
	case INT0:
	{
		/**
		 * PERIPHERAL INTERRUPT ENABLE FOR INT0
		 */
		SET_BIT(GICR,GICR_INT0);
		switch(IntSense)
		{
		case INT_LOW_LEVEL   :
		{
			MCUCR &= INT0_BITMASK;
			MCUCR |= INT_LOW_LEVEL;
			break;
		}
		case INT_ONCHANGE    :
		{
			MCUCR &= INT0_BITMASK;
			MCUCR |= INT_ONCHANGE;
			break;
		}
		case INT_RISING_EDGE:
		{
			MCUCR &= INT0_BITMASK;
			MCUCR |= INT_RISING_EDGE;
			break;
		}
		case INT_FALLING_EDGE:
		{
			MCUCR &= INT0_BITMASK;
			MCUCR |= INT_FALLING_EDGE ;
			break;
		}
		default:
			State = INT_SENSE_CONTROL;

		}break;
	}
	case INT1:
	{
		/**
		 * PERIPHERAL INTERRUPT ENABLE FOR INT0
		 */
		SET_BIT(GICR,GICR_INT1);
		switch(IntSense)
		{
		case INT_LOW_LEVEL   :
		{
			MCUCR &= INT1_BITMASK;
			MCUCR |= INT_LOW_LEVEL;
			break;
		}
		case INT_ONCHANGE    :
		{
			MCUCR &= INT1_BITMASK;
			MCUCR |= INT_ONCHANGE;
			break;
		}
		case INT_RISING_EDGE:
		{
			MCUCR &= INT1_BITMASK;
			MCUCR |= INT_RISING_EDGE;
			break;
		}
		case INT_FALLING_EDGE:
		{
			MCUCR &= INT1_BITMASK;
			MCUCR |= INT_FALLING_EDGE ;
			break;
		}
		default:
			State = INT_SENSE_CONTROL;

		}break;

	}
	case INT2:
	{
		/**
		 * PERIPHERAL INTERRUPT ENABLE FOR INT0
		 */
		SET_BIT(GICR,GICR_INT2);
		switch(IntSense)
		{
		case INT_RISING_EDGE:
		{
			SET_BIT(MCUCSR, MCUCSR_INT2);
			break;
		}

		case INT_FALLING_EDGE:
		{
			CLR_BIT(MCUCSR, MCUCSR_INT2);
			break;
		}
		default:
			State = INT_SENSE_CONTROL;


		}break;
	}
	default:
		State = INT_REQ_LINE_NOT_FOUND;




	}
	return State;
}



ErrorState_t EXTI_Int0CallBack(void (*PvInt0Func)(void))
{
	ErrorState_t ErrorState = DONE;
	if( PvInt0Func == NULL)
	{
		ErrorState = NULLPTR;
		return ErrorState;
	}
	EXTI_gpvInt0Func = PvInt0Func;

	return ErrorState;


}

ErrorState_t EXTI_Int1CallBack(void (*PvInt1Func)(void))
{
	ErrorState_t ErrorState = DONE;
	if( PvInt1Func == NULL)
	{
		ErrorState = NULLPTR;
		return ErrorState;
	}
	EXTI_gpvInt1Func = PvInt1Func;

	return ErrorState;


}
ErrorState_t EXTI_Int2CallBack(void (*PvInt2Func)(void))
{
	ErrorState_t ErrorState = DONE;
	if( PvInt2Func == NULL)
	{
		ErrorState = NULLPTR;
		return ErrorState;
	}
	EXTI_gpvInt2Func = PvInt2Func;

	return ErrorState;


}
/**
 * ISR of INT0
 */

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_gpvInt0Func != NULL)
	{
		EXTI_gpvInt0Func();
	}
}

/**
 * ISR of INT1
 */

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_gpvInt1Func != NULL)
	{
		EXTI_gpvInt1Func();
	}
}


/**
 * ISR of INT2
 */

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_gpvInt2Func != NULL)
	{
		EXTI_gpvInt2Func();
	}
}













