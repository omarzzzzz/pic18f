/* 
 * File:   hal_adc.h
 * Author: omars
 *
 * Created on July 19, 2024, 7:53 PM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* ********************** Includes Section Start ********************** */
#include"../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* ********************** Includes Section End   ********************** */
#define ADC_AN0_ENABLE 0x0E
#define ADC_AN1_ENABLE 0x0D
#define ADC_AN2_ENABLE 0x0C
#define ADC_AN3_ENABLE 0x0B
#define ADC_AN4_ENABLE 0x0A
#define ADC_AN5_ENABLE 0x09
#define ADC_AN6_ENABLE 0x08
#define ADC_AN7_ENABLE 0x07
#define ADC_AN8_ENABLE 0x06
#define ADC_AN9_ENABLE 0x05
#define ADC_AN10_ENABLE 0x04
#define ADC_AN11_ENABLE 0x03
#define ADC_AN12_ENABLE 0x02
#define ADC_AN_ALL_ENABLE 0x01
#define ADC_ALL_DISABLE 0x0F

#define ADC_RIGHT_FORMATE 0x01
#define ADC_LEFT_FORMATE  0x00

#define ADC_CONVERSION_DONE 0x01
#define ADC_CONVERSION_IN_PROGRESS  0x00




/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */
                            /* ADC REGISTER ADCON0 CONFIGURATION*/
#define ADC_CONVERSION_STATUS() (ADCON0bits.GO_nDONE)

#define ADC_START_CONVERSION() (ADCON0bits.GO_nDONE = 1)


#define ADC_CONVERTER_ENABLE() (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE() (ADCON0bits.ADON = 0)

                            /* ADC REGISTER ADCON1 VOLTAGE CONFIGURATION*/
#define ADC_VOLTAGE_REFRENCE_ENABLE() do{ADCON1bits.VCFG1 = 1;\
                                         ADCON1bits.VCFG0 = 1;\
                                         }while(0)
#define ADC_VOLTAGE_REFRENCE_DISABLE() do{ADCON1bits.VCFG1 = 0;\
                                         ADCON1bits.VCFG0 = 0;\
                                         }while(0)

             /* DETERMINES WHICH IS ANOLOG AND WHICH IS DIGITAL*/
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG=_CONFIG)


#define ADC_RIGHT_FORMAT()   (ADCON2bits.ADFM = 1)
#define ADC_LEFT_FORMAT()   (ADCON2bits.ADFM = 0)
/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef enum {
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12
}adc_channel_select_t;


typedef enum {
    ADC_0_TAD = 0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
            
}adc_time_acquisition_t;

typedef enum {
    FOSC_DIV_2= 0,
    FOSC_DIV_8,
    FOSC_DIV_FRC,  
    FOSC_DIV_4,        
    FOSC_DIV_16,        
    FOSC_DIV_64       
}adc_clock_select_t;
typedef enum{
    low_prio=0,
    high_prio        
}INTURREPT_adc_PRIO;
typedef struct{
#if ADC_INTERRUPT_ENABLE ==1
             
    INTURREPT_adc_PRIO priority;
    void(* ADC_InterruptHandler)(void);
#endif     
    adc_time_acquisition_t adc_time;
    adc_clock_select_t adc_clock;
    adc_channel_select_t adc_channel;
    uint8 voltage_reference :1;
    uint8 result_format :1;
    uint8 ADC_RESERVED :6;
}adc_config_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType ADC_Init(const adc_config_t *_adc);
std_ReturnType ADC_DeInit(const adc_config_t *_adc);
std_ReturnType ADC_SelectChannel(const adc_config_t *_adc, adc_channel_select_t channel );
std_ReturnType ADC_StartConversion(const adc_config_t *_adc);
std_ReturnType ADC_IsConversionDone(const adc_config_t *_adc,uint8 *conversion_status);
std_ReturnType ADC_GetConversionResult(const adc_config_t *_adc,uint16 *conversion_Result);
std_ReturnType ADC_GetConversion(const adc_config_t *_adc,adc_channel_select_t channel,uint16 *conversion_Result );
std_ReturnType ADC_GetConversion_interrupt(const adc_config_t *_adc,adc_channel_select_t channel);
/* **********************  functions declarations Section End   ************************* */


#endif	/* HAL_ADC_H */

//adc_config_t adc_1={
//  .ADC_InterruptHandler= NULL,
//  .adc_time=  ADC_12_TAD,
//  .adc_clock= FOSC_DIV_16,
//  .adc_channel= ADC_CHANNEL_AN0,
//  .voltage_reference= 0,
//  .result_format=ADC_RIGHT_FORMATE
//    
//    
//}; defined varaible