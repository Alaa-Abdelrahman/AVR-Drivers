/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	USART			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/

#ifndef USART_REGISTER_H
#define USART_REGISTER_H

#define UDR    (*(volatile uint8_t *)0x2C)     /**<USART description register **/
#define UCSRA  (*(volatile uint8_t *)0x2B)     /**<USAERT CONTROL AND STATUS REGISTER A**/

#define UCSRA_RXC          7  /**<usart receive complete */
#define UCSRA_TXC          6  /**<usart transmit complete */
#define UCSRA_UDRE         5  /**<usart data register empty*/
#define UCSRA_FE           4 /**<frame error */
#define UCSRA_DOR          3 /**<data overrun */
#define UCSRA_PE           2 /**<parity error */
#define UCSRA_U2X          1


#define UCSRB  (*(volatile uint8_t *)0x2A)     /**<USAERT CONTROL AND STATUS REGISTER B**/
#define UCSRB_RXCIE  7 /**< RX COMPLETE INTERRUPT ENABLE */
#define UCSRB_TXCIE  6 /**< TX COMPLETE INTERRUPT ENABLE */
#define UCSRB_UDRIE  5 /**< USART DATA REGISTER EMPTY INTERRUPT ENABLE */
#define UCSRB_RXEN   4 /**< RECEIVER ENABLE */
#define UCSRB_TXEN   3 /**<TRANSMITTER ENABLE */
#define UCSRB_UCSZ2  2 /**<CHARACTER SIZE */

#define UBRRL  (*(volatile uint8_t *)0x29)     /**<USAERT BAUD RATE REGISTER LOW **/

#define UBRRH  (*(volatile uint8_t *)0x40)     /**<USAERT BAUD RATE REGISTER HIGH **/

#define UCSRC  (*(volatile uint8_t *)0x40)     /**<USAERT CONTROL AND STATUS REGISTER B**/
#define UCSRC_URSEL    7 /**< REGISTER SELECT */
#define UCSRC_UMSEL    6 /**<USART MODE SELECT*/
#define UCSRC_UPM1     5 /**< PARITY MODE */
#define UCSRC_UPM0     4 /**<PARITY MODE */
#define UCSRC_USBS     3 /**< STOP BIT SELECT*/
#define UCSRC_UCSZ1    2 /**<CHARACTER SIZE */
#define UCSRC_UCSZ0    1 /**<CHARACTER SIZE */
#define UCSRC_UCPOL    0 /** CLOCK POLARITY*/

#endif
