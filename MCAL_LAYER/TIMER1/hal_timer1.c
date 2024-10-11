
/* 
 * File:   hal_timer1.c
 * Author: omars
 *
 * Created on July 30, 2024, 9:51 PM
 */

#include"hal_timer1.h"

static inline void Timer1_Mode_config(const timer1_t * _timer1);


static uint16 pre_load_value=0;



#if TIMER1_INTERRUPT_ENABLE == 1
    static void (*TIMER1_Interrupthandler)(void) = NULL;
#endif 

std_ReturnType Timer1_Init(const timer1_t * _timer1){
     std_ReturnType ret=E_OK;
    if(NULL == _timer1 )
    {
        ret=E_NOT_OK;
    }
    else
{
         TIMER1_DISABLE();
        TIMER1_PRESCALER_SELECT(_timer1->timer1_prescaler_value);
        Timer1_Mode_config(_timer1);
        TMR1H= ((_timer1->timer1_preload_value) >>8 );
        TMR1L= (uint8)(_timer1->timer1_preload_value);
        pre_load_value = (_timer1->timer1_preload_value);
#if TIMER1_INTERRUPT_ENABLE
        TIMER1_INTERRUPT_ENABLE_BIT();
        TIMER1_INTERRUPT_CLEAR_FLAG();
     TIMER1_Interrupthandler = _timer1->TIMER1_InterruptHandler;
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
          INTERRUPT_PRIORITY_ENABLE();


        if (_timer1->priority == HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_HIGH_ENABLE();
            TIMER1_INTERRUPT_HIGH_PRIORITY();
        } else if (_timer1->priority == LOW_PRIORITY) {
            INTERRUPT_GLOBAL_LOW_ENABLE();
            TIMER1_INTERRUPT_LOW_PRIORITY();
#else
            INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_ENABLE();              
#endif
#endif
        TIMER1_ENABLE();
        ret=E_OK;
    }
     return ret;
}
std_ReturnType Timer1_DeInit(const timer1_t * _timer1){
      std_ReturnType ret=E_OK;
    if(NULL == _timer1 )
    {
        ret=E_NOT_OK;
    }
    else
{
        TIMER1_DISABLE();
#if TIMER1_INTERRUPT_ENABLE
        TIMER1_INTERRUPT_DISABLE_BIT();
#endif        
        
    }
     return ret;
}
std_ReturnType Timer1_Write_Value(const timer1_t * _timer1, uint16 value){
      std_ReturnType ret=E_OK;
    if(NULL == _timer1 )
    {
        ret=E_NOT_OK;
    }
    else
{
        TMR1H= ((value) >>8 );
        TMR1L= (uint8)(value);
    
        
    }
     return ret;
}
std_ReturnType Timer1_Read_Value(const timer1_t * _timer1, uint16 *value){
      std_ReturnType ret=E_OK;
    if(NULL == _timer1 )
    {
        ret=E_NOT_OK;
    }
    else
{
            *value= (uint16) ((TMR1H << 8) +(TMR1L));
        
    }
     return ret;
}

static inline void Timer1_Mode_config(const timer1_t * _timer1)
{
   if(TIMER1_TIMER_MODE_BIT==_timer1->timer1_mode) 
   {
      TIMER1_TIMER_MODE_ENABLE();
      
   }
   else if(TIMER1_COUNTER_MODE_BIT==_timer1->timer1_mode)
   {
       TIMER1_COUNTER_MODE_ENABLE();
       if(TIMER1_SYNCHRONIZE_BIT==_timer1->timer1_counter_mode)
       {
           TIMER1_SYNCHRONIZE_ENABLE();
       }
       else if(TIMER1_ASYNCHRONIZE_BIT ==_timer1->timer1_counter_mode)
       {
           TIMER1_ASYNCHRONIZE_ENABLE();
       }
   }
   else{
       /* nothing*/
   }
}




void TIMER1_ISR(void){
    TIMER1_INTERRUPT_CLEAR_FLAG();
     TMR1H= ((pre_load_value) >>8 );
     TMR1L= (uint8)(pre_load_value);
    if(TIMER1_Interrupthandler){
        TIMER1_Interrupthandler();
    }
}
