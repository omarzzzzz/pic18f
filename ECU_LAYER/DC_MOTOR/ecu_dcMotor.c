

#include"ecu_dcMotor.h"


static pin_config_t motor_pin1_obj;
static pin_config_t motor_pin2_obj;


std_ReturnType Motor_Init(const dc_motor_t *_dc_motor){
   std_ReturnType ret= E_OK;
    if (NULL == _dc_motor)
    {
        ret=E_NOT_OK;
    }
    else{
        motor_pin1_obj.port=_dc_motor->dc_motor[0].port_name;
        motor_pin1_obj.pin=_dc_motor->dc_motor[0].pin_number;
        motor_pin1_obj.logic=_dc_motor->dc_motor[0].motor_pin_status;
        motor_pin1_obj.direction=OUTPUT;
         motor_pin2_obj.port=_dc_motor->dc_motor[0].port_name;
        motor_pin2_obj.pin=_dc_motor->dc_motor[0].pin_number;
        motor_pin2_obj.logic=_dc_motor->dc_motor[0].motor_pin_status;
        motor_pin2_obj.direction=OUTPUT;
        
      GPIO_PinInit(&motor_pin1_obj);
      GPIO_PinInit(&motor_pin2_obj);
    }
          return ret; 
    
    
}
std_ReturnType Motor_MoveRight(const dc_motor_t *_dc_motor){
      std_ReturnType ret= E_OK;
    if (NULL == _dc_motor)
    {
        ret=E_NOT_OK;
    }
    else{
      
        
      GPIO_WritePinLogic(&motor_pin1_obj,HIGH);
      GPIO_WritePinLogic(&motor_pin2_obj,LOW);
    }
          return ret; 
    
    
}
std_ReturnType Motor_MoveLeft(const dc_motor_t *_dc_motor){
         std_ReturnType ret= E_OK;
    if (NULL == _dc_motor)
    {
        ret=E_NOT_OK;
    }
    else{
       
        
      GPIO_WritePinLogic(&motor_pin1_obj,LOW);
      GPIO_WritePinLogic(&motor_pin2_obj,HIGH);
    }
          return ret; 
    
    
}
std_ReturnType Motor_MoveStop(const dc_motor_t *_dc_motor){
    
         std_ReturnType ret= E_OK;
    if (NULL == _dc_motor)
    {
        ret=E_NOT_OK;
    }
    else{
       
        
      GPIO_WritePinLogic(&motor_pin1_obj,LOW);
      GPIO_WritePinLogic(&motor_pin2_obj,LOW);
    }
          return ret; 
    
}

