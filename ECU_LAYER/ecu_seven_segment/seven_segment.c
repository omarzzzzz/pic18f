#include"seven_segment.h"



std_ReturnType seven_segment_Init(const seven_segment_t * segment){
    
    std_ReturnType ret= E_OK;
    if (NULL == segment)
    {
        ret=E_NOT_OK;
    }
    else{
        ret=GPIO_PinInit(&(segment->segment_pins[0]));
        ret=GPIO_PinInit(&(segment->segment_pins[1]));
        ret=GPIO_PinInit(&(segment->segment_pins[2]));
        ret=GPIO_PinInit(&(segment->segment_pins[3]));
    }
          return ret; 
    
}
std_ReturnType seven_segment_TypeNumber(const seven_segment_t *segment, uint8 number){
    
 
     std_ReturnType ret= E_OK;
    if (NULL == segment)
    {
        ret=E_NOT_OK;
    }
    else{
       ret= GPIO_WritePinLogic(&(segment->segment_pins[0]),number & 0x01);
       ret= GPIO_WritePinLogic(&(segment->segment_pins[1]),(number>>1) & 0x01);
       ret= GPIO_WritePinLogic(&(segment->segment_pins[2]),(number>>2) & 0x01);
       ret= GPIO_WritePinLogic(&(segment->segment_pins[3]),(number>>3) & 0x01);
    }
          return ret; 
}