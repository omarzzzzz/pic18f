#include"relay.h"


std_ReturnType Relay_Init(const relay_t * relay){
    
 std_ReturnType ret= E_OK;
    if (NULL == relay)
    {
        ret=E_NOT_OK;
    }
    else{
        pin_config_t relay_obj={.port= relay->port_name,
       .pin=relay->pin_number,
       .direction=OUTPUT,
       .logic=relay->relay_status};
      GPIO_PinInit(&relay_obj);
    }
          return ret; 
   }
   

std_ReturnType Relay_TurnOn(const relay_t * relay){
    
    std_ReturnType ret= E_OK;
      if (NULL == relay)
    {
        ret=E_NOT_OK;
    }
    else{
        pin_config_t relay_obj={.port= relay->port_name,
       .pin=relay->pin_number,
       .direction=OUTPUT,
       .logic=relay->relay_status};
      GPIO_WritePinLogic(&relay_obj,HIGH);
    }
          return ret; 
    
}
std_ReturnType Relay_TurnOff(const relay_t * relay){
    
    std_ReturnType ret= E_OK;
      if (NULL == relay)
    {
        ret =E_NOT_OK;
    }
    else{
           pin_config_t relay_obj={.port= relay->port_name,
       .pin=relay->pin_number,
       .direction=OUTPUT,
       .logic=relay->relay_status};
      GPIO_WritePinLogic(&relay_obj,LOW);
    }
          return ret; 
    
    
}
