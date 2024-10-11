/* 
 * File:   mcal_interrupt_config.h
 * Author: omars
 *
 * Created on July 12, 2024, 9:11 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H
/* ********************** Includes Section Start ********************** */
#include "xc.h"
#include "../mcal_std_types.h"
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"

/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define INTERUPT_ENABLE   1
#define INTERUPT_DISABLE  0
#define INTERUPT_PRIORITY_ENABLE  1
#define INTERUPT_PRIORITY_DISABLE 0
#define INTERUPT_OCCUR      1
#define INTERUPT_NOT_OCCUR  0

#define ADC_INTERRUPT_ENABLE 1 // ADCCCCCCCCCCCCCCCCC
#define TIMER0_INTERRUPT_ENABLE 1 // TIMERRR0 
#define TIMER1_INTERRUPT_ENABLE 1 // TIMER1
#define TIMER2_INTERRUPT_ENABLE 1 // TIMER2
#define TIMER3_INTERRUPT_ENABLE 1 // TIMER3
#define CCP1_INTERRUPT_ENABLE 1 // CCP1
 // this macro is responsible for enabling and disabling priority feature  
#define INTERUPT_PRIORITY__FEATURE_ENABLE INTERUPT_PRIORITY_DISABLE
/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
        /* this function enables all high prio interrupts*/
#define INTERRUPT_GLOBAL_HIGH_ENABLE()       (INTCONbits.GIEH=1)
        /* this function disables all high prio interrupts*/
#define INTERRUPT_GLOBAL_HIGH_DISABLE()      (INTCONbits.GIEH=0)
            /* this function enables all low prio interrupts*/
#define INTERRUPT_GLOBAL_LOW_ENABLE()   (INTCONbits.GIEL=1)
            /* this function disables all low prio interrupts*/
#define INTERRUPT_GLOBAL_LOW_DISABLE()  (INTCONbits.GIEL=0)
     /* this function enables all priority levels*/
#define INTERRUPT_PRIORITY_ENABLE()      (RCONbits.IPEN=1)
         /* this function disables all priority levels*/
#define INTERRUPT_PRIORITY_DISABLE()     (RCONbits.IPEN=0)

#else
            /* this function enables all interrupts*/
#define INTERRUPT_GLOBAL_ENABLE()       (INTCONbits.GIE=1)
        /* this function disables all interrupts*/
#define INTERRUPT_GLOBAL_DISABLE()      (INTCONbits.GIE=0)
     /* this function enables all peripheral interrupts*/
#define INTERRUPT_PERIPHERAL_ENABLE()   (INTCONbits.PEIE=1)
     /* this function disables all peripheral interrupts*/
#define INTERRUPT_PERIPHERAL_DISABLE()  (INTCONbits.PEIE=0)
#endif
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef enum {
    LOW_PRIORITY = 0,
    HIGH_PRIORITY 
}INTURREPT_INTx_PRIO;

/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */


/* **********************  functions declarations Section End   ************************* */


#endif	/* MCAL_INTERRUPT_CONFIG_H */

