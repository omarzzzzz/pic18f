/* 
 * File:   mcal_interrupt_manager.h
 * Author: omars
 *
 * Created on July 12, 2024, 9:15 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* ********************** Includes Section Start ********************** */
#include "mcal_interrupt_config.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(void);
void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void); 
void TIMER3_ISR(void);
/* **********************  functions declarations Section End   ************************* */

#endif	/* MCAL_INTERRUPT_MANAGER_H */

