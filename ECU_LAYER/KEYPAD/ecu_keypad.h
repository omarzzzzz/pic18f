/* 
 * File:   ecu_keypad.h
 * Author: omars
 *
 * Created on July 2, 2024, 2:24 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
/* ********************** Includes Section Start ********************** */
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define ROW_PINS 4
#define COLOUMN_PINS 4


/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef struct{
    pin_config_t rows[ROW_PINS];
    pin_config_t coloumns[COLOUMN_PINS];
}keypad_t;

/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Keypad_init(const keypad_t* keypad);
std_ReturnType Keypad_write(const keypad_t* keypad, uint8*value);
/* **********************  functions declarations Section End   ************************* */


#endif	/* ECU_KEYPAD_H */

