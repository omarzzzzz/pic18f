/* 
 * File:   hal_eeprom.h
 * Author: omars
 *
 * Created on July 16, 2024, 10:49 PM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* ********************** Includes Section Start ********************** */
#include "../GPIO/hal_gpio.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType EEPROM_Data_Write_byte(uint16 bAdd,uint8 bData);
std_ReturnType EEPROM_Data_Read_byte(uint16 bAdd,uint8 *bData);
/* **********************  functions declarations Section End   ************************* */


#endif	/* HAL_EEPROM_H */

