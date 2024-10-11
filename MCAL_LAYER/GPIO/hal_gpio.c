/* 
 * File:   hal_gpio.c
 * Author: OMAR SALAH
 *
 * Created on June 21, 2024, 8:30 PM
 */
#include "hal_gpio.h"

volatile uint8 *Registers_Tris []={&TRISA , &TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *Registers_Lat []={&LATA ,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *Registers_Port []={&PORTA ,&PORTB,&PORTC,&PORTD,&PORTE};


#if PORT_PIN_CONFIG == ENABLE
std_ReturnType GPIO_SetPinDir(const pin_config_t *config_t)
{          
    std_ReturnType ret= E_OK;
    if(NULL ==config_t || config_t->pin > MAX_PIN_NUMBER-1 )
    {
        ret=E_NOT_OK;
    }
    else{
        switch(config_t->direction)
    {
        case OUTPUT :
          CLEAR_BIT(*Registers_Tris [config_t->port],config_t->pin);
           break;
        case INPUT :
          SET_BIT(*Registers_Tris [config_t->port],config_t->pin);
           break;
        
        default: ret=E_NOT_OK;
       
        
    }
    }
    
       return ret; 
}
#endif


#if PORT_PIN_CONFIG == ENABLE
std_ReturnType GPIO_ReadPinStatus(const pin_config_t *config_t,direction_t *direction_of_pin){
    std_ReturnType ret= E_OK;
 if(NULL ==config_t || NULL ==direction_of_pin || config_t->pin > MAX_PIN_NUMBER )
    {
        ret=E_NOT_OK;
    }
    else{
    *direction_of_pin= READ_BIT(*Registers_Tris [config_t->port],config_t->pin);
    }

return ret; 
}
#endif



#if PORT_PIN_CONFIG == ENABLE
std_ReturnType GPIO_WritePinLogic(const pin_config_t *config_t,logic_t logic){
    
    std_ReturnType ret= E_OK;
    if(NULL ==config_t || config_t->pin > MAX_PIN_NUMBER  )
    {
        ret=E_NOT_OK;
    }
    else{
     switch(logic)
    {
        case HIGH :
             SET_BIT(*Registers_Lat [config_t->port],config_t->pin);
          break;
        case LOW :
             CLEAR_BIT(*Registers_Lat [config_t->port],config_t->pin);
            break;
        
        default: ret=E_NOT_OK;
       
        
    }
    }

        return ret; 
}
#endif


 


#if PORT_PIN_CONFIG == ENABLE
std_ReturnType GPIO_ReadPinLogic(const pin_config_t *config_t,logic_t *logic_status){

        std_ReturnType ret= E_OK;

        if(NULL ==config_t || NULL ==logic_status || config_t->pin > MAX_PIN_NUMBER )
    {
        ret=E_NOT_OK;
    }
    else{
            *logic_status= READ_BIT(*Registers_Port [config_t->port],config_t->pin);
     
    }
        return ret; 

}
#endif



#if PORT_PIN_CONFIG == ENABLE
std_ReturnType GPIO_TogglePin(const pin_config_t *config_t){

     std_ReturnType ret= E_OK;

     if(NULL ==config_t || config_t->pin > MAX_PIN_NUMBER  )
    {
        ret=E_NOT_OK;
    }
    else{
         TOGGLE_BIT(*Registers_Lat [config_t->port],config_t->pin);
    }
        return ret; 

}
#endif


#if PORT_PIN_CONFIG == ENABLE
std_ReturnType GPIO_PinInit(const pin_config_t *config_t){
    
     std_ReturnType ret= E_OK;
    if( NULL ==config_t || config_t->pin > MAX_PIN_NUMBER  )
    {
        ret=E_NOT_OK;
    }
    else{
           ret=GPIO_SetPinDir(config_t);  
           ret=GPIO_WritePinLogic(config_t,config_t->logic);
    }
    

        return ret; 
    
    
    
}
#endif


#if PORT_CONFIG == ENABLE
std_ReturnType GPIO_SetPortDir(port_index_t port,uint8 direction){
    
     std_ReturnType ret= E_OK;


    if(port >MAX_PORT_NUMBER-1 )
    {
        ret=E_NOT_OK;
    }
    else{
     *Registers_Tris [port]=direction;
    }
        return ret; 
}
#endif


#if PORT_CONFIG == ENABLE
std_ReturnType GPIO_ReadPortStatus(port_index_t port,uint8 *direction_status){
    
     std_ReturnType ret= E_OK;
    if((NULL ==direction_status) && (port >MAX_PORT_NUMBER-1) )
    {
        ret=E_NOT_OK;
    }
    else{
     *direction_status= *Registers_Tris [port];
    }

    return ret; 
}
#endif


#if PORT_CONFIG == ENABLE
std_ReturnType GPIO_WritePortLogic(port_index_t port,uint8 logic){
     std_ReturnType ret= E_OK;

    if(port >MAX_PORT_NUMBER-1 )
    {
        ret=E_NOT_OK;
    }
    else{
     *Registers_Lat [port]=logic;
    }
        return ret; 
}
#endif

#if PORT_CONFIG == ENABLE
std_ReturnType GPIO_ReadPortLogic(port_index_t port,uint8 *logic){
    
     std_ReturnType ret= E_OK;
    if(NULL ==logic || port >MAX_PORT_NUMBER-1 )
    {
        ret=E_NOT_OK;
    }
    else{
     *logic= *Registers_Lat [port];
    }

    return ret; 
    
    
}
#endif
#if PORT_CONFIG == ENABLE
std_ReturnType GPIO_TogglePort(port_index_t port ){
     std_ReturnType ret= E_OK;

  if(port >MAX_PORT_NUMBER-1 )
    {
        ret=E_NOT_OK;
    }
    else{
    *Registers_Lat [port]=(*Registers_Lat[port]) ^ 0xFF;
    }
        return ret; 
}
    
#endif
 