
/* 
 * File:   hal_timer0.c
 * Author: omars
 *
 * Created on July 28, 2024, 10:37 PM
 */

#include "hal_timer0.h"

static inline void Timer0_prescaler_config(const timer0_t * _timer0);
static inline void Timer0_Mode_config(const timer0_t * _timer0);
static inline void Timer0_Set_Register_Size(const timer0_t * _timer0);  



#if TIMER0_INTERRUPT_ENABLE == 1
    static void (*TIMER0_Interrupthandler)(void) = NULL;
#endif 

    static uint16 pre_load_value=0;

std_ReturnType Timer0_Init(const timer0_t * _timer0){
 std_ReturnType ret=E_OK;
    if(NULL == _timer0 )
    {
        ret=E_NOT_OK;
    }
    else
{
        TIMER0_DISABLE();
        Timer0_prescaler_config(_timer0);
        Timer0_Mode_config(_timer0);
        TMR0H= ((_timer0->preload_value) >>8 );
        TMR0L= (uint8)(_timer0->preload_value);
        pre_load_value = (_timer0->preload_value);    
#if TIMER0_INTERRUPT_ENABLE

        TIMER0_INTERRUPT_ENABLE_BIT();
        TIMER0_INTERRUPT_CLEAR_FLAG();
        TIMER0_Interrupthandler = _timer0->TIMER0_InterruptHandler;

#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
        INTERRUPT_PRIORITY_ENABLE();


        if (_timer0->priority == HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_HIGH_ENABLE();
            TIMER0_INTERRUPT_HIGH_PRIORITY();
        } else if (_timer0->priority == LOW_PRIORITY) {
            INTERRUPT_GLOBAL_LOW_ENABLE();
            TIMER0_INTERRUPT_LOW_PRIORITY();
#else
            INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_ENABLE();        
#endif
#endif
          TIMER0_ENABLE();  
    }  
    return ret;
    
}
std_ReturnType Timer0_DeInit(const timer0_t * _timer0){
   std_ReturnType ret=E_OK;
    if(NULL == _timer0 )
    {
        ret=E_NOT_OK;
    }
    else
{

        TIMER0_DISABLE();
#if TIMER0_INTERRUPT_ENABLE
        TIMER0_INTERRUPT_DISABLE_BIT();
#endif
        
    
    
    }  
    return ret;;
}
std_ReturnType Timer0_Write_Value(const timer0_t * _timer0, uint16 value){
   std_ReturnType ret=E_OK;
    if(NULL == _timer0 )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
        TMR0H= ((value) >>8 );
        TMR0L= (uint8)(value);
    
    }  
    return ret;
}
std_ReturnType Timer0_Read_Value(const timer0_t * _timer0, uint16 *value){
     std_ReturnType ret=E_OK;
    if(NULL == _timer0 )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
        *value= (uint16) ((TMR0H << 8) +(TMR0L));
    
    }  
    return ret;
    
}
        


static inline void Timer0_prescaler_config(const timer0_t * _timer0)
{
   if(TIMER_PRESCALER_ON_BIT==_timer0->prescaler_conifg) 
   {
       TIMER0_PRESCALER_ENABLE();
       T0CONbits.T0PS=_timer0->prescaler_value;
   }
   else if(TIMER_PRESCALER_OFF_BIT==_timer0->prescaler_conifg)
   {
       TIMER0_PRESCALER_DISABLE();
   }
   else{
       /* nothing*/
   }
}

static inline void Timer0_Mode_config(const timer0_t * _timer0)
{
   if(TIMER0_TIMER_MODE_BIT==_timer0->timer0_mode) 
   {
      TIMER0_TIMER_MODE_ENABLE();
      
   }
   else if(TIMER0_COUNTER_MODE_BIT==_timer0->timer0_mode)
   {
       TIMER0_COUNTER_MODE_ENABLE();
       if(TIMER0_RISING_EDGE==_timer0->edge_select)
       {
           TIMER0_RISING_EDGE_SELECT();
       }
       else if(TIMER0_FALLING_EDGE==_timer0->edge_select)
       {
            TIMER0_FALLING_EDGE_SELECT();
       }
   }
   else{
       /* nothing*/
   }
}

static inline void Timer0_Set_Register_Size(const timer0_t * _timer0)
{
   if(TIMER0_8BIT_CONFIG_BIT==_timer0->timer0_size) 
   {
       TIMER0_8bit_MODE_ENABLE();
   }
   else if(TIMER0_16BIT_CONFIG_BIT==_timer0->timer0_size)
   {
       TIMER0_16bit_MODE_ENABLE();
   }
   else{
       /* nothing*/
   }
}



void TIMER0_ISR(void){
    TIMER0_INTERRUPT_CLEAR_FLAG();
     TMR0H= ((pre_load_value) >>8 );
     TMR0L= (uint8)(pre_load_value);
    if(TIMER0_Interrupthandler){
        TIMER0_Interrupthandler();
    }
}
