/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa	     	***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	EXTI				***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


#define GICR        (*((volatile uint8_t * const) 0X5B))
#define GICR_INT1	    7
#define GICR_INT0	    6
#define GICR_INT2 	    5

#define GIIFR       (*((volatile uint8_t * const) 0X5A))

#define MCUCR       (*((volatile uint8_t * const) 0X55))
#define MCUCR_ISC11  	3
#define MCUCR_ISC10		2
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0

#define MCUCSR      (*((volatile uint8_t * const) 0X54))
#define MCUCSR_INT2		6


#endif
