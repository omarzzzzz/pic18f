/* 
 * File:   hal_adc.c
 * Author: omar salah
 *
 * Created on July 19, 2024, 7:53 PM
 */


#include <pic18f4620.h>

#include "hal_adc.h"

#if ADC_INTERRUPT_ENABLE ==1
    static void (*ADC_Interrupthandler)(void) = NULL;
#endif 


static inline void adc_input_channel_port_configure(adc_channel_select_t channel);
static inline void adc_select_result_format(const adc_config_t *_adc);
static inline void adc_voltage_reference_configure(const adc_config_t *_adc);




std_ReturnType ADC_Init(const adc_config_t *_adc){
    std_ReturnType ret=E_OK;
    if(NULL == _adc )
    {
        ret=E_NOT_OK;
    }
    else
    {       /*MAKE SURE IT'S DISABLED */
             ADC_CONVERTER_DISABLE();
             /* CONFIGURE AQUISTION TIME*/
             ADCON2bits.ACQT=(_adc->adc_time);
             /* CONFIGURE THE CLOCK*/
             ADCON2bits.ADCS=(_adc->adc_clock);
              /* CONFIGURE THE CHANNEL*/
             ADCON0bits.CHS=(_adc->adc_channel);
             adc_input_channel_port_configure((_adc->adc_channel));
             
                      /* CONFIGURE THE interrupt*/
        #if ADC_INTERRUPT_ENABLE ==1

             ADC_INTERRUPT_ENABLE_BIT();
             ADC_INTERRUPT_CLEAR_FLAG();
             #if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
             INTERRUPT_PRIORITY_ENABLE();
             if (_adc->priority== 1)
             {
                 INTERRUPT_GLOBAL_HIGH_ENABLE();
                 ADC_INTERRUPT_HIGH_PRIORITY();
             }
             else
             {
                 INTERRUPT_GLOBAL_LOW_ENABLE();
                  ADC_INTERRUPT_LOW_PRIORITY();
             }
             ADC_Interrupthandler= _adc->ADC_InterruptHandler;
#else
            INTERRUPT_GLOBAL_ENABLE();
            INTERRUPT_PERIPHERAL_ENABLE();
               #endif
        #endif             
              /* CONFIGURE THE result format*/
             adc_select_result_format(_adc);
             /* CONFIGURE THE VOLTAGE REFERENCE*/
             adc_voltage_reference_configure(_adc);
               /* ENABLE THE ADC*/
              ADC_CONVERTER_ENABLE();
    }
    return ret;
    
    
}
std_ReturnType ADC_DeInit(const adc_config_t *_adc){
    
    std_ReturnType ret=E_OK;
    if(NULL == _adc )
    {
        ret=E_NOT_OK;
    }
    else
    {
          /* DISABLE ADC*/
        ADC_INTERRUPT_DISABLE_BIT();
        ADC_CONVERTER_DISABLE();
         /* CONFIGURE THE interrupt*/
    }
    return ret;
}
std_ReturnType ADC_SelectChannel(const adc_config_t *_adc, adc_channel_select_t channel ){
    std_ReturnType ret=E_OK;
    if(NULL == _adc )
    {
        ret=E_NOT_OK;
    }
    else
{
               /* CONFIGURE THE interrupt*/
        ADCON0bits.CHS = channel;
        adc_input_channel_port_configure(channel);
    }
    return ret;
}
std_ReturnType ADC_StartConversion(const adc_config_t *_adc){
    std_ReturnType ret=E_OK;
    if(NULL == _adc )
    {
        ret=E_NOT_OK;
    }
    else
    {
            ADC_START_CONVERSION();
    }
    return ret;
}
std_ReturnType ADC_IsConversionDone(const adc_config_t *_adc,uint8 *conversion_status){
    std_ReturnType ret=E_OK;
    if(NULL == _adc || NULL == conversion_status  )
    {
        ret=E_NOT_OK;
    }
    else
    {
            *conversion_status=(uint8)(!(ADCON0bits.GO_nDONE));
    }
    return ret;
}
std_ReturnType ADC_GetConversionResult(const adc_config_t *_adc,uint16 *conversion_Result){
    std_ReturnType ret=E_OK;
    if(NULL == _adc  || NULL == conversion_Result)
    {
        ret=E_NOT_OK;
    }
    else
    {
        if(_adc->result_format == ADC_RIGHT_FORMATE){
              *conversion_Result =(uint16)((ADRESH << 8) + ADRESL);
    }
    else if(_adc->result_format == ADC_LEFT_FORMATE){
        *conversion_Result =(uint16)(((ADRESH << 8) + ADRESL) >>6);
    }
    else{
        ADC_RIGHT_FORMAT();
    }
        
    }
    return ret;
}
std_ReturnType ADC_GetConversion(const adc_config_t *_adc,adc_channel_select_t channel,uint16 *conversion_Result ){
    std_ReturnType ret=E_OK;
    uint8 l_conversion_status=0;
    if(NULL == _adc  || NULL == conversion_Result)
    {
        ret=E_NOT_OK;
    }
    else
    {
            ret=ADC_SelectChannel(_adc,channel);
            ret=ADC_StartConversion(_adc);
            ret=ADC_IsConversionDone(_adc,&l_conversion_status);
            
            
            while(ADCON0bits.GO_DONE)
                ; //blocking until the conversion is done
                 ret= ADC_GetConversionResult(_adc,conversion_Result);
   
    }
    return ret;
}
std_ReturnType ADC_GetConversion_interrupt(const adc_config_t *_adc,adc_channel_select_t channel ){
    std_ReturnType ret=E_OK;
  
    if(NULL == _adc  )
    {
        ret=E_NOT_OK;
    }
    else
    {
            ret=ADC_SelectChannel(_adc,channel);
            ret=ADC_StartConversion(_adc);
            
            
    }
    return ret;
}

static inline void adc_input_channel_port_configure(adc_channel_select_t channel)
{
    switch(channel){
        
        case ADC_CHANNEL_AN0: SET_BIT(TRISA, _TRISA_RA0_POSN);  break;
        case ADC_CHANNEL_AN1: SET_BIT(TRISA, _TRISA_RA1_POSN);  break;
        case ADC_CHANNEL_AN2: SET_BIT(TRISA, _TRISA_RA2_POSN);  break;
        case ADC_CHANNEL_AN3: SET_BIT(TRISA, _TRISA_RA3_POSN);  break;
        case ADC_CHANNEL_AN4: SET_BIT(TRISA, _TRISA_RA5_POSN);  break;
        case ADC_CHANNEL_AN5: SET_BIT(TRISE, _TRISE_RE0_POSN);  break;
        case ADC_CHANNEL_AN6: SET_BIT(TRISE, _TRISE_RE1_POSN);  break;
        case ADC_CHANNEL_AN7: SET_BIT(TRISE, _TRISE_RE2_POSN);  break;
        case ADC_CHANNEL_AN8: SET_BIT(TRISB, _TRISB_RB2_POSN);  break;
        case ADC_CHANNEL_AN9: SET_BIT(TRISB, _TRISB_RB3_POSN);  break;
        case ADC_CHANNEL_AN10: SET_BIT(TRISB, _TRISB_RB1_POSN); break;
        case ADC_CHANNEL_AN11: SET_BIT(TRISB, _TRISB_RB4_POSN); break;
        case ADC_CHANNEL_AN12: SET_BIT(TRISB, _TRISB_RB0_POSN); break;
    }
}

static inline void adc_select_result_format(const adc_config_t *_adc)
{
    if(_adc->result_format == ADC_RIGHT_FORMATE){
        ADC_RIGHT_FORMAT();       
    }
    else if(_adc->result_format == ADC_LEFT_FORMATE){
        ADC_LEFT_FORMAT(); 
    }
    else{
        ADC_RIGHT_FORMAT();
    }
}

static inline void adc_voltage_reference_configure(const adc_config_t *_adc){
    if((_adc->voltage_reference) == 0){
       ADC_VOLTAGE_REFRENCE_DISABLE();       
    }
    else if((_adc->result_format) == 1){
        ADC_VOLTAGE_REFRENCE_ENABLE(); 
    }
    else{
        ADC_VOLTAGE_REFRENCE_DISABLE();
    }
    
    
}


void ADC_ISR(void){
    ADC_INTERRUPT_CLEAR_FLAG();
    if(ADC_Interrupthandler){
        ADC_Interrupthandler();
    }
}