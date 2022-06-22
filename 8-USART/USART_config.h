/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	USART			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/**
 * mode options:
 *         -Synchronous -> SYNC
 *         -Asynchronous-> ASYNC
 */

#define USART_MODE   ASYNC

/**
 * define data frame size  options:
 *                             -DATA_FRAME_5BITS
 *                             -DATA_FRAME_6BITS
 *                             -DATA_FRAME_7BITS
 *                             -DATA_FRAME_8BITS
 *                             -DATA_FRAME_9BITS
 */
#define DATA_FRAME  DATA_FRAME_8BITS

/**
 * define number of stop bits :
 *                      -STOP_1BIT
 *                      -STOP_2BITS
 */

#define NO_OF_STOP_BIT   STOP_1BIT





/**
 * define the the parity mode
 *                          -EVEN
 *                          -ODD
 *                          -NO_PARITY
 */
#define NO_OF_PARITY    NO_PARITY


/**
 * define the baud rate standard options:
 *                                     -2400
 *                                     -4800
 *                                     -9600
 *                                     -14400
 *                                     -19200
 *
 */
#define BAUD_RATE    9600
#endif
