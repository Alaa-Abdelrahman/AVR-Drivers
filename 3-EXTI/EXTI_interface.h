/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	EXTI			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/**
 * interrupt sense control  options
 * when choose one option that interrupt happen when occurs
 */

typedef enum{
	        INT_LOW_LEVEL   ,
	        INT_ONCHANGE    ,
	        INT_FALLING_EDGE,

	        INT_RISING_EDGE

}InterruptSenseCtrl_t;

/**
 * interrupt Interrupt Request line  options
 * when choose one option that define the interrupt Request line
 */

typedef enum{
	        INT0,   /**<Interrupt Request Line0  */
	        INT1,   /**<Interrupt Request Line1  */
			INT2    /**<Interrupt Request Line2  */

}InterrupReqLine_t;

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
* @return Error State
*
* \b Example:
* @code
*
* SwConfig SW1 = {SW_IN_PULLUP,,PORTA,PIN0}
* uint8_t state = SW_Init(&SW1);
*
* @endcode
******************************************************************************/

void EXTI_InitStatic(void);

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


ErrorState_t EXTI_InitDynamic(InterruptSenseCtrl_t IntSense ,InterrupReqLine_t IntReqLine);

ErrorState_t EXTI_Int0CallBack(void (*PvInt0Func)(void));

ErrorState_t EXTI_Int1CallBack(void (*PvInt1Func)(void));

ErrorState_t EXTI_Int2CallBack(void (*PvInt0Func)(void));

#endif
