/* 
 * File:   ecu_lcd.h
 * Author: omars
 *
 * Created on July 5, 2024, 5:28 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/* ********************** Includes Section Start ********************** */

#include"../../MCAL_LAYER/GPIO/hal_gpio.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define CLR_SCREEN                          0x01
#define RETURN_HOME                         0x02
#define ENTRY_MODE_DEC_SHIFT_OFF            0x04
#define ENTRY_MODE_DEC_SHIFT_ON              0x05
#define ENTRY_MODE_INC_SHIFT_OFF            0x06
#define ENTRY_MODE_INC_SHIFT_ON             0x07
#define LCD_DISPLAY_OFF                     0x08
#define LCD_CURSOR_ON_BLINK_OFF             0x0E
#define LCD_CURSOR_OFF                      0x0C
#define LCD_CURSOR_BLINK_ON                 0x0F
#define LCD_DISPLAY_SHIFT_RIGHT             0x1C
#define LCD_DISPLAY_SHIFT_LEFT              0x18
#define LCD_8BIT_MODE_2_LINE                0x38
#define LCD_4BIT_MODE_2_LINE                0x28
#define LCD_CGRAM_START                     0X40
#define LCD_DDRAM_START                     0X80



/* ********************** Macro Section End   ************************* */

/* ********************** Macro functions Section Start ************************* */

/* ********************** Macro functions Section End   ************************* */

/* ********************** Data type Section Start ************************* */
typedef struct{
    pin_config_t lcd_pins[8];
    pin_config_t RS;
    pin_config_t EN;
    
}lcd_8bit_t;
typedef struct{
    pin_config_t lcd_pins[4];
    pin_config_t RS;
    pin_config_t EN;
    
}lcd_4bit_t;

/* ********************** Data type functions Section End   ************************* */

/* **********************  functions declarations Section Start ************************* */
std_ReturnType LCD_4bit_Init(const  lcd_4bit_t* lcd);
std_ReturnType LCD_4bit_Send_Command(const  lcd_4bit_t* lcd, uint8 command);
std_ReturnType LCD_4bit_Send_Character(const  lcd_4bit_t* lcd, uint8 character);
std_ReturnType LCD_4bit_Send_Character_pos(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn ,uint8 Character);
std_ReturnType LCD_4bit_Send_String(const  lcd_4bit_t* lcd, uint8 *str);
std_ReturnType LCD_4bit_Send_String_pos(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn ,uint8 *str);
std_ReturnType LCD_4bit_Send_Custom_char(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn ,uint8 chr[],uint8 mem_pos);



std_ReturnType LCD_8bit_Init(const  lcd_8bit_t* lcd);
std_ReturnType LCD_8bit_Send_Command(const  lcd_8bit_t* lcd, uint8 command);
std_ReturnType LCD_8bit_Send_Character(const  lcd_8bit_t* lcd, uint8 character);
std_ReturnType LCD_8bit_Send_Character_pos(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn ,uint8 Character);
std_ReturnType LCD_8bit_Send_String(const  lcd_8bit_t* lcd, uint8 *str);
std_ReturnType LCD_8bit_Send_String_pos(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn ,uint8 *str);
std_ReturnType LCD_8bit_Send_Custom_char(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn ,uint8 chr[],uint8 mem_pos);


void Convert_Byte_to_string(uint8 value, uint8* string);
void Convert_Short_to_string(uint16 value, uint8* string);
void Convert_int_to_string(uint32 value, uint8* string);



/* **********************  functions declarations Section End   ************************* */


#endif	/* ECU_LCD_H */

//lcd_8bit_t lcd_2={
//  .EN.port=PORTC_INDEX,  .EN.pin=PIN7, .EN.direction=OUTPUT, .EN.logic=LOW,
//  .RS.port=PORTC_INDEX,  .RS.pin=PIN6, .RS.direction=OUTPUT, .RS.logic=LOW,
//  .lcd_pins[0].port=PORTD_INDEX ,.lcd_pins[0].pin=PIN0, .lcd_pins[0].direction=OUTPUT, .lcd_pins[0].logic=LOW,
//  .lcd_pins[1].port=PORTD_INDEX ,.lcd_pins[1].pin=PIN1, .lcd_pins[1].direction=OUTPUT, .lcd_pins[1].logic=LOW,
//  .lcd_pins[2].port=PORTD_INDEX ,.lcd_pins[2].pin=PIN2, .lcd_pins[2].direction=OUTPUT, .lcd_pins[2].logic=LOW,
//  .lcd_pins[3].port=PORTD_INDEX ,.lcd_pins[3].pin=PIN3, .lcd_pins[3].direction=OUTPUT, .lcd_pins[3].logic=LOW,
//  .lcd_pins[4].port=PORTD_INDEX ,.lcd_pins[4].pin=PIN4, .lcd_pins[4].direction=OUTPUT, .lcd_pins[4].logic=LOW,
//  .lcd_pins[5].port=PORTD_INDEX ,.lcd_pins[5].pin=PIN5, .lcd_pins[5].direction=OUTPUT, .lcd_pins[5].logic=LOW,
//  .lcd_pins[6].port=PORTD_INDEX ,.lcd_pins[6].pin=PIN6, .lcd_pins[6].direction=OUTPUT, .lcd_pins[6].logic=LOW,
//  .lcd_pins[7].port=PORTD_INDEX ,.lcd_pins[7].pin=PIN7, .lcd_pins[7].direction=OUTPUT, .lcd_pins[7].logic=LOW
//}; variable of an lcd