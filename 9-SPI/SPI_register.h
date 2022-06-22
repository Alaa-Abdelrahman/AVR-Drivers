/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	SPI		     	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H


#define SPDR   *((volatile uint8_t *)0x2F)  /*SPI Data register*/

#define SPSR   *((volatile uint8_t *)0x2E)  /*SPI status Register*/
#define SPSR_SPIF     7                     /*SPI interrupt flag*/
#define SPSR_SPI2X    0                    /*Prescaler bit 2*/

#define SPCR   *((volatile uint8_t *)0x2D)  /*SPI control register*/
#define SPCR_SPR0      0                   /*Prescaler bit 0*/
#define SPCR_SPR1      1                   /*Prescaler bit 1*/
#define SPCR_CPHA      2                   /*clock phase */
#define SPCR_CPOL      3                   /*clock polarity*/
#define SPCR_MSTR      4                   /*Master bit */
#define SPCR_DORD      5                   /*Data order*/
#define SPCR_SPE       6                   /*SPIenable */
#define SPCR_SPIE      7				/*SPI interrupt*/






#endif
