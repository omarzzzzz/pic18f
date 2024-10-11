/* 
 * File:   mcal_external_interrupt.h
 * Author: omars
 *
 * Created on July 12, 2024, 9:13 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* ********************** Includes Section Start ********************** */
#include "mcal_interrupt_config.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define EXTERNAL_INTERRUPT_ENABLE  1
#define EXTERNAL_INTERRUPT_DISABLE 0


#define EXTERNAL_INTERRUPT_FEATURE EXTERNAL_INTERRUPT_ENABLE
/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

#if EXTERNAL_INTERRUPT_FEATURE == EXTERNAL_INTERRUPT_ENABLE

#define INTERRUPT_INT0_EXTERNAL_ENABLE()   (INTCONbits.INT0IE=1)
#define INTERRUPT_INT0_EXTERNAL_DISABLE()  (INTCONbits.INT0IE=0)
#define INTERRUPT_INT0_FLAG_CLEAR()        (INTCONbits.INT0IF=0)
#define INTERRUPT_INT0_RISING_EDGE()       (INTCON2bits.INTEDG0=1)
#define INTERRUPT_INT0_FALLING_EDGE()      (INTCON2bits.INTEDG0=0)

#define INTERRUPT_INT1_EXTERNAL_ENABLE()   (INTCON3bits.INT1IE=1)
#define INTERRUPT_INT1_EXTERNAL_DISABLE()  (INTCON3bits.INT1IE=0)
#define INTERRUPT_INT1_FLAG_CLEAR()        (INTCON3bits.INT1IF=0)
#define INTERRUPT_INT1_RISING_EDGE()       (INTCON2bits.INTEDG1=1)
#define INTERRUPT_INT1_FALLING_EDGE()      (INTCON2bits.INTEDG1=0)


#define INTERRUPT_INT2_EXTERNAL_ENABLE()   (INTCON3bits.INT2IE=1)
#define INTERRUPT_INT2_EXTERNAL_DISABLE()  (INTCON3bits.INT2IE=0)
#define INTERRUPT_INT2_FLAG_CLEAR()        (INTCON3bits.INT2IF=0)
#define INTERRUPT_INT2_RISING_EDGE()       (INTCON2bits.INTEDG2=1)
#define INTERRUPT_INT2_FALLING_EDGE()      (INTCON2bits.INTEDG2=0)

/////////////////////////////////////////////////////////////////////////////////////////////////
#define INTERRUPT_RBx_EXTERNAL_ENABLE()    (INTCONbits.RBIE=1)
#define INTERRUPT_RBx_EXTERNAL_DISABLE()   (INTCONbits.RBIE=0)
#define INTERRUPT_RBx_FLAG_CLEAR()         (INTCONbits.RBIF=0)




#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1

#define INTERRUPT_INT1_HighPriortiy()      (INTCON3bits.INT1IP=1)
#define INTERRUPT_INT1_LowPriortiy()       (INTCON3bits.INT1IP=0)
#define INTERRUPT_INT2_HighPriortiy()      (INTCON3bits.INT2IP=1)
#define INTERRUPT_INT2_LowPriortiy()       (INTCON3bits.INT2IP=0)
/******************************************************************/
#define INTERRUPT_RBx_HighPriortiy()      (INTCON2bits.RBIP=1)
#define INTERRUPT_RBx_LowPriortiy()       (INTCON2bits.RBIP=0)

#endif

#endif
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


typedef enum{
    FALLING_EDGE=0,
     RISING_EDGE
    
}INTURREPT_INTx_EDGE;


typedef enum {
    EXT_INT0 = 0,
    EXT_INT1,
    EXT_INT2
    
}INTURREPT_INTx_SRC;
typedef struct{
    void (*EXTERNAL_HANDLER) (void);
    pin_config_t pin;
    INTURREPT_INTx_SRC source;
    INTURREPT_INTx_EDGE edge;
    INTURREPT_INTx_PRIO priority;     
}interrupt_INTx_t;

typedef struct{
    void (*EXTERNAL_HANDLER) (void);
    pin_config_t pin;
    INTURREPT_INTx_PRIO priority;
}interrupt_RBx_t;

/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType Interrupt_intx_init(const interrupt_INTx_t* int_obj);
std_ReturnType Interrupt_intx_Deinit(const interrupt_INTx_t* int_obj);
std_ReturnType Interrupt_RBx_init(const interrupt_RBx_t* int_obj);
std_ReturnType Interrupt_RBx_Deinit(const interrupt_RBx_t* int_obj);

/* **********************  functions declarations Section End   ************************* */


#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

