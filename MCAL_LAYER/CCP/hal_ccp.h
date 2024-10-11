/* 
 * File:   hal_ccp.h
 * Author: omars
 *
 * Created on August 7, 2024, 12:27 AM
 */

#ifndef HAL_CCP_H
#define	HAL_CCP_H

/* ********************** Includes Section Start ********************** */
#include"../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define CCP1_CAPTURE_MODE_SELECTED  0
#define CCP1_COMPARE_MODE_SELECTED  1 
#define CCP1_PWM_MODE_SELECTED      2


#define CCP1_SELECT_MODE        (CCP1_PWM_MODE_SELECTED)



#define CCP1_MODULE_DISABLE                     0
#define CCP1_COMPARE_MODE_TOGGLE_ON_MATCH       0X02
#define CCP1_CAPTURE_MODE_1_FALLING_EDGE        0x04
#define CCP1_CAPTURE_MODE_1_RISING_EDGE         0x05
#define CCP1_CAPTURE_MODE_4_RISING_EDGE         0x06
#define CCP1_CAPTURE_MODE_16_RISING_EDGE        0x07
#define CCP1_COMPARE_MODE_SET_PIN_LOW           0x08
#define CCP1_COMPARE_MODE_SET_PIN_HIGH          0x09
#define CCP1_COMPARE_MODE_GEN_SW_INTERRUPT      0x0A
#define CCP1_COMPARE_MODE_GEN_EVENT             0x0B
#define CCP1_PWM_MODE                           0x0C



#define CCP1_CAPTURE_NOT_READY      0x00
#define CCP1_CAPTURE_READY          0x01

#define CCP1_COMPARE_NOT_READY      0x00
#define CCP1_COMPARE_READY          0x01
/* ********************** Macro Section End   ************************* */
#define CCP1_SET_MODE(_CONFIG)          (CCP1CONbits.CCP1M=_CONFIG)         
/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */

typedef enum{
    CCP1_CAPTURE_MODE_SELECT = 0,
    CCP1_COMPARE_MODE_SELECT,
    CCP1_PWM_MODE_SELECT
}ccp1_mode_T;

typedef union{
struct{
    uint8 ccpr_low;  /* CCPR1 low register */
    uint8 ccpr_high; /* CCPR1 high register */
};

struct{
    uint16 ccpr_16Bit; /* Read CCPR1 as a 16 Bit value */
};
}CCP_REG_T;
typedef struct{

        ccp1_mode_T ccp1_mode;
        uint8 ccp1_mode_variant;
        pin_config_t pin;
 
        
#if CCP1_INTERRUPT_ENABLE ==1

INTURREPT_INTx_PRIO priority;
void(* CCP1_InterruptHandler)(void);
#endif 
#if (CCP1_SELECT_MODE == CCP1_PWM_MODE_SELECTED)
    uint32 PWM_frequency;
     uint8 timer2_postscaler_value: 4;
    uint8 timer2_prescaler_value: 2;
#endif
}ccp_t;
/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */

std_ReturnType CCP_Init(const ccp_t *_ccp_obj);
std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj);

#if             (CCP1_SELECT_MODE == CCP1_CAPTURE_MODE_SELECTED)
std_ReturnType CCP1_IsCapturedDataReady(uint8 *_capture_status);
std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value);
#endif


#if             (CCP1_SELECT_MODE == CCP1_COMPARE_MODE_SELECTED)
std_ReturnType CCP_IsCompareComplete(uint8 *_compare_status);
std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value);
#endif


#if             (CCP1_SELECT_MODE == CCP1_PWM_MODE_SELECTED)     
std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty);
std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj);
std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj);
#endif

/* **********************  functions declarations Section End   ************************* */

#endif	/* HAL_CCP_H */

