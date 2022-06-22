/* Import The Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <math.h>
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"


/********************************************************************************************************************************
 * Parameters:(in) : None
 * Parameters:(out): None
 * Return value	  : None
 * Description	  : Function used to initialize the I2C as Master based on the Configuration file
 **********************************************************************************************************************************/

void MI2C_voidMasterInit(void)
{
	/* Set Prescaler */
	TWSR |= I2C_PRESCALER ;
	/* set SCL CLock */
	TWBR = BITRATE;
	/* If Ack Bit is Enable */
#if		I2C_ACK_BIT == ENABLE
	SET_BIT (TWCR,TWEA);
	/* If Ack Bit is Disable */
#elif 	I2C_ACK_BIT == DISABLE
	CLR_BIT (TWCR,TWEA);
#endif
	/* If I2c Interrupt Enable */
#if I2C_INTERRUPT == ENABLE
	SET_BIT (TWCR , TWIE );
	/* If I2c Interrupt Disable */
#elif I2C_INTERRUPT == DISABLE
	CLR_BIT (TWCR , TWIE );
#endif
	/* If Recognition Bit is Enable */
#if I2C_RECOGNITION_BIT	==	ENABLE
	SET_BIT (TWAR , TWGCE );
	/* If Recognition Bit is Disable */
#elif I2C_RECOGNITION_BIT ==	DISABLE
	CLR_BIT (TWAR , TWGCE );
#endif
	/* Enable I2c */
#if I2C == ENABLE
	SET_BIT (TWCR , TWEN );
	/* DISABLE I2c */
#elif I2C == DISABLE
	CLR_BIT (TWCR , TWEN );
#endif
}

/********************************************************************************************************************************
 * Parameters:(in) : None
 * Parameters:(out): None
 * Return value	  : None
 * Description	  : Function used to initialize the I2C as Slave based on the Configuration file
 **********************************************************************************************************************************/

void MI2C_voidSlaveInit(u8 Copy_u8Address)
{
	/* Set Slave Address */
	TWAR |= (Copy_u8Address<<1);
	/* If Ack Bit is Enable */
#if		I2C_ACK_BIT == ENABLE
	SET_BIT (TWCR,TWEA);
	/* If Ack Bit is Disable */
#elif 	I2C_ACK_BIT == DISABLE
	CLR_BIT (TWCR,TWEA);
#endif
	/* Enable I2c */
#if I2C == ENABLE
	SET_BIT (TWCR , TWEN );
	/* DISABLE I2c */
#elif I2C == DISABLE
	CLR_BIT (TWCR , TWEN );
#endif

}

/********************************************************************************************************************************
 * Parameters:(in) : None
 * Parameters:(out): None
 * Return value	  : ENUM Error
 * Description	  : Function used to Send The Start Condition to Start The Communication
 **********************************************************************************************************************************/

I2C_Error_State MI2C_enuSendStartCondition(void)
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;
	/* Set Start Condition Bit */
	SET_BIT (TWCR , TWSTA );
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status different from 0x08 go to ERROR */
	if ((TWSR & 0xF8) != I2C_SC_ACK)
	{
		/* Makw State Error */
		local_enuReturnState = I2C_SC_Error ;
	}
	/* Return The Sate */
	return local_enuReturnState ;
}

/********************************************************************************************************************************
 * Parameters:(in) : None
 * Parameters:(out): None
 * Return value	  : ENUM Error
 * Description	  : Function used to Send Repeated Start Condition
 **********************************************************************************************************************************/
I2C_Error_State MI2C_enuSendRepeatedStartCondition(void)
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;
	/* Set Start Condition Bit */
	SET_BIT (TWCR , TWSTA );
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status different from 0x10 go to ERROR */
	if ((TWSR & 0xF8) != I2C_RSC_ACK)
	{
		/* Makw State Error */
		local_enuReturnState = I2C_SC_Error ;
	}
	/* Return The Sate */
	return local_enuReturnState ;
}


/********************************************************************************************************************************
 * Parameters:(in) : Address of The Target Slave
 * Parameters:(out): None
 * Return value	  : ENUM Error
 * Description	  : Function used to Send The Address Of The Slave With Write Operation
 **********************************************************************************************************************************/
I2C_Error_State MI2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd)
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;

	/* Set Slave Address */
	TWDR = (Copy_u8SlaveAdd << 1 );
	/* Make Write Operation */
	CLR_BIT (TWDR , TWD0 );
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status different from 0x08 go to ERROR */
	if ((TWSR & 0xF8) != I2C_MT_SLA_W_ACK)
	{
		/* Makw State Error */
		local_enuReturnState = I2C_MT_SLA_W_Error ;
	}
	/* Return The Sate */
	return local_enuReturnState ;
}

/********************************************************************************************************************************
 * Parameters:(in) : Address of The Target Slave
 * Parameters:(out): None
 * Return value	  : ENUM Error
 * Description	  : Function used to Send The Address Of The Slave With Read Operation
 **********************************************************************************************************************************/
I2C_Error_State MI2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd)
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;
	/* Set Slave Address */
	TWDR = (Copy_u8SlaveAdd << 1 );
	/* Make Read Operation */
	SET_BIT (TWDR , TWD0 );
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status different from 0x08 go to ERROR */
	if ((TWSR & 0xF8) != I2C_MR_SLA_R_ACK)
	{
		/* Make State Error */
		local_enuReturnState = I2C_MR_SLA_R_Error ;
	}
	/* Return The Sate */
	return local_enuReturnState ;

}

/********************************************************************************************************************************
 * Parameters:(in) : 8 Bit Data To Send
 * Parameters:(out): None
 * Return value	  : ENUM Error
 * Description	  : Function used to Send Byte of Data From Master Through I2C
 **********************************************************************************************************************************/

I2C_Error_State MI2C_enuMasterSendDataByte(u8 Copy_u8Data)
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;
	/* Set Data */
	TWDR = Copy_u8Data ;
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status different from 0x08 go to ERROR */
	if ((TWSR & 0xF8) != I2C_MT_DATA_ACK)
	{
		/* Make State Error */
		local_enuReturnState = I2C_MT_Data_Error ;
	}
	/* Return The Sate */
	return local_enuReturnState ;

}

/********************************************************************************************************************************
 * Parameters:(in) : Pointer Holds The Returned Data
 * Parameters:(out): Pointer Holds The Returned Data
 * Return value	  : ENUM Error
 * Description	  : Function used to Read The Data That Send From The Slave
 **********************************************************************************************************************************/
I2C_Error_State MI2C_enuMasterReadDataByte(u8 * Copy_pu8ReturnData)
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status different from 0x08 go to ERROR */
	if ((TWSR & 0xF8) != I2C_MR_DATA_ACK)
	{
		/* Makw State Error */
		local_enuReturnState = I2C_MR_Data_Error ;
	}
	else 
	{
		/* Get The Data From The Register */
		*Copy_pu8ReturnData = TWDR ;
	}

	/* Return The Sate */
	return local_enuReturnState ;
}

/********************************************************************************************************************************
 * Parameters:(in) : None
 * Parameters:(out): None
 * Return value	  : None
 * Description	  : Function used toSend Stop Condition To End The Communication
 **********************************************************************************************************************************/

void MI2C_voidSendStopCondition(void)
{
	/* Set Stop Condition bit */
	SET_BIT(TWCR,TWSTO);

	/* Clear Interrupt Flag */
	SET_BIT(TWCR,TWINT);
}

/********************************************************************************************************************************
 * Parameters:(in) : None
 * Parameters:(out): None
 * Return value	  : ENUM Error
 * Description	  : Function used to Read The Data That Send From The Master To The Slave
 **********************************************************************************************************************************/
I2C_Error_State	MI2C_enuSlaveReadDataByte()
{
	/* Make State OK */
	I2C_Error_State local_enuReturnState = I2C_Ok ;
	/* Clear Interrupt Flag */
	SET_BIT (TWCR , TWINT );
	/* Wait until TWI finish its current job */
	while (!GET_BIT(TWCR , TWINT ));
	/* Check value of TWI Status Register If status equal to  0x60 */
	if ( ( (TWSR & 0xF8) == I2C_SR_DATA_W_ACK ) )
	{
		/* Clear Interrupt Flag */
		SET_BIT (TWCR , TWINT );
		/* Wait until TWI finish its current job */
		while (!GET_BIT(TWCR , TWINT ));
		/* Check value of TWI Status Register If status Differ From 0x80 Go To Error  */
		if (( (TWSR & 0xF8) != I2C_SR_DATA_ARR_ACK ) )
			/* Make State Error */
			local_enuReturnState = I2C_SR_Data_Error ;
		else
			/* Return The Data */
			return   TWDR ;
	}
	else
		/* Make State Error */
		local_enuReturnState = I2C_SR_Data_Error ;

	/* Return The Sate */
	return local_enuReturnState ;

}



































