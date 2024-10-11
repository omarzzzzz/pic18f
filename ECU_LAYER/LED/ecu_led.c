/* 
 * File:   ecu_led.h
 * Author: omars
 *
 * Created on June 22, 2024, 4:58 PM
 */


#include "ecu_led.h"



   std_ReturnType LED_initialize(const led_t *led){
       
       std_ReturnType ret= E_OK;
      
           
     
    if(NULL == led)
    {
        ret=E_NOT_OK;
    }
    else{
         pin_config_t led_obj={.port= led->port_name,
       .pin=led->pin_number,
       .direction=OUTPUT,
       .logic=led->logic};
      GPIO_PinInit(&led_obj);
    }
          return ret; 
   }
   std_ReturnType LED_Turn_on(const led_t *led){
           std_ReturnType ret= E_OK;
    if(NULL ==led)
    {
        ret=E_NOT_OK;
    }
    else{
          pin_config_t led_obj={.port= led->port_name,
       .pin=led->pin_number,
       .direction=OUTPUT,
       .logic=led->logic};
          GPIO_WritePinLogic(&led_obj,HIGH);
    }
          return ret;
       
       
   }
   std_ReturnType LED_Turn_off(const led_t *led){
           std_ReturnType ret= E_OK;
            if(NULL ==led)
    {
        ret=E_NOT_OK;
    }
    else{
         pin_config_t led_obj={.port= led->port_name,
       .pin=led->pin_number,
       .direction=OUTPUT,
       .logic=led->logic};
          GPIO_WritePinLogic(&led_obj,LOW);
    }
          return ret;
       
       
   }
   std_ReturnType LED_Toggle(const led_t *led){
           std_ReturnType ret= E_OK;
             if(NULL ==led)
    {
        ret=E_NOT_OK;
    }
    else{
          pin_config_t led_obj={.port= led->port_name,
       .pin=led->pin_number,
       .logic=led->logic};
          GPIO_TogglePin(&led_obj);
    }
          return ret;
       
   }
