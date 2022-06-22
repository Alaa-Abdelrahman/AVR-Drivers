/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	EXTI			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/**
 * interrupt sense control  options
 * when choose one option that interrupt happen when occurs
 * Options:
 *                -INT_LOW_LEVEL
 *	              -INT_ONCHANGE
 *                -INT_RINSING_EDGE
 *                -INT_FALLING_EDGE
 *

*/

#define INT_SENSE_CTRL  INT_FALLING_EDGE

/**
 * interrupt Interrupt Request line  options
 * when choose one option that define the interrupt Request line
 * Options:  -INT0
 *           -INT1
 *           -INT2
 *
 */


#define INT_REQ_LINE   INT0









#endif
