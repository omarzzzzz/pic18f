/* 
 * File:   relay.h
 * Author: omars
 *
 * Created on June 28, 2024, 2:29 PM
 */

#ifndef RELAY_H
#define	RELAY_H


/* ********************** Includes Section Start ********************** */
#include"relay_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define RELAY_ON_STATUS  0x00
#define RELAY_OFF_STATUS 0x01

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef struct{
       uint8 port_name: 4; /* @ref  port_index_t */
     uint8 pin_number: 3;  /* @ref  pin_index_t */ 
     uint8 relay_status: 1;
}relay_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Relay_Init(const relay_t * relay);
std_ReturnType Relay_TurnOn(const relay_t * relay);
std_ReturnType Relay_TurnOff(const relay_t * relay);
/* **********************  functions declarations Section End   ************************* */


#endif	/* RELAY_H */

