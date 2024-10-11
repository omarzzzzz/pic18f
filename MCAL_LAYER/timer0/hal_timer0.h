/* 
 * File:   hal_timer0.h
 * Author: omars
 *
 * Created on July 28, 2024, 10:37 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H
 

/* ********************** Includes Section Start ********************** */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define TIMER_PRESCALER_ON_BIT      1 
#define TIMER_PRESCALER_OFF_BIT     0

#define TIMER0_RISING_EDGE  1
#define TIMER0_FALLING_EDGE 0

#define TIMER0_TIMER_MODE_BIT   1
#define TIMER0_COUNTER_MODE_BIT 0

#define TIMER0_8BIT_CONFIG_BIT  1
#define TIMER0_16BIT_CONFIG_BIT 0

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
#define TIMER0_PRESCALER_ENABLE()     (T0CONbits.PSA=0)
#define TIMER0_PRESCALER_DISABLE()    (T0CONbits.PSA=1)

#define TIMER0_RISING_EDGE_SELECT()   (T0CONbits.T0SE=0)
#define TIMER0_FALLING_EDGE_SELECT()  (T0CONbits.T0SE=1)

#define TIMER0_TIMER_MODE_ENABLE()    (T0CONbits.T0CS=0)
#define TIMER0_COUNTER_MODE_ENABLE()  (T0CONbits.T0CS=1)

#define TIMER0_8bit_MODE_ENABLE()    (T0CONbits.T08BIT=1)
#define TIMER0_16bit_MODE_ENABLE()   (T0CONbits.T08BIT=0)

#define TIMER0_ENABLE()              (T0CONbits.TMR0ON=1)
#define TIMER0_DISABLE()             (T0CONbits.TMR0ON=0)
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */

typedef enum {
    TIMER0_PRESCALER_DIV_2 = 0,
    TIMER0_PRESCALER_DIV_4,
    TIMER0_PRESCALER_DIV_8,
    TIMER0_PRESCALER_DIV_16,
    TIMER0_PRESCALER_DIV_32,
    TIMER0_PRESCALER_DIV_64,
    TIMER0_PRESCALER_DIV_128,
    TIMER0_PRESCALER_DIV_256
    
}timer0_prescaler_select_t;

typedef struct{
#if TIMER0_INTERRUPT_ENABLE ==1
             
    INTURREPT_INTx_PRIO priority;
    void(* TIMER0_InterruptHandler)(void);
#endif 
    uint16 preload_value;
    uint8 timer0_size : 1;
    uint8 edge_select : 1;
    uint8 prescaler_conifg : 1;
    uint8 timer0_mode : 1;
    timer0_prescaler_select_t prescaler_value;
    uint8 timer0_reserved:4;
}timer0_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Timer0_Init(const timer0_t * _timer0);
std_ReturnType Timer0_DeInit(const timer0_t * _timer0);
std_ReturnType Timer0_Write_Value(const timer0_t * _timer0, uint16 value);
std_ReturnType Timer0_Read_Value(const timer0_t * _timer0, uint16 *value);

/* **********************  functions declarations Section End   ************************* */



#endif	/* HAL_TIMER0_H */

