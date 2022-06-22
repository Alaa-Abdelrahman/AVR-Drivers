#ifndef 	I2C_CONFIG_H_	
#define 	I2C_CONFIG_H_

/* OPTIONS
	* ENABLE
	* DISABLE
*/

#define 	I2C						ENABLE

/* OPTIONS
	* ENABLE
	* DISABLE
*/
#define 	I2C_INTERRUPT			DISABLE
	
/* OPTIONS
	* ENABLE
	* DISABLE
*/
#define 	I2C_ACK_BIT				ENABLE

/*	OPTIONS
	* _1_
	* _4_
	* _16_
	* _64_
*/
#define 	I2C_PRESCALER			_1_

/* OPTIONS
	* ENABLE
	* DISABLE
*/
#define		I2C_RECOGNITION_BIT		DISABLE

#define		SCL_CLK					100000
#define		F_CPU					8000000
/* BIT Rate Macro Function */
#define BITRATE				((F_CPU/SCL_CLK)-16)/(2*pow(4,((I2C_PRESCALER))))

#endif	