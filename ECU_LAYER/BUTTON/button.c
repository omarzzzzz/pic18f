/* 
 * File:   button.c
 * Author: omars
 *
 * Created on June 27, 2024, 6:43 PM
 */

#include "button.h"
std_ReturnType ButtonInit(const button_t *btn){
    std_ReturnType ret= E_OK;
      
           
     
    if(NULL == btn)
    {
        ret=E_NOT_OK;
    }
    else{
      ret=GPIO_SetPinDir(&(btn->button_pin));
    }
          return ret; 
    
    
}
std_ReturnType ButtonReadState(const button_t *btn, button_state_t *btn_state){
    std_ReturnType ret= E_OK;
    logic_t logic_button_state= LOW;
     if(NULL == btn  || NULL == btn_state )
    {
        ret=E_NOT_OK;
    }
    else{
         GPIO_ReadPinLogic(&(btn->button_pin),&logic_button_state);
         if(btn->button_connection== BUTTON_ACTIVE_HIGH)
         {
             if(logic_button_state== HIGH )
             {
                 *btn_state =BUTTON_PRESSED ;
                 
             }
             else
             {
                 *btn_state = BUTTON_RELEASED;
             }
         }
         else
         {
             if(logic_button_state== LOW)
             {
                  *btn_state =BUTTON_PRESSED ;
             }
             else
             {
                 *btn_state = BUTTON_RELEASED;
             }
         }
         }
    return ret; 
    }
          
    
    
