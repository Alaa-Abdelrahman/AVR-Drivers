/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	SPI		     	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/**
 * modes of operation for SPI
 */
 #define MASTER_MODE    1
 #define SLAVE_MODE     2


/**
 * define sync events for sending and receiving
 */
#define SAMPLE_ON_RISING_SETUP_ON_FALING   3
#define SAMPLE_ON_FALING_SETUP_ON_RISING   4

/**
 * define Data order
 */

#define MSB   5
#define LSB   6

/**
 * Define serial clock frequency
 */
#define SCK_SPCR_MASK     0B11111100

#define FOSC_DIV_4       0b00000000
#define FOSC_DIV_16      0b00000001
#define FOSC_DIV_64      0b00000010
#define FOSC_DIV_128     0b00000011
#define FOSC_DIV_8       0b00000001
#define FOSC_DIV_32      0b00000010
#endif
