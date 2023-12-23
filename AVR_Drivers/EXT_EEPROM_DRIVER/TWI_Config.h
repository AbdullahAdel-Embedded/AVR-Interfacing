/*
 * TWI_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_CONFIG_H_
#define TWI_TWI_CONFIG_H_
/*
 * select F_OSC
 */
#define F_OSC      8000000

/*
 * select F_SCL
 */
#define F_SCL      400000
/*
 * select TWI_MODE : TWI_MASTER_MODE , TWI_SLAVE_MODE
 */
#define TWI_MODE    TWI_MASTER_MODE
/*
 * select SLAVE_ADDRESS
 */
#define SLAVE_ADDRESS   1
/*
 *
 */
#define GENERAL_CALL    1
#endif /* TWI_TWI_CONFIG_H_ */
