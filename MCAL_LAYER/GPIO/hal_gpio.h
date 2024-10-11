/* 
 * File:   hal_gpio.h
 * Author: omars
 *
 * Created on June 21, 2024, 9:32 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/* ********************** Includes Section Start ********************** */   
#include "xc.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "gpio_config.h"
 
#define _XTAL_FREQ 8000000ul

/* ********************** Includes Section End   ********************** */




/* ********************** Macro Section Start ************************* */

#define BIT_MASK 0x01
#define MAX_PIN_NUMBER 8
#define MAX_PORT_NUMBER 5
#define PORT_PIN_CONFIG ENABLE
#define PORT_CONFIG ENABLE

/* ********************** Macro Section End   ************************* */


/* ********************** Macro functions Section Start ************************* */
#define HWREG(_X)    (*((volatile uint8*)(_X)))


#define SET_BIT(REG,BIT_POS)     REG |= (1<<BIT_POS)
#define CLEAR_BIT(REG,BIT_POS)     REG &= ~(1<<BIT_POS)
#define TOGGLE_BIT(REG,BIT_POS)     REG ^= (1<<BIT_POS)
#define READ_BIT(REG,BIT_POS)       ((REG>> BIT_POS)&1)   
/* ********************** Macro functions Section End   ************************* */



/* ********************** Data type Section Start ************************* */
typedef enum{
   LOW=0,
   HIGH
}logic_t;

typedef enum{
   OUTPUT=0,
   INPUT
}direction_t;

typedef enum{
   PIN0=0,
   PIN1,
   PIN2,
   PIN3,
   PIN4,
   PIN5,
   PIN6,
   PIN7        
}pin_index_t;


typedef enum{
   PORTA_INDEX=0,
   PORTB_INDEX,
   PORTC_INDEX,
   PORTD_INDEX,
   PORTE_INDEX      
 }port_index_t;
 
 typedef struct{
     uint8 port:3; /* @ref  port_index_t */
     uint8 pin:3;  /* @ref  pin_index_t */ 
     uint8 direction:1; /* @ref  direction_t */
     uint8 logic:1;    /* @ref  logic_t */     
 }pin_config_t;
/* ********************** Data type functions Section End   ************************* */


/* **********************  functions declarations Section Start ************************* */
std_ReturnType GPIO_SetPinDir(const pin_config_t *config_t);
std_ReturnType GPIO_ReadPinStatus(const pin_config_t *config_t,direction_t *direction_of_pin);
std_ReturnType GPIO_WritePinLogic(const pin_config_t *config_t,logic_t logic);
std_ReturnType GPIO_ReadPinLogic(const pin_config_t *config_t,logic_t *logic_status);
std_ReturnType GPIO_TogglePin(const pin_config_t *config_t);
std_ReturnType GPIO_PinInit(const pin_config_t *config_t);

std_ReturnType GPIO_SetPortDir(port_index_t port,uint8 direction);
std_ReturnType GPIO_ReadPortStatus(port_index_t port,uint8 *direction_status);
std_ReturnType GPIO_WritePortLogic(port_index_t port,uint8 logic);
std_ReturnType GPIO_ReadPortLogic(port_index_t port,uint8 *logic);
std_ReturnType GPIO_TogglePort(port_index_t port);

/* **********************  functions declarations Section End   ************************* */






#endif	/* HAL_GPIO_H */

