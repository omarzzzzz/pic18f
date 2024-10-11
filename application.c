/* 
 * File:   APP.c
 * Author: OMAR SALAH
 *
 * Created on June 21, 2024, 8:30 PM
 */


#include "application.h"
#include "MCAL_LAYER/TIMER1/hal_timer1.h"
#include "MCAL_LAYER/TIMER2/hal_timer2.h"
void App_ISR0(void);
void Timer1_DefaultHandler(void);
void timer1_timers_init(void) ;
void Timer2_DefaultHandler(void);
void Timer3_DefaultHandler(void);
void timer2_timers_init(void);
volatile uint16 timer1_flag=0;


volatile uint16 timer3_flag=0;



interrupt_INTx_t int1={
  .EXTERNAL_HANDLER= App_ISR0,
  .edge=RISING_EDGE,
  .pin.port=PORTB_INDEX,
  .pin.pin=PIN0,
  .pin.direction=INPUT,
  .source=EXT_INT0,
  .priority=HIGH_PRIORITY
    
};
led_t led_1={
.logic=LOW,
.pin_number=PIN0,
.port_name=PORTC_INDEX  
};
std_ReturnType ret= 0;
int main(){
    
        timer1_timers_init();
    while(1)
    {
        
    }
    
        return(EXIT_SUCCESS);
}



void App_ISR0(void){
    LED_Toggle(&led_1);
}
void Timer1_DefaultHandler(void){
   timer1_flag++;
}
void timer1_timers_init(void) {

    timer3_t timer3_obj;
    timer3_obj.TIMER3_InterruptHandler = Timer3_DefaultHandler;
            timer3_obj.priority = HIGH_PRIORITY;
            timer3_obj.timer3_mode = TIMER1_TIMER_MODE_BIT;
            timer3_obj.timer3_prescaler_value = TIMER0_PRESCALER_DIV_4;
            timer3_obj.timer3_preload_value = 15536;
            timer3_obj.timer3_reg_rw_mode = TIMER1_16BIT_CONFIG_BIT;
            Timer3_Init(&timer3_obj);
}
void timer1_counters_init(void) {

    timer1_t counter1_obj;
    counter1_obj.TIMER1_InterruptHandler = Timer1_DefaultHandler;
            counter1_obj.priority = HIGH_PRIORITY;
            counter1_obj.timer1_mode = TIMER1_COUNTER_MODE_BIT;
            counter1_obj.timer1_counter_mode=TIMER1_SYNCHRONIZE_BIT;
            counter1_obj.timer1_preload_value=0;
            counter1_obj.timer1_prescaler_value=TIMER0_PRESCALER_DIV_1;
            counter1_obj.timer1_reg_rw_mode = TIMER1_16BIT_CONFIG_BIT;
            Timer1_Init(&counter1_obj);
}

/*                       TIMER 2                                    */

void timer2_timers_init(void) {

    timer2_t timer2_obj;
    timer2_obj.TIMER2_InterruptHandler = Timer2_DefaultHandler;
    timer2_obj.priority=LOW_PRIORITY;
    timer2_obj.timer2_preload_value=249;
    timer2_obj.timer2_prescaler_value= TIMER2_PRESCALER_DIV_1;
    timer2_obj.timer2_postscaler_value=TIMER2_POSTSCALER_DIV_16;
          Timer2_Init(&timer2_obj); 
}
void Timer2_DefaultHandler(void){
    timer1_flag++;
}


void Timer3_DefaultHandler(void){
    timer3_flag++;
}