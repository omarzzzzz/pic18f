#include"mcal_interrupt_manager.h"

//#include "xc.h"
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
void __interrupt(high_priority) InterruptManagerHigh(void){ // msh 7atet (high_priority)
    if((INTERUPT_ENABLE ==INTCONbits.INT0IE)  && (INTERUPT_OCCUR == INTCONbits.INT0IF)){
        
        INT0_ISR();
    }
     else{/* nothing */}   
    
  if((INTERUPT_ENABLE == INTCON3bits.INT2E)  && (INTERUPT_OCCUR == INTCON3bits.INT2F)){
        
        INT2_ISR();    
          
    }
    else {/* nothing */};    
    
}

void __interrupt(low_priority) InterruptManagerLow(void){
    if((INTERUPT_ENABLE ==INTCON3bits.INT1E)  && (INTERUPT_OCCUR == INTCON3bits.INT1F)){
        
        INT1_ISR();
    }    
     else{/* nothing */}   
    
}
#else
void __interrupt() InterruptManager(void){
    if((INTERUPT_ENABLE ==INTCONbits.INT0IE)  && (INTERUPT_OCCUR == INTCONbits.INT0IF)){
        
        INT0_ISR();
    }
     else{/* nothing */}    
    if((INTERUPT_ENABLE ==INTCON3bits.INT1E)  && (INTERUPT_OCCUR == INTCON3bits.INT1F)){
        
        INT1_ISR();
    }    
     else{/* nothing */}      
    if((INTERUPT_ENABLE == INTCON3bits.INT2E)  && (INTERUPT_OCCUR == INTCON3bits.INT2F)){
        
        INT2_ISR();    
          
    }
    else {/* nothing */};
    
     if((INTERUPT_ENABLE == INTCONbits.RBIE)  && (INTERUPT_OCCUR == INTCONbits.RBIF)){
        
        RB4_ISR();    
          
    }
    else {/* nothing */};
     if((INTERUPT_ENABLE == PIE1bits.ADIE)  && (INTERUPT_OCCUR == PIR1bits.ADIF)){
        
        ADC_ISR();    
          
    }
    else {/* nothing */};
    
    
     if((INTERUPT_ENABLE == INTCONbits.TMR0IE)  && (INTERUPT_OCCUR == INTCONbits.TMR0IF)){
        
       TIMER0_ISR();    
          
    }
    else {/* nothing */};

     if((INTERUPT_ENABLE == PIE1bits.TMR1IE)  && (INTERUPT_OCCUR == PIR1bits.TMR1IF)){
        
       TIMER1_ISR();    
          
    }
    else {/* nothing */}; 
    
     if((INTERUPT_ENABLE == PIE1bits.TMR2IE )  && (INTERUPT_OCCUR ==PIR1bits.TMR2IF )){
        
       TIMER2_ISR();    
          
    }
    else {/* nothing */}; 
    
    
     if((INTERUPT_ENABLE ==PIE2bits.TMR3IE )  && (INTERUPT_OCCUR == PIR2bits.TMR3IF )){
        
      TIMER3_ISR();    
          
    }
    else {/* nothing */};     
}


#endif