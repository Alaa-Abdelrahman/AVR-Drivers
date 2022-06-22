/**********************************************************************/
/**********************************************************************/
/*****************		Author: Alaa		    ***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	SPI		     	***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define NULL_BYTE  '\0'

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

void SPI_voidInit(void);

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

void SPI_voidTransceiveByteSYNC(uint8_t u8SentData,uint8_t *u8ptrReceivedData);

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
void SPI_voidSendChar(uint8_t Char);

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
void SPI_voidReceiveChar(uint8_t *ptrReceivedChar);

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
void SPI_voidSendString(const uint8_t * ptrString);
/**********************************************************************
* Function : SPI_voidReceivedString(uint8_t * ptrReceivedString);
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
void SPI_voidReceiveString(uint8_t * ptrReceivedString);



void SPI_voidDisable(void);

void SPI_voidEnable(void);















#endif
