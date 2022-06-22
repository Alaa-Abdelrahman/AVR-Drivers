#ifndef 	I2C_INTERFACE_H_	
#define 	I2C_INTERFACE_H_

/* Enum To Handle Error Status */
typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_MT_SLA_W_Error,
	I2C_MR_SLA_R_Error,
	I2C_MT_Data_Error,
	I2C_MR_Data_Error,
	I2C_SR_Data_Error
}I2C_Error_State;

/* Prototype of the Function */

void MI2C_voidMasterInit(void);
void MI2C_voidSlaveInit(u8 Copy_u8Address);
void MI2C_voidSendStopCondition(void);
I2C_Error_State MI2C_enuSendStartCondition(void);
I2C_Error_State MI2C_enuSendRepeatedStartCondition(void);
I2C_Error_State MI2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd);
I2C_Error_State MI2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd);
I2C_Error_State MI2C_enuMasterSendDataByte(u8 Copy_u8Data);
I2C_Error_State MI2C_enuMasterReadDataByte(u8 * Copy_pu8ReturnData);
I2C_Error_State	MI2C_enuSlaveReadDataByte();

#endif	