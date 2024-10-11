/* 
 * File:   hal_ccp.c
 * Author: omars
 *
 * Created on August 7, 2024, 12:27 AM
 */


#include "hal_ccp.h"


#if CCP1_INTERRUPT_ENABLE == 1
    static void (*CCP1_Interrupthandler)(void) = NULL;
#endif 



std_ReturnType CCP_Init(const ccp_t *_ccp_obj){
    
    CCP1_SET_MODE(CCP1_MODULE_DISABLE);
        
    if(CCP1_CAPTURE_MODE_SELECTED == _ccp_obj->ccp1_mode)
    {
        switch(_ccp_obj->ccp1_mode_variant){
            case CCP1_CAPTURE_MODE_1_FALLING_EDGE :CCP1_SET_MODE(CCP1_CAPTURE_MODE_1_FALLING_EDGE);
            case CCP1_CAPTURE_MODE_1_RISING_EDGE :CCP1_SET_MODE(CCP1_CAPTURE_MODE_1_RISING_EDGE);
            case CCP1_CAPTURE_MODE_4_RISING_EDGE :CCP1_SET_MODE(CCP1_CAPTURE_MODE_4_RISING_EDGE);
            case CCP1_CAPTURE_MODE_16_RISING_EDGE :CCP1_SET_MODE(CCP1_CAPTURE_MODE_16_RISING_EDGE);
        }
    }
    else if(CCP1_COMPARE_MODE_SELECTED == _ccp_obj->ccp1_mode)
    {
        switch(_ccp_obj->ccp1_mode_variant){
            case CCP1_COMPARE_MODE_TOGGLE_ON_MATCH :CCP1_SET_MODE(CCP1_COMPARE_MODE_TOGGLE_ON_MATCH);
            case CCP1_COMPARE_MODE_SET_PIN_LOW :CCP1_SET_MODE(CCP1_COMPARE_MODE_SET_PIN_LOW);
            case CCP1_COMPARE_MODE_SET_PIN_HIGH :CCP1_SET_MODE(CCP1_COMPARE_MODE_SET_PIN_HIGH);
            case CCP1_COMPARE_MODE_GEN_SW_INTERRUPT :CCP1_SET_MODE(CCP1_COMPARE_MODE_GEN_SW_INTERRUPT);
            case CCP1_COMPARE_MODE_GEN_EVENT :CCP1_SET_MODE(CCP1_COMPARE_MODE_GEN_EVENT);
        }        
    }
    else if(CCP1_PWM_MODE_SELECTED == _ccp_obj->ccp1_mode)
    {
        if(CCP1_PWM_MODE == _ccp_obj->ccp1_mode_variant)
        {
            CCP1_SET_MODE(CCP1_PWM_MODE);
        }
#if (CCP1_SELECT_MODE == CCP1_PWM_MODE_SELECTED)        
   PR2 = (uint8)(((float)_XTAL_FREQ / ((float)_ccp_obj->PWM_frequency * 4.0 * (float)_ccp_obj->timer2_prescaler_value * 
            (float)_ccp_obj->timer2_postscaler_value)) - 1);
#endif
    }
    GPIO_SetPinDir(&(_ccp_obj->pin));
    
#if CCP1_INTERRUPT_ENABLE
       CCP1_INTERRUPT_ENABLE_BIT();
       CCP1_INTERRUPT_CLEAR_FLAG();
       CCP1_Interrupthandler = _ccp_obj->CCP1_InterruptHandler;
  
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1       
        INTERRUPT_PRIORITY_ENABLE();


        if (_ccp_obj->priority == HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_HIGH_ENABLE();
            CCP1_INTERRUPT_HIGH_PRIORITY();
        } else if (_ccp_obj->priority == LOW_PRIORITY) {
            INTERRUPT_GLOBAL_LOW_ENABLE();
            CCP1_INTERRUPT_LOW_PRIORITY();
#else
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIPHERAL_ENABLE();        
#endif
#endif
    
}
std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj) {
    
    std_ReturnType ret = E_NOT_OK;
    if (NULL == _ccp_obj) {
        ret = E_NOT_OK;
    } 
    else {
             CCP1_SET_MODE(CCP1_MODULE_DISABLE);
#if CCP1_INTERRUPT_ENABLE
        CCP1_INTERRUPT_DISABLE_BIT();
#endif
    }
}

#if (CCP1_SELECT_MODE == CCP1_CAPTURE_MODE_SELECTED)


std_ReturnType CCP1_IsCapturedDataReady(uint8 *_capture_status){
       std_ReturnType ret = E_NOT_OK;
    if (NULL == _capture_status) {
        ret = E_NOT_OK;
    } 
    else {
         if(CCP1_CAPTURE_READY  == PIR1bits.CCP1IF){
            *_capture_status = CCP1_CAPTURE_READY;
            CCP1_INTERRUPT_CLEAR_FLAG();
        }
        else{
            *_capture_status = CCP1_CAPTURE_NOT_READY;
        }
    }

}
std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value){
       std_ReturnType ret = E_NOT_OK;
          CCP_REG_T capture_temp_value = {.ccpr_low = 0, .ccpr_high = 0};
    if (NULL == capture_value) {
        ret = E_NOT_OK;
    }
    else {
          /* Copy captured value */
        capture_temp_value.ccpr_low = CCPR1L;
        capture_temp_value.ccpr_high = CCPR1H;
        /* Write the 16-bit capture value */
        *capture_value = capture_temp_value.ccpr_16Bit;
        ret = E_OK;
        
    }

}
#endif


#if  (CCP1_SELECT_MODE == CCP1_COMPARE_MODE_SELECTED)
std_ReturnType CCP_IsCompareComplete(uint8 *_compare_status){
std_ReturnType ret = E_NOT_OK;
    if (NULL == _compare_status) {
        ret = E_NOT_OK;
    }
    else {
          if(CCP1_COMPARE_READY == PIR1bits.CCP1IF){
            *_compare_status = CCP1_COMPARE_READY;
            CCP1_INTERRUPT_CLEAR_FLAG();
        }
        else{
            *_compare_status = CCP1_COMPARE_NOT_READY;
    }

}
}
std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value){
std_ReturnType ret = E_NOT_OK;
 CCP_REG_T capture_temp_value = {.ccpr_low = 0, .ccpr_high = 0};
    if (NULL == _ccp_obj) {
        ret = E_NOT_OK;
    }
    else {
        capture_temp_value.ccpr_16Bit = compare_value;


            CCPR1L = capture_temp_value.ccpr_low;
            CCPR1H = capture_temp_value.ccpr_high;

        
    }
}
#endif


#if             (CCP1_SELECT_MODE == CCP1_PWM_MODE_SELECTED)     
std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty){
std_ReturnType ret = E_NOT_OK;
uint16 l_duty_temp = 0;
    if (NULL == _ccp_obj) {
        ret = E_NOT_OK;
    }
    else {
       l_duty_temp = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)_duty / 100.0));
    CCP1CONbits.DC1B = (uint8) (l_duty_temp & 0x0003);
    CCPR1L = (uint8) (l_duty_temp >> 2);
    }
}
std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj){
    
             std_ReturnType ret = E_NOT_OK;
    if (NULL == _ccp_obj) {
        ret = E_NOT_OK;
    }
    else {
        CCP1CONbits.CCP1M = CCP1_PWM_MODE;
    }
}
std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj){
std_ReturnType ret = E_NOT_OK;
    if (NULL == _ccp_obj) {
        ret = E_NOT_OK;
    }
    else 
    {CCP1CONbits.CCP1M = CCP1_MODULE_DISABLE;
        
    }
}
#endif
