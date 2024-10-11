/* 
 * File:   button.h
 * Author: omars
 *
 * Created on June 27, 2024, 6:43 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

/* ********************** Includes Section Start ********************** */
#include "button_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"

/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */


/* ********************** Data type Section Start ************************* */

typedef enum{
    BUTTON_PRESSED,// 0 when pressed
    BUTTON_RELEASED        // 1 when released
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW        
}button_connection_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_connection_t button_connection;
            
}button_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType ButtonInit(const button_t *btn);
std_ReturnType ButtonReadState(const button_t *btn, button_state_t *btn_state);
/* **********************  functions declarations Section End   ************************* */



#endif	/* BUTTON_H */

