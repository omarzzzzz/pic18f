#include "mcal_external_interrupt.h"

static void (*INT0_Iterrupthandler)(void) = NULL;
static void (*INT1_Iterrupthandler)(void) = NULL;
static void (*INT2_Iterrupthandler)(void) = NULL;

static void (*RB4_Interrupthandler)(void) = NULL;
static void (*RB5_Interrupthandler)(void) = NULL;
static void (*RB6_Interrupthandler)(void) = NULL;
static void (*RB7_Interrupthandler)(void) = NULL;

static std_ReturnType interrupt_intx_enable(const interrupt_INTx_t* int_obj);
static std_ReturnType interrupt_intx_disable(const interrupt_INTx_t* int_obj);
static std_ReturnType interrupt_intx_set_edge(const interrupt_INTx_t* int_obj);
static std_ReturnType interrupt_intx_set_priority(const interrupt_INTx_t* int_obj);
static std_ReturnType interrupt_intx_set_pin(const interrupt_INTx_t* int_obj);
static std_ReturnType interrupt_intx_clear_flag(const interrupt_INTx_t* int_obj);

static std_ReturnType INT0_SetIterruptHandler(void (*Iterrupthandler)(void));
static std_ReturnType INT1_SetIterruptHandler(void (*Iterrupthandler)(void));
static std_ReturnType INT2_SetIterruptHandler(void (*Iterrupthandler)(void));
static std_ReturnType Interrupt_INTx_SetIterruptHandler(const interrupt_INTx_t* int_obj);

static std_ReturnType interrupt_RBx_enable(const interrupt_RBx_t* int_obj);
static std_ReturnType interrupt_RBx_disable(const interrupt_RBx_t* int_obj);
static std_ReturnType interrupt_RBx_set_priority(const interrupt_RBx_t* int_obj);
static std_ReturnType interrupt_RBx_set_pin(const interrupt_RBx_t* int_obj);


std_ReturnType Interrupt_intx_init(const interrupt_INTx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else {
        ret = interrupt_intx_disable(int_obj);
        ret = interrupt_intx_clear_flag(int_obj);
        ret = interrupt_intx_set_edge(int_obj);
        #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
        ret = interrupt_intx_set_priority(int_obj); // RET |=
        #endif
        ret = interrupt_intx_set_pin(int_obj);
        ret = Interrupt_INTx_SetIterruptHandler(int_obj);
        ret = interrupt_intx_enable(int_obj);
    }
          return ret; 
    
}


void INT0_ISR(void){
    /*  must  clear the flag bit*/
    INTERRUPT_INT0_FLAG_CLEAR();
    /* code*/
    
    
    /* code*/
    /*   callback function gets called back each time an ISR is executed */
    if(INT0_Iterrupthandler){
        INT0_Iterrupthandler();
    }
        else{ /* */};
    }


void INT1_ISR(void){
    /*  must  clear the flag bit*/
    INTERRUPT_INT1_FLAG_CLEAR();
    /* code*/
    
    
    /* code*/
    /*   callback function gets called back each time an ISR is executed */
    if(INT1_Iterrupthandler){
        INT1_Iterrupthandler();
    }
    else{ /* */};
}

void INT2_ISR(void){
    /*  must  clear the flag bit*/
    INTERRUPT_INT2_FLAG_CLEAR();
    /* code*/
    
    
    /* code*/
    /*   callback function gets called back each time an ISR is executed */
    if(INT2_Iterrupthandler){
        INT2_Iterrupthandler();
    }
    else{ /* */};
}

void RB4_ISR(void){
      /*  must  clear the flag bit*/
     INTERRUPT_RBx_FLAG_CLEAR() ;
    /* code*/
    
    
    /* code*/
    /*   callback function gets called back each time an ISR is executed */
    if(RB4_Interrupthandler){
        RB4_Interrupthandler();
    }
    else{ /* */};
    
}

std_ReturnType Interrupt_intx_Deinit(const interrupt_INTx_t* int_obj){
        std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else{
            interrupt_intx_disable(int_obj);
    }
          return ret;
    
    
}
std_ReturnType Interrupt_RBx_init(const interrupt_RBx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else {
        ///////////////////////////////// disable all interrupts
        INTERRUPT_RBx_EXTERNAL_DISABLE();
        /////////////////////////////////////clear flag
        INTERRUPT_RBx_FLAG_CLEAR();
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
        INTERRUPT_PRIORITY_ENABLE();
        if ((int_obj->priority) == HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_HIGH_ENABLE();
            INTERRUPT_RBx_HighPriortiy();
        } else if ((int_obj->priority) == LOW_PRIORITY) {
            INTERRUPT_GLOBAL_LOW_ENABLE();
            INTERRUPT_RBx_LowPriortiy() ;
        } else {
            /* nothing */
        }
#else
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_ENABLE();
#endif
        /*  init the pin number*/
        ret=GPIO_SetPinDir(&(int_obj->pin));
        /* init callback function*/
        switch(int_obj->pin.pin) {
            case PIN4:
                RB4_Interrupthandler = int_obj->EXTERNAL_HANDLER;
                break;
            case PIN5:
                RB5_Interrupthandler = int_obj->EXTERNAL_HANDLER;
                break;
            case PIN6:
                RB6_Interrupthandler = int_obj->EXTERNAL_HANDLER;
                break;
            case PIN7:
                RB7_Interrupthandler = int_obj->EXTERNAL_HANDLER;
                break;
            default: ret= E_NOT_OK;
        }
        
        
        ///////////////////////////////// enable
        INTERRUPT_RBx_EXTERNAL_ENABLE();
    }
          return ret;
    
}
std_ReturnType Interrupt_RBx_Deinit(const interrupt_RBx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else{
      
    }
          return ret;
    
    
}

static std_ReturnType interrupt_intx_enable(const interrupt_INTx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else {
        switch (int_obj->source) {
            case EXT_INT0:
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
                INTERRUPT_GLOBAL_HIGH_ENABLE();
                
#else

                INTERRUPT_GLOBAL_ENABLE();
                INTERRUPT_PERIPHERAL_ENABLE();
#endif

                INTERRUPT_INT0_EXTERNAL_ENABLE();
                ret = E_OK;
                break;
            case EXT_INT1:
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
                INTERRUPT_PRIORITY_ENABLE();
                if((int_obj->priority) == HIGH_PRIORITY)
                {
                    INTERRUPT_GLOBAL_HIGH_ENABLE();
                }
                else if((int_obj->priority) == LOW_PRIORITY){
                    INTERRUPT_GLOBAL_LOW_ENABLE(); 
                }
                else{ /* nothing */ }    
#else

                INTERRUPT_GLOBAL_ENABLE();
                INTERRUPT_PERIPHERAL_ENABLE();
#endif

                INTERRUPT_INT1_EXTERNAL_ENABLE();
                ret = E_OK;
                break;
            case EXT_INT2:
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
                INTERRUPT_PRIORITY_ENABLE();
                if((int_obj->priority) == HIGH_PRIORITY)
                {
                    INTERRUPT_GLOBAL_HIGH_ENABLE();
                }
                else if((int_obj->priority) == LOW_PRIORITY){
                    INTERRUPT_GLOBAL_LOW_ENABLE(); 
                }
                else{ /* nothing */ }    
#else

                INTERRUPT_GLOBAL_ENABLE();
                INTERRUPT_PERIPHERAL_ENABLE();
#endif

                INTERRUPT_INT2_EXTERNAL_ENABLE();
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
          return ret;
}
static std_ReturnType interrupt_intx_disable(const interrupt_INTx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else{
        switch (int_obj->source) {
            case EXT_INT0:
                INTERRUPT_INT0_EXTERNAL_DISABLE();
                ret = E_OK;
                break;
            case EXT_INT1: INTERRUPT_INT1_EXTERNAL_DISABLE();
                ret = E_OK;
                break;
            case EXT_INT2: INTERRUPT_INT2_EXTERNAL_DISABLE();
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
          return ret;
}
static std_ReturnType interrupt_intx_set_edge(const interrupt_INTx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
         ret=E_NOT_OK;
    }
    else{
      switch (int_obj->source) {
            case EXT_INT0:
                if((int_obj->edge) == FALLING_EDGE)
                {
                    INTERRUPT_INT0_FALLING_EDGE();
                }
                else if((int_obj->edge) == RISING_EDGE){
                    INTERRUPT_INT0_RISING_EDGE(); 
                }
                else{ /* nothing */ }
                ret = E_OK;
                break;
            case EXT_INT1: 
                if((int_obj->edge) == FALLING_EDGE)
                {
                    INTERRUPT_INT1_FALLING_EDGE();
                }
                else if((int_obj->edge) == RISING_EDGE){
                    INTERRUPT_INT1_RISING_EDGE(); 
                }
                else{ /* nothing */ }
                ret = E_OK;
                break;
            case EXT_INT2: 
                if((int_obj->edge) == FALLING_EDGE)
                {
                    INTERRUPT_INT2_FALLING_EDGE();
                }
                else if((int_obj->edge) == RISING_EDGE){
                    INTERRUPT_INT2_RISING_EDGE(); 
                }
                else{ /* nothing */ }
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
          return ret;
}
static std_ReturnType interrupt_intx_clear_flag(const interrupt_INTx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else{
         switch (int_obj->source) {
            case EXT_INT0:
                INTERRUPT_INT0_FLAG_CLEAR() ;
                ret = E_OK;
                break;
            case EXT_INT1: 
               INTERRUPT_INT1_FLAG_CLEAR() ;
                ret = E_OK;
                break;
            case EXT_INT2: 
              INTERRUPT_INT2_FLAG_CLEAR() ;
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
         }
    }
          return ret;
}
static std_ReturnType interrupt_intx_set_pin(const interrupt_INTx_t* int_obj){
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else{
        ret= GPIO_SetPinDir(&(int_obj->pin));
    }
          return ret;
}
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
static std_ReturnType interrupt_intx_set_priority(const interrupt_INTx_t* int_obj){
    
    
    std_ReturnType ret= E_OK;
      
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else{
         switch (int_obj->source) {
            case EXT_INT1: 
                if((int_obj->priority) == HIGH_PRIORITY)
                {
                    INTERRUPT_INT1_HighPriortiy();
                }
                else if((int_obj->priority) == LOW_PRIORITY){
                    INTERRUPT_INT1_LowPriortiy(); 
                }
                else{ /* nothing */ }
                ret = E_OK;
                break;
            case EXT_INT2: 
                if((int_obj->priority) == HIGH_PRIORITY)
                {
                    INTERRUPT_INT2_HighPriortiy();
                }
                else if((int_obj->priority) == LOW_PRIORITY){
                    INTERRUPT_INT2_LowPriortiy(); 
                }
                else{ /* nothing */ }
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
      
    }
          return ret;
    
    
    
}

#endif


static std_ReturnType INT0_SetIterruptHandler(void (*Iterrupthandler)(void)){
    std_ReturnType ret = E_OK;
   if (NULL == Iterrupthandler) {
        ret = E_NOT_OK;
    }
   else {
        INT0_Iterrupthandler = Iterrupthandler;
        ret = E_OK;
    }
    return ret;    
     
}
static std_ReturnType INT1_SetIterruptHandler(void (*Iterrupthandler)(void)){
       std_ReturnType ret = E_OK;
   if (NULL == Iterrupthandler) {
        ret = E_NOT_OK;
    }
   else {
        INT1_Iterrupthandler = Iterrupthandler;
        ret = E_OK;
    }
    return ret;    
}
static std_ReturnType INT2_SetIterruptHandler(void (*Iterrupthandler)(void)){
       std_ReturnType ret = E_OK;
   if (NULL == Iterrupthandler) {
        ret = E_NOT_OK;
    }
   else {
        INT2_Iterrupthandler = Iterrupthandler;
        ret = E_OK;
    }
    return ret;    
    
}
static std_ReturnType Interrupt_INTx_SetIterruptHandler(const interrupt_INTx_t* int_obj) {
    std_ReturnType ret = E_OK;

    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case EXT_INT0:
                INT0_SetIterruptHandler(int_obj->EXTERNAL_HANDLER);
                ret = E_OK;
                break;
            case EXT_INT1:
                INT1_SetIterruptHandler(int_obj->EXTERNAL_HANDLER);
                ret = E_OK;
                break;
            case EXT_INT2:
                INT2_SetIterruptHandler(int_obj->EXTERNAL_HANDLER);
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;    
    
    
}