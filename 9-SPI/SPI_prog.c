/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	SPI		     	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_register.h"
#include "SPI_private.h"

/**********************************************************************
* Function : SPI_voidInit(void);
*//**
* \b Description:
*This function is used to configure SPI with static configuration in config.h
*used for initialize:
*					 -mode of SPI
*                    -sending and receiving events
*                    -data order
*                    -SCK freq if SPI initlialized as master
*
*
* PRE-CONDITION: CHoose suitable configuration in config.h
*
* POST-CONDITION: SPI is configured
*
*
* @param void
*
* @return void
******************************************************************************/

void SPI_voidInit(void){

	/* define in which change read and send happen*/
#if SYNC_SAMPLING_SETUP == SAMPLE_ON_RISING_SETUP_ON_FALING

	CLR_BIT(SPCR,SPCR_CPHA);

	CLR_BIT(SPCR,SPCR_CPOL);

#elif SYNC_SAMPLING_SETUP == SAMPLE_ON_FALING_SETUP_ON_RISING

	SET_BIT(SPCR,SPCR_CPHA);

	CLR_BIT(SPCR,SPCR_CPOL);
#endif

	/*data order */
#if DATA_ORDER == MSB

	CLR_BIT(SPCR,SPCR_DORD);

#elif DATA_ORDER == LSB

	CLR_BIT(SPCR,SPCR_DORD);

#endif

	/*SPI mode of operation */
#if SPI_MODE == MASTER_MODE
	/*select master mode */
	SET_BIT(SPCR,SPCR_MSTR);

	/*Set frequency for SCK*/
	SPCR &= SCK_SPCR_MASK;

	SPCR |=SCK_FREQ;

#elif SPI_MODE == SLAVE_MODE
	/*select slave mode */
	CLR_BIT(SPCR,SPCR_MSTR);

#endif

	/*Enable SPI Module*/
	SET_BIT(SPCR,SPCR_SPE);

}

/**********************************************************************
* Function : SPI_u8TransceiveByteSYNC(uint8_t u8SentData,uint8_t *u8ptrReceivedData);
*//**
* \b Description:
*This function is used to send and receive at the same time
*
*
* PRE-CONDITION: SPI must Init before
*
*@param [in]  u8SentData that needed to send
*@param [out] u8ptrReceivedData pointer to u8 to store the received data
*
*@return void
******************************************************************************/

void SPI_voidTransceiveByteSYNC(uint8_t u8SentData,uint8_t *u8ptrReceivedData){

	/* Send the Data*/
	SPDR = u8SentData;

	/* wait until the transfer is complete */

	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	/* Get the exchanged data*/
	*u8ptrReceivedData = SPDR;

}
/**********************************************************************
* Function : SPI_voidSendChar(uint8_t Char);
*//**
* \b Description:
*This function is used to send char
*
*
* PRE-CONDITION: SPI must Init before
*
*@param [in] Char that needed to send
*
*@return void
******************************************************************************/

void SPI_voidSendChar(uint8_t Char){


	/* Send the Data*/
	SPDR = Char;

	/* wait until the transfer is complete */

	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	


}
/**********************************************************************
* Function : SPI_voidReceiveChar(uint8_t *ptrReceivedChar);
*//**
* \b Description:
*This function is used to receive char
*
*
* PRE-CONDITION: SPI must Init before
*
*@param [out] ptrReceivedChar pinter to the character that needed to receive
*
*@return void
******************************************************************************/

void SPI_voidReceiveChar(uint8_t *ptrReceivedChar){
    /*read flag to clear */
	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	/*read the received data*/
	*ptrReceivedChar = SPDR;
}
/**********************************************************************
* Function : SPI_voidSendString(const uint8_t * ptrString);
*//**
* \b Description:
*This function is used to send char
*
*
* PRE-CONDITION: SPI must Init before
*
*@param [in] ptrString pointer to string that needed to send
*
*@return void
******************************************************************************/

void SPI_voidSendString(const uint8_t * const ptrString){

	uint8_t u8LocalIterator = 0;

	while(ptrString[u8LocalIterator] != NULL_BYTE)
	{
		SPI_voidSendChar(ptrString[u8LocalIterator]);
		_delay_ms(10);

		u8LocalIterator++;
	}
	SPI_voidSendChar(NULL_BYTE);
}

/**********************************************************************
* Function : SPI_voidReceiveString(uint8_t * ptrReceivedString);
*//**
* \b Description:
*This function is used to send char
*
*
* PRE-CONDITION: SPI must Init before
*
*@param [out] ptrReceivedString pointer to string that needed to receive
*
*@return void
******************************************************************************/

void SPI_voidReceiveString(uint8_t * ptrReceivedString)
{
	uint8_t u8LocalIterator = 0;
	do{
		/*read flag to clear */
		while(GET_BIT(SPSR,SPSR_SPIF)==0);

		/*read the received data*/
		ptrReceivedString[u8LocalIterator]= SPDR;
		/*Increment the iterator*/
		u8LocalIterator++;

	}while(ptrReceivedString[u8LocalIterator] != NULL_BYTE);

}


void SPI_voidDisable(void){
	
	/*Disable SPI Module*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidEnable(void){
	/*Enable SPI Module*/
	SET_BIT(SPCR,SPCR_SPE);
}

