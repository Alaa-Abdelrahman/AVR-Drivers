/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	USART			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/**
 * define the modes for USART
 */
#define SYNC     1
#define ASYNC    2

/**
 * define the data frame sizes options
 */

#define FRAME_MASK          0b11111001
#define DATA_FRAME_5BITS    0b11111001
#define DATA_FRAME_6BITS    0b11111011
#define DATA_FRAME_7BITS    0b11111101
#define DATA_FRAME_8BITS    0b11111111
#define DATA_FRAME_9BITS    0b11111111


/**
 * define stop bits number
 */
#define STOP_1BIT   3
#define STOP_2BITS  4

/**
 * parity mode
 */
#define EVEN      23
#define ODD       43
#define NO_PARITY 98

#endif
