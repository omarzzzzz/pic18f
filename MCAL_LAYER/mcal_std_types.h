/* 
 * File:   mcal_std_types.h
 * Author: omars
 *
 * Created on June 24, 2024, 9:25 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* ********************** Includes Section Start ********************** */
#include "std_libraries.h"
#include "COMPILER.H"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define STD_HIGH       0x01
#define STD_LOW        0x00



#define STD_ON         0x01
#define STD_0FF        0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK           (std_ReturnType)0x01
#define E_NOT_OK       (std_ReturnType)0x00

/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */

/* **********************  functions declarations Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long  sint32;
typedef float float32;


typedef uint8 std_ReturnType;
/* ********************** Data type functions Section End   ************************* */

#endif	/* MCAL_STD_TYPES_H */

