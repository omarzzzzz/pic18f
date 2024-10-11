/* 
 * File:   ecu_dcMotor.h
 * Author: omars
 *
 * Created on June 28, 2024, 3:35 PM
 */

#ifndef ECU_DCMOTOR_H
#define	ECU_DCMOTOR_H

/* ********************** Includes Section Start ********************** */
#include "ecu_dcMotor_cfg.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define MOTOR_ON_STATUS  0x00
#define MOTOR_OFF_STATUS 0x01
/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef struct{
       uint8 port_name: 4; /* @ref  port_index_t */
     uint8 pin_number: 3;  /* @ref  pin_index_t */ 
     uint8 motor_pin_status: 1;
}dc_motor_pin_t;


typedef struct{
dc_motor_pin_t dc_motor[2];
}dc_motor_t;

/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Motor_Init(const dc_motor_t *_dc_motor);
std_ReturnType Motor_MoveRight(const dc_motor_t *_dc_motor);
std_ReturnType Motor_MoveLeft(const dc_motor_t *_dc_motor);
std_ReturnType Motor_MoveStop(const dc_motor_t *_dc_motor);

/* **********************  functions declarations Section End   ************************* */

#endif	/* ECU_DCMOTOR_H */

