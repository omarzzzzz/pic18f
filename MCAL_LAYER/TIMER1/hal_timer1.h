/* 
 * File:   hal_timer1.h
 * Author: omars
 *
 * Created on July 30, 2024, 9:51 PM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/* ********************** Includes Section Start ********************** */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */



#define TIMER1_TIMER_MODE_BIT   1
#define TIMER1_COUNTER_MODE_BIT 0

#define TIMER1_8BIT_CONFIG_BIT  1
#define TIMER1_16BIT_CONFIG_BIT 0

#define TIMER1_SYNCHRONIZE_BIT   0 //ONLY IN COUNTER MODE
#define TIMER1_ASYNCHRONIZE_BIT  1

#define TIMER1_OSC_BIT_ON    1
#define TIMER1_OSC_BIT_OFF   0

#define TIMER0_PRESCALER_DIV_1  0
#define TIMER0_PRESCALER_DIV_2  1
#define TIMER0_PRESCALER_DIV_4  2
#define TIMER0_PRESCALER_DIV_8  3

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
#define TIMER1_PRESCALER_SELECT(_PRESCALER_)   (T1CONbits.T1CKPS= _PRESCALER_)

#define TIMER1_OSCILLATOR_ENABLE()      (T1CONbits.T1OSCEN=1)
#define TIMER1_OSCILLATOR_DISABLE()     (T1CONbits.T1OSCEN=0)


#define TIMER1_SYNCHRONIZE_ENABLE()    (T1CONbits.T1SYNC=0)    //ONLY IN COUNTER MODE 
#define TIMER1_ASYNCHRONIZE_ENABLE()   (T1CONbits.T1SYNC=1)

#define TIMER1_TIMER_MODE_ENABLE()      (T1CONbits.TMR1CS=0)
#define TIMER1_COUNTER_MODE_ENABLE()    (T1CONbits.TMR1CS=1)

#define TIMER1_8bit_MODE_ENABLE()       (T1CONbits.RD16=0)
#define TIMER1_16bit_MODE_ENABLE()      (T1CONbits.RD16=1)

#define TIMER1_SYSTEM_CLK_STATUS()      (T1CONbits.T1RUN)

#define TIMER1_ENABLE()                 (T1CONbits.TMR1ON=1)
#define TIMER1_DISABLE()                (T1CONbits.TMR1ON=0)
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


typedef struct{
#if TIMER1_INTERRUPT_ENABLE ==1
             
    INTURREPT_INTx_PRIO priority;
    void(* TIMER1_InterruptHandler)(void);
#endif 
    uint16 timer1_preload_value;
    uint8 timer1_mode : 1;
    uint8 timer1_counter_mode:1;
    uint8 timer1_osc_config : 1;
    uint8 timer1_prescaler_value: 2;
    uint8 timer1_reg_rw_mode:1;
    uint8 timer1_reserved:2;
}timer1_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Timer1_Init(const timer1_t * _timer1);
std_ReturnType Timer1_DeInit(const timer1_t * _timer1);
std_ReturnType Timer1_Write_Value(const timer1_t * _timer1, uint16 value);
std_ReturnType Timer1_Read_Value(const timer1_t * _timer1, uint16 *value);

/* **********************  functions declarations Section End   ************************* */


#endif	/* HAL_TIMER1_H */

