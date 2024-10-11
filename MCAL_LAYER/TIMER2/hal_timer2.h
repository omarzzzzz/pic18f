/* 
 * File:   hal_timer2.h
 * Author: omars
 *
 * Created on August 1, 2024, 9:21 PM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/* ********************** Includes Section Start ********************** */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */


#define TIMER2_PRESCALER_DIV_1   0
#define TIMER2_PRESCALER_DIV_4   1
#define TIMER2_PRESCALER_DIV_16  2




#define TIMER2_POSTSCALER_DIV_1  0
#define TIMER2_POSTSCALER_DIV_2  1
#define TIMER2_POSTSCALER_DIV_3  2
#define TIMER2_POSTSCALER_DIV_4  3
#define TIMER2_POSTSCALER_DIV_5  4
#define TIMER2_POSTSCALER_DIV_6  5
#define TIMER2_POSTSCALER_DIV_7  6
#define TIMER2_POSTSCALER_DIV_8  7
#define TIMER2_POSTSCALER_DIV_9  8
#define TIMER2_POSTSCALER_DIV_10  9
#define TIMER2_POSTSCALER_DIV_11  10
#define TIMER2_POSTSCALER_DIV_12  11
#define TIMER2_POSTSCALER_DIV_13  12
#define TIMER2_POSTSCALER_DIV_14  13
#define TIMER2_POSTSCALER_DIV_15  14
#define TIMER2_POSTSCALER_DIV_16  15

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
#define TIMER2_PRESCALER_SELECT(_PRESCALER_)   (T2CONbits.T2CKPS= _PRESCALER_)


#define TIMER2_POSTSCALER_SELECT(_PRESCALER_)   (T2CONbits.TOUTPS= _PRESCALER_)



#define TIMER2_ENABLE()                 (T2CONbits.TMR2ON=1)
#define TIMER2_DISABLE()                (T2CONbits.TMR2ON=0)
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


typedef struct{
#if TIMER2_INTERRUPT_ENABLE ==1
             
    INTURREPT_INTx_PRIO priority;
    void(* TIMER2_InterruptHandler)(void);
#endif 
    uint8 timer2_preload_value;
    uint8 timer2_postscaler_value: 4;
    uint8 timer2_prescaler_value: 2;
    uint8 timer2_reserved: 2;
}timer2_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Timer2_Init(const timer2_t * _timer2);
std_ReturnType Timer2_DeInit(const timer2_t * _timer2);
std_ReturnType Timer2_Write_Value(const timer2_t * _timer2, uint8 value);
std_ReturnType Timer2_Read_Value(const timer2_t * _timer2, uint8 *value);

/* **********************  functions declarations Section End   ************************* */


#endif	/* HAL_TIMER2_H */

