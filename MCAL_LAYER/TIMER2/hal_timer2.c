/* 
 * File:   hal_timer2.c
 * Author: omars
 *
 * Created on August 1, 2024, 9:21 PM
 */
#include"hal_timer2.h"
#if TIMER2_INTERRUPT_ENABLE == 1
    static void (*TIMER2_Interrupthandler)(void) = NULL;
#endif
    
    static uint8 preload_value=0;



std_ReturnType Timer2_Init(const timer2_t * _timer2) {

    TIMER2_DISABLE();
    TIMER2_PRESCALER_SELECT(_timer2->timer2_prescaler_value);
    TIMER2_POSTSCALER_SELECT(_timer2->timer2_postscaler_value);
    TMR2 = _timer2->timer2_preload_value;
    preload_value = _timer2->timer2_preload_value;
#if TIMER1_INTERRUPT_ENABLE
    TIMER2_INTERRUPT_ENABLE_BIT();
    TIMER2_INTERRUPT_CLEAR_FLAG();
    TIMER2_Interrupthandler = _timer2->TIMER2_InterruptHandler;
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
    INTERRUPT_PRIORITY_ENABLE();


    if (_timer2->priority == HIGH_PRIORITY) {
        INTERRUPT_GLOBAL_HIGH_ENABLE();
        TIMER1_INTERRUPT_HIGH_PRIORITY();
    } else if (_timer2->priority == LOW_PRIORITY) {
        INTERRUPT_GLOBAL_LOW_ENABLE();
        TIMER1_INTERRUPT_LOW_PRIORITY();
    }
#else
    INTERRUPT_GLOBAL_ENABLE();
    INTERRUPT_PERIPHERAL_ENABLE();
#endif
#endif
        TIMER2_ENABLE();

}
std_ReturnType Timer2_DeInit(const timer2_t * _timer2){
            TIMER2_DISABLE();
#if TIMER2_INTERRUPT_ENABLE
        TIMER2_INTERRUPT_DISABLE_BIT();
#endif        
        
}
std_ReturnType Timer2_Write_Value(const timer2_t * _timer2, uint8 value){
             TMR2=value;
}
std_ReturnType Timer2_Read_Value(const timer2_t * _timer2, uint8*value){
             *value=TMR2;
}


void TIMER2_ISR(void){
    TIMER1_INTERRUPT_CLEAR_FLAG();
    TMR2 = preload_value;
    if(TIMER2_Interrupthandler){
        TIMER2_Interrupthandler();
    }
}
