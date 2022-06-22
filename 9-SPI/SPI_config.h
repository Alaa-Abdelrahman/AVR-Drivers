/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	SPI		     	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/**
 * Define the mode that SPI operates in
 * 					options:
 * 					    -MASTER_MODE
 * 					    -SLAVE_MODE
 */

#define SPI_MODE    MASTER_MODE

/**
 * define options for reading and sending data:
 * 		-SAMPLE_ON_RISING_SETUP_ON_FALING
 * 		-SAMPLE_ON_FALING_SETUP_ON_RISING
 */

#define SYNC_SAMPLING_SETUP   SAMPLE_ON_RISING_SETUP_ON_FALING

/**
 * define the data order for sending
 * 							Options:
 * 							-MSB
 * 							-LSB
 */

#define DATA_ORDER     MSB


/**
 * define SCK frequency
 * 			options:
 * 			        -FOSC_DIV_4
 * 			        -FOSC_DIV_16
 * 			        -FOSC_DIV_64
 * 			        -FOSC_DIV_128
 *
 *
 *
 */
#define SCK_FREQ       FOSC_DIV_16




#endif
