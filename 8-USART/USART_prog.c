/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	USART			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_register.h"



void USART_voidInit(void)
{
	uint8_t Local_u8UCSRCVAlue = 0;
	/*Set Mode*/
#if USART_MODE == ASYNC
	/* select the USART Mode asynchronous mode */
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UMSEL);

#elif USART_MODE == SYNC
	/* select the USART Mode synchronous mode */
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UMSEL);

#endif

#if DATA_FRAME == DATA_FRAME_8BITS
	/* set data to 8 bits */
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_FRAME == DATA_FRAME_5BITS
	/* set data to 5 bits */
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_FRAME == DATA_FRAME_6BITS
	/* set data to 6 bits */
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_FRAME == DATA_FRAME_7BITS
	/* set data to 7 bits */
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#endif

#if  NO_OF_STOP_BIT==STOP_1BIT
	/*1 bit for Stop select*/
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_USBS);
#elif  NO_OF_STOP_BIT==STOP_2BITS
	/* 2 bit for Stop select*/
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_USBS);

#endif

#if NO_OF_PARITY == NO_PARITY
	/*no Parity*/
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UPM1);
#elif NO_OF_PARITY == EVEN
	/*EVEN Parity*/
	CLR_BIT(Local_u8UCSRCVAlue,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UPM1);
#elif NO_OF_PARITY ==ODD
	/*ODD Parity*/
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_UPM1);

#endif

	/* Select the UCSRC register */
	SET_BIT(Local_u8UCSRCVAlue,UCSRC_URSEL);
	/*write to UCSRC*/
	UCSRC = Local_u8UCSRCVAlue;

	/* setting baud rate */
   UBRRL=51;

	/*Enable Tx and Rx */
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidSend(uint8_t data)
{
	/*
	 * check the flag data register empty
	 */
	while(GET_BIT(UCSRA,UCSRA_UDRE)== 0);
	UDR = data;

}

uint8_t  USART_u8Receive(void)
{
	/* check the flag RECIEVE COMPLETE
	 * TO kNOW DATA IS RECEIVED
	 */
	while(GET_BIT(UCSRA,UCSRA_RXC)== 0);

	return UDR;

}

void USART_voidSendString(const uint8_t* ptrString){

	uint8_t u8LocalIterator = 0;

	while(ptrString[u8LocalIterator] != NULL_BYTE){

		USART_voidSend(ptrString[u8LocalIterator]);

		u8LocalIterator ++;
	}

}

void  USART_voidReceiveString( uint8_t* ptrReceviedString,uint8_t u8size){
	uint8_t u8LocalIterator = 0;
	do{

		ptrReceviedString[u8LocalIterator] = USART_u8Receive();

		u8LocalIterator++;

	}while((ptrReceviedString[u8LocalIterator] != NULL_BYTE)&&(u8LocalIterator < u8size));
}

