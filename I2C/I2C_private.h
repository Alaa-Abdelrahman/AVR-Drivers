#ifndef 	I2C_PRIVATE_H_	
#define 	I2C_PRIVATE_H_

/* 		Define The Register for I2c 		*/

#define 		TWBR			(*(volatile u8*) 0x20)
#define 		TWSR			(*(volatile u8*) 0x21)
#define 		TWAR			(*(volatile u8*) 0x22)
#define 		TWDR			(*(volatile u8*) 0x23)
#define 		TWCR			(*(volatile u8*) 0x56)

/* 		Definiation of TWBR Register Bits 	*/
#define 		TWBR7			7
#define 		TWBR6			6
#define 		TWBR5			5
#define 		TWBR4			4
#define 		TWBR3			3
#define 		TWBR2			2
#define 		TWBR1			1
#define 		TWBR0			0
/* 		Definiation of TWCR Register Bits 	*/
#define 		TWINT			7
#define 		TWEA			6
#define 		TWSTA			5
#define 		TWSTO			4
#define 		TWWC			3
#define 		TWEN			2
#define 		TWIE			0
/* 		Definiation of TWSR Register Bits 	*/
#define 		TWS7			7
#define 		TWS6			6
#define 		TWS5			5
#define 		TWS4			4
#define 		TWS3			3
#define 		TWPS1			1
#define 		TWPS0			0
/* 		Definiation of TWDR Register Bits 	*/
#define 		TWD7			7
#define 		TWD6			6
#define 		TWD5			5
#define 		TWD4			4
#define 		TWD3			3
#define 		TWD2			2
#define 		TWD1			1
#define 		TWD0			0
/* 		Definiation of TWAR Register Bits 	*/
#define 		TWA6			7
#define 		TWA5			6
#define 		TWA4			5
#define 		TWA3			4
#define 		TWA2			3
#define 		TWA1			2
#define 		TWA0			1
#define 		TWGCE			0

/* 		Defination Macros To Make The Code More Readable */

#define			_1_				0b00
#define			_4_				0b01
#define			_16_			0b10
#define			_64_			0b11
#define			ENABLE			1
#define			DISABLE			0

/* Define Macros For Ack of Master Transmission */

#define 		I2C_SC_ACK			0x08
#define			I2C_RSC_ACK			0x10
#define 		I2C_MT_SLA_W_ACK	0x18
#define 		I2C_MT_DATA_ACK		0x28
/* Define Macros For Ack of Master Receive */
#define 		I2C_MR_SLA_R_ACK	0x40
#define 		I2C_MR_DATA_ACK		0x50
/* Define Macros For Ack of Slave Receive */
#define			I2C_SR_DATA_W_ACK	0x60
#define			I2C_SR_DATA_R_W_ACK	0x68
#define			I2C_SR_DATA_ARR_ACK	0x80
#endif	