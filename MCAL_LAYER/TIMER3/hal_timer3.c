#include "hal_timer3.h"

static inline void Timer3_Mode_config(const timer3_t * _timer3);



#if TIMER3_INTERRUPT_ENABLE == 1
    static void (*TIMER3_Interrupthandler)(void) = NULL;
#endif 
    
    
    static uint16 pre_load_value=0;
    
std_ReturnType Timer3_Init(const timer3_t * _timer3){
         std_ReturnType ret=E_OK;
    if(NULL == _timer3 )
    {
        ret=E_NOT_OK;
    }
    else
{
         TIMER3_DISABLE();
        TIMER3_PRESCALER_SELECT(_timer3->timer3_prescaler_value);
        Timer3_Mode_config(_timer3);
        TMR3H= ((_timer3->timer3_preload_value) >>8 );
        TMR3L= (uint8)(_timer3->timer3_preload_value);
        pre_load_value = (_timer3->timer3_preload_value);
#if TIMER3_INTERRUPT_ENABLE
        TIMER3_INTERRUPT_ENABLE_BIT();
        TIMER3_INTERRUPT_CLEAR_FLAG();
     TIMER3_Interrupthandler = _timer3->TIMER3_InterruptHandler;
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
          INTERRUPT_PRIORITY_ENABLE();


        if (_timer3->priority == HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_HIGH_ENABLE();
            TIMER3_INTERRUPT_HIGH_PRIORITY();
        } else if (_timer3->priority == LOW_PRIORITY) {
            INTERRUPT_GLOBAL_LOW_ENABLE();
            TIMER1_INTERRUPT_LOW_PRIORITY();
#else
            INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_ENABLE();              
#endif
#endif
        TIMER3_ENABLE();
        ret=E_OK;
    }
     return ret;
}
std_ReturnType Timer3_DeInit(const timer3_t * _timer3){
     std_ReturnType ret=E_OK;
    if(NULL == _timer3 )
    {
        ret=E_NOT_OK;
    }
    else
{
        TIMER3_DISABLE();
#if TIMER3_INTERRUPT_ENABLE
        TIMER3_INTERRUPT_DISABLE_BIT();
#endif        
        
    }
     return ret;
}
std_ReturnType Timer3_Write_Value(const timer3_t * _timer3, uint16 value){
      std_ReturnType ret=E_OK;
    if(NULL == _timer3 )
    {
        ret=E_NOT_OK;
    }
    else
{
        TMR3H= ((value) >>8 );
        TMR3L= (uint8)(value);
    
        
    }
     return ret;
}
std_ReturnType Timer3_Read_Value(const timer3_t * _timer3, uint16 *value){
      std_ReturnType ret=E_OK;
    if(NULL == _timer3 )
    {
        ret=E_NOT_OK;
    }
    else
{
            *value= (uint16) ((TMR3H << 8) +(TMR3L));
        
    }
     return ret;
}


static inline void Timer3_Mode_config(const timer3_t * _timer3)
{
   if(TIMER3_TIMER_MODE_BIT==_timer3->timer3_mode) 
   {
      TIMER3_TIMER_MODE_ENABLE();
      
   }
   else if(TIMER3_COUNTER_MODE_BIT==_timer3->timer3_mode)
   {
       TIMER3_COUNTER_MODE_ENABLE();
       if(TIMER3_SYNCHRONIZE_BIT==_timer3->timer3_counter_mode)
       {
           TIMER3_SYNCHRONIZE_ENABLE();
       }
       else if(TIMER3_ASYNCHRONIZE_BIT ==_timer3->timer3_counter_mode)
       {
           TIMER3_ASYNCHRONIZE_ENABLE();
       }
   }
   else{
       /* nothing*/
   }
}




void TIMER3_ISR(void){
    TIMER3_INTERRUPT_CLEAR_FLAG();
     TMR3H= ((pre_load_value) >>8 );
     TMR3L= (uint8)(pre_load_value);
    if(TIMER3_Interrupthandler){
        TIMER3_Interrupthandler();
    }
}
