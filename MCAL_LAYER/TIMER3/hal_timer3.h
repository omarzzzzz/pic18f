/* 
 * File:   hal_timer3.h
 * Author: omars
 *
 * Created on August 1, 2024, 9:21 PM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H

/* ********************** Includes Section Start ********************** */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

#define TIMER3_TIMER_MODE_BIT   1
#define TIMER3_COUNTER_MODE_BIT 0

#define TIMER3_8BIT_CONFIG_BIT  1
#define TIMER3_16BIT_CONFIG_BIT 0

#define TIMER3_SYNCHRONIZE_BIT   0 //ONLY IN COUNTER MODE
#define TIMER3_ASYNCHRONIZE_BIT  1

#define TIMER3_PRESCALER_DIV_1  0
#define TIMER3_PRESCALER_DIV_2  1
#define TIMER3_PRESCALER_DIV_4  2
#define TIMER3_PRESCALER_DIV_8  3

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
#define TIMER3_PRESCALER_SELECT(_PRESCALER_)   (T3CONbits.T3CKPS= _PRESCALER_)



#define TIMER3_SYNCHRONIZE_ENABLE()    (T3CONbits.T3SYNC=0)    //ONLY IN COUNTER MODE 
#define TIMER3_ASYNCHRONIZE_ENABLE()   (T3CONbits.T3SYNC=1)

#define TIMER3_TIMER_MODE_ENABLE()      (T3CONbits.TMR3CS=0)
#define TIMER3_COUNTER_MODE_ENABLE()    (T3CONbits.TMR3CS=1)

#define TIMER3_8bit_MODE_ENABLE()       (T3CONbits.RD16=0)
#define TIMER3_16bit_MODE_ENABLE()      (T3CONbits.RD16=1)

#define TIMER3_ENABLE()                 (T3CONbits.TMR3ON=1)
#define TIMER3_DISABLE()                (T3CONbits.TMR3ON=0)
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


typedef struct{
#if TIMER3_INTERRUPT_ENABLE ==1
             
    INTURREPT_INTx_PRIO priority;
    void(* TIMER3_InterruptHandler)(void);
#endif 
    uint16 timer3_preload_value;
    uint8 timer3_mode : 1;
    uint8 timer3_counter_mode:1;
    uint8 timer3_prescaler_value: 2;
    uint8 timer3_reg_rw_mode:1;
    uint8 timer3_reserved:3;
}timer3_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Timer3_Init(const timer3_t * _timer3);
std_ReturnType Timer3_DeInit(const timer3_t * _timer3);
std_ReturnType Timer3_Write_Value(const timer3_t * _timer3, uint16 value);
std_ReturnType Timer3_Read_Value(const timer3_t * _timer3, uint16 *value);



#endif	/* HAL_TIMER3_H */

