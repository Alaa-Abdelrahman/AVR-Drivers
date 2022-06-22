/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	USART			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/**
 * define NULL_BYTE
 */
#define NULL_BYTE   '\0'

/**
 *define the clock frequency of the system
 */
#define FOSC   8000000

/*********************************************************************
* Function :USART_voidInit(void);
*//**
* \b Description:used to configure USART :
*                                      -Mode (ASYNC,SYNC)
*                                      -Data frame size
*                                      -NO of STOP bits
*                                      -Parity mode
*                                      -baud rate
*                                      _enable USAT module
* PRE-CONDITION: Configuration must set in config.h <br>
*
*
* POST-CONDITION: UASRT peripheral is set up with the configuration settings.
*
* @param : void
*
* @return void

***************************************************************************/

void USART_voidInit(void);

/*********************************************************************
* Function :USART_voidSend(uint8_t data);
*//**
* \b Description:used to send byte of data.
*
* @param[in] : data the byte of data to sent
*
* @return void

***************************************************************************/

void USART_voidSend(uint8_t data);

/*********************************************************************
* Function :USART_u8Receive(void);
*//**
* \b Description:used to receive  byte of data.
*
* @param[] :none
*
* @return received data

***************************************************************************/
uint8_t  USART_u8Receive(void);

/*********************************************************************
* Function :USART_voidSendString(const uint8_t* ptrString);
*//**
* \b Description:used to send string
*
* @param[in] : pointer to string that want to send
*
* @return void

***************************************************************************/

void USART_voidSendString(const uint8_t* ptrString);
/*********************************************************************
* Function :USART_voidReceiveString(const uint8_t* ptrReceviedString,uint8_t u8size);
*//**
* \b Description:used to receive  string
*
* @param[in] :size of the string
* @param[out] :pointer to the received string
*
* @return received data

***************************************************************************/
void  USART_voidReceiveString( uint8_t* ptrReceviedString,uint8_t u8size);


#endif
