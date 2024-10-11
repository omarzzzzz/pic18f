/* 
 * File:   mcal_internal_interrupt.h
 * Author: omars
 *
 * Created on July 12, 2024, 9:12 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* ********************** Includes Section Start ********************** */
#include "mcal_interrupt_config.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
/* ADC INTERRUPT */
#if ADC_INTERRUPT_ENABLE == 1
             /* ADC INTERRUPT DISABLE*/
#define ADC_INTERRUPT_DISABLE_BIT() (PIE1bits.ADIE=0)
             /* ADC INTERRUPT ENABLE*/
#define ADC_INTERRUPT_ENABLE_BIT() (PIE1bits.ADIE=1)
             /* ADC INTERRUPT CLEAR FLAG*/
#define ADC_INTERRUPT_CLEAR_FLAG() (PIR1bits.ADIF=0)
    #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
 #define ADC_INTERRUPT_HIGH_PRIORITY() (IPR1bits.ADIP=1)       
#define ADC_INTERRUPT_LOW_PRIORITY() (IPR1bits.ADIP=0)
    #endif
#endif
/* ADC INTERRUPT */


/* TIMER0 INTERRUPT */
#if TIMER0_INTERRUPT_ENABLE == 1
             /* TIMER0 INTERRUPT DISABLE*/
#define TIMER0_INTERRUPT_DISABLE_BIT() (INTCONbits.TMR0IE=0)
             /* TIMER0 INTERRUPT ENABLE*/
#define TIMER0_INTERRUPT_ENABLE_BIT()  (INTCONbits.TMR0IE=1)
             /* TIMER0 INTERRUPT CLEAR FLAG*/
#define TIMER0_INTERRUPT_CLEAR_FLAG() (INTCONbits.TMR0IF=0)
    #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
#define TIMER0_INTERRUPT_HIGH_PRIORITY()  (INTCON2bits.TMR0IP=1)       
#define  TIMER0_INTERRUPT_LOW_PRIORITY()  (INTCON2bits.TMR0IP=0)
    #endif
#endif
/* TIMER0 INTERRUPT */

/* TIMER1 INTERRUPT */
#if TIMER1_INTERRUPT_ENABLE == 1
             /* TIMER1 INTERRUPT DISABLE*/
#define TIMER1_INTERRUPT_DISABLE_BIT() (PIE1bits.TMR1IE=0)
             /* TIMER1 INTERRUPT ENABLE*/
#define TIMER1_INTERRUPT_ENABLE_BIT()  (PIE1bits.TMR1IE=1)
             /* TIMER1 INTERRUPT CLEAR FLAG*/
#define TIMER1_INTERRUPT_CLEAR_FLAG() (PIR1bits.TMR1IF=0)
    #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
#define TIMER1_INTERRUPT_HIGH_PRIORITY()  (IPR1bits.TMR1IP=1)       
#define  TIMER1_INTERRUPT_LOW_PRIORITY()  (IPR1bits.TMR1IP=0)
    #endif
#endif
/* TIMER1 INTERRUPT */


/* TIMER2 INTERRUPT */
#if TIMER2_INTERRUPT_ENABLE == 1
             /* TIMER2 INTERRUPT DISABLE*/
#define TIMER2_INTERRUPT_DISABLE_BIT() (PIE1bits.TMR2IE=0)
             /* TIMER2 INTERRUPT ENABLE*/
#define TIMER2_INTERRUPT_ENABLE_BIT()  (PIE1bits.TMR2IE=1)
             /* TIMER2 INTERRUPT CLEAR FLAG*/
#define TIMER2_INTERRUPT_CLEAR_FLAG() (PIR1bits.TMR2IF=0)
    #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
#define TIMER2_INTERRUPT_HIGH_PRIORITY()  (IPR1bits.TMR1IP=1)       
#define  TIME2_INTERRUPT_LOW_PRIORITY()  (IPR1bits.TMR1IP=0)
    #endif
#endif
/* TIMER2 INTERRUPT */

/* TIMER3 INTERRUPT */
#if TIMER3_INTERRUPT_ENABLE == 1
             /* TIMER3 INTERRUPT DISABLE*/
#define TIMER3_INTERRUPT_DISABLE_BIT() (PIE2bits.TMR3IE=0)
             /* TIMER3 INTERRUPT ENABLE*/
#define TIMER3_INTERRUPT_ENABLE_BIT()  (PIE2bits.TMR3IE=1)
             /* TIMER3 INTERRUPT CLEAR FLAG*/
#define TIMER3_INTERRUPT_CLEAR_FLAG() (PIR2bits.TMR3IF=0)
    #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
#define TIMER3_INTERRUPT_HIGH_PRIORITY()  (IPR2bits.TMR3IP=1)       
#define  TIMER3_INTERRUPT_LOW_PRIORITY()  (IPR2bits.TMR3IP=0)
    #endif
#endif
/* TIMER3 INTERRUPT */



/* CCP1 INTERRUPT */
#if CCP1_INTERRUPT_ENABLE == 1
             /* CCP1 INTERRUPT DISABLE*/
#define CCP1_INTERRUPT_DISABLE_BIT() (PIE1bits.CCP1IE=0)
             /* CCP1 INTERRUPT ENABLE*/
#define CCP1_INTERRUPT_ENABLE_BIT()  (PIE1bits.CCP1IE=1)
             /* CCP1 INTERRUPT CLEAR FLAG*/
#define CCP1_INTERRUPT_CLEAR_FLAG() (PIR1bits.CCP1IF=0)
    #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
#define CCP1_INTERRUPT_HIGH_PRIORITY()  (IPR1bits.CCP1IP=1)       
#define  CCP1_INTERRUPT_LOW_PRIORITY()  (IPR1bits.CCP1IP=0)
    #endif
#endif
/* CCP1 INTERRUPT */


/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */


/* **********************  functions declarations Section End   ************************* */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

