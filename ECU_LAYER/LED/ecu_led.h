/* 
 * File:   ecu_led.h
 * Author: omars
 *
 * Created on June 22, 2024, 4:58 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* ********************** Includes Section Start ********************** */
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */


/* ********************** Data type Section Start ************************* */
typedef enum{
    LED_OFF=0,
    LED_ON  
  }led_status_t;
 typedef struct{
    uint8 port_name:4;
    uint8 pin_number:3;
     uint8 logic:1;
 }led_t;
/* ********************** Data type functions Section End   ************************* */
 
 /* **********************  functions declarations Section Start ************************* */
   std_ReturnType LED_initialize(const led_t *led);
   std_ReturnType LED_Turn_on(const led_t *led);
   std_ReturnType LED_Turn_off(const led_t *led);
   std_ReturnType LED_Toggle(const led_t *led);
/* **********************  functions declarations Section End   ************************* */


#endif	/* ECU_LED_H */

