/* 
 * File:   seven_segment.h
 * Author: omars
 *
 * Created on June 29, 2024, 12:01 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/* ********************** Includes Section Start ********************** */
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */


/* ********************** Data type functions Section End   ************************* */
typedef enum{
    COMMON_CATHODE,
    COMMON_ANODE
}segment_type_t;


typedef struct{
    
    pin_config_t segment_pins[4];
    segment_type_t segment_type;        
    
}seven_segment_t;
/* **********************  functions declarations Section Start ************************* */
std_ReturnType seven_segment_Init(const seven_segment_t * segment);
std_ReturnType seven_segment_TypeNumber(const seven_segment_t * segment, uint8 number);

/* **********************  functions declarations Section End   ************************* */


#endif	/* SEVEN_SEGMENT_H */

