

#include "ecu_lcd.h"

static std_ReturnType lcd_send_4bits(const  lcd_4bit_t* lcd, uint8 _data_command);
static std_ReturnType lcd_send_enable_4bits(const  lcd_4bit_t* lcd);
static std_ReturnType lcd_send_enable_8bits(const  lcd_8bit_t* lcd);
static std_ReturnType LCD_8bit_Set_cursor(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn);
static std_ReturnType LCD_4bit_Set_cursor(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn);
 
//////////////////////////////////////////////////////////////////////////////////////////////////////

std_ReturnType LCD_4bit_Init(const  lcd_4bit_t* lcd){
     std_ReturnType ret= E_OK;
     uint8 l_pins_index=0;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
        ret=GPIO_PinInit(&(lcd->RS));
        ret=GPIO_PinInit(&(lcd->EN));
        
        for(l_pins_index=0 ; l_pins_index<4 ; l_pins_index++)
        {
           ret=GPIO_PinInit(&(lcd->lcd_pins[l_pins_index]));
        }
        __delay_ms(20);
        ret=LCD_4bit_Send_Command( lcd,LCD_8BIT_MODE_2_LINE );
        __delay_ms(5);
        ret=LCD_4bit_Send_Command( lcd,LCD_8BIT_MODE_2_LINE );
        __delay_us(150);
        ret=LCD_4bit_Send_Command( lcd,LCD_8BIT_MODE_2_LINE );
        ret=LCD_4bit_Send_Command(lcd, CLR_SCREEN);
        ret=LCD_4bit_Send_Command(lcd, RETURN_HOME);
        ret=LCD_4bit_Send_Command(lcd, ENTRY_MODE_INC_SHIFT_OFF);
        ret=LCD_4bit_Send_Command(lcd, LCD_CURSOR_ON_BLINK_OFF);
        ret=LCD_4bit_Send_Command(lcd, LCD_4BIT_MODE_2_LINE);
        ret=LCD_4bit_Send_Command(lcd, 0x80);
    }
          return ret; 
}
std_ReturnType LCD_4bit_Send_Command(const  lcd_4bit_t* lcd, uint8 command){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
        ret=GPIO_WritePinLogic(&(lcd->RS),LOW);
        ret=lcd_send_4bits(lcd,command >> 4); // momkn n3dl feha
        ret=lcd_send_enable_4bits(lcd);
        ret=lcd_send_4bits((lcd),command);
      //  ret=GPIO_WritePinLogic(&(lcd->RS),LOW);
        ret=lcd_send_enable_4bits(lcd);
    }
          return ret; 
}
std_ReturnType LCD_4bit_Send_Character(const  lcd_4bit_t* lcd, uint8 character){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
        ret=GPIO_WritePinLogic(&(lcd->RS),HIGH);
        ret=lcd_send_4bits((lcd),character >> 4); // momkn n3dl feha
        ret=lcd_send_enable_4bits(lcd);
        ret=lcd_send_4bits(lcd,character);
        ret=lcd_send_enable_4bits(lcd);
      
    }
          return ret; 
}
std_ReturnType LCD_4bit_Send_Character_pos(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn ,uint8 Character){
    
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
       ret=LCD_4bit_Set_cursor(lcd,row,coloumn);
       ret= LCD_4bit_Send_Character(lcd,Character);
    }
          return ret; 
    
}
std_ReturnType LCD_4bit_Send_String(const  lcd_4bit_t* lcd, uint8 *str){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
            while(*str)
        {
            ret=LCD_4bit_Send_Character(lcd,*str);
            str++;
        }
      
    }
          return ret; 
    
}
    
    
std_ReturnType LCD_4bit_Send_String_pos(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn ,uint8 *str){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
      LCD_4bit_Set_cursor(lcd,row,coloumn);
           while(*str)
        {
            ret=LCD_4bit_Send_Character(lcd,*str);
            str++;
        }
    }
          return ret; 
}
std_ReturnType LCD_4bit_Send_Custom_char(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn ,uint8 chr[],uint8 mem_pos){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
       
      
    }
          return ret; 
    
    
}


std_ReturnType LCD_8bit_Init(const  lcd_8bit_t* lcd){
    
     std_ReturnType ret= E_OK;
     uint8 l_pins_index=0;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
        ret=GPIO_PinInit(&(lcd->RS));
        ret=GPIO_PinInit(&(lcd->EN));
        
        for(l_pins_index=0;l_pins_index<8;l_pins_index++)
        {
           ret=GPIO_PinInit(&(lcd->lcd_pins[l_pins_index]));
        }
        __delay_ms(20);
        LCD_8bit_Send_Command( lcd,LCD_8BIT_MODE_2_LINE );
        __delay_ms(5);
        LCD_8bit_Send_Command( lcd,LCD_8BIT_MODE_2_LINE );
        __delay_us(150);
        ret= LCD_8bit_Send_Command( lcd,LCD_8BIT_MODE_2_LINE );
        ret=LCD_8bit_Send_Command(lcd, CLR_SCREEN);
        ret=LCD_8bit_Send_Command(lcd, RETURN_HOME);
        ret=LCD_8bit_Send_Command(lcd, ENTRY_MODE_INC_SHIFT_OFF);
        ret=LCD_8bit_Send_Command(lcd, LCD_CURSOR_ON_BLINK_OFF);
        ret=LCD_8bit_Send_Command(lcd, LCD_8BIT_MODE_2_LINE);
        ret=LCD_8bit_Send_Command(lcd, 0x80);
        
         
    }
          return ret; 
}
std_ReturnType LCD_8bit_Send_Command(const  lcd_8bit_t* lcd, uint8 command){
    uint8 l_pins_index=0;
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
       ret=GPIO_WritePinLogic(&(lcd->RS),LOW);
      for(l_pins_index=0;l_pins_index<8;++l_pins_index)
        { 
            ret=GPIO_WritePinLogic(&(lcd->lcd_pins[l_pins_index]),(command >>l_pins_index)& (uint8)0x01);
        }
            ret=lcd_send_enable_8bits(lcd);
      
    }
          return ret; 
    
}
std_ReturnType LCD_8bit_Send_Character(const  lcd_8bit_t* lcd, uint8 character){
     uint8 l_pins_index=0;
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
       ret=GPIO_WritePinLogic(&(lcd->RS),HIGH);
       for(l_pins_index=0;l_pins_index<8;++l_pins_index)
        {
            ret=GPIO_WritePinLogic(&(lcd->lcd_pins[l_pins_index]),(character >>l_pins_index)&(uint8)0x01);
        }
            ret=lcd_send_enable_8bits(lcd);
    }
          return ret; 
    
}
std_ReturnType LCD_8bit_Send_Character_pos(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn ,uint8 Character){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
       LCD_8bit_Set_cursor(lcd,row,coloumn);
       LCD_8bit_Send_Character(lcd,Character);
      
    }
          return ret; 
    
}
std_ReturnType LCD_8bit_Send_String(const  lcd_8bit_t* lcd, uint8 *str){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
        while(*str)
        {
            ret=LCD_8bit_Send_Character(lcd,*str);
            str++;
        }
      
    }
          return ret; 
    
    
}
std_ReturnType LCD_8bit_Send_String_pos(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn ,uint8 *str){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
      ret=LCD_8bit_Set_cursor(lcd,row,coloumn);
      ret=LCD_8bit_Send_String(lcd,str);
    }
          return ret; 
    
}
std_ReturnType LCD_8bit_Send_Custom_char(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn ,uint8 chr[],uint8 mem_pos){
     std_ReturnType ret= E_OK;
    if (NULL == lcd)
    {
        ret=E_NOT_OK;
    }
    else{
       
      
    }
          return ret; 
    
}


void Convert_Byte_to_string(uint8 value, uint8* string){
     std_ReturnType ret= E_OK;
    if (NULL == string)
    {
        ret=E_NOT_OK;
    }
    else{
       
      
    }
         
    
}
void Convert_Short_to_string(uint16 value, uint8* string){
     std_ReturnType ret= E_OK;
    if (NULL == string)
    {
        ret=E_NOT_OK;
    }
    else{
       
      
    }
         
    
}
void Convert_int_to_string(uint32 value, uint8* string){
     std_ReturnType ret= E_OK;
    if (NULL == string)
    {
        ret=E_NOT_OK;
    }
    else{
       
      
    }
          
    
}

static std_ReturnType lcd_send_4bits(const  lcd_4bit_t* lcd, uint8 _data_command){
    
    std_ReturnType ret= E_OK;

        ret = GPIO_WritePinLogic(&(lcd->lcd_pins[0]),(_data_command >>0)& (uint8)0x01);
        ret = GPIO_WritePinLogic(&(lcd->lcd_pins[0]),(_data_command >>1)& (uint8)0x01);
        ret = GPIO_WritePinLogic(&(lcd->lcd_pins[0]),(_data_command >>2)& (uint8)0x01);
        ret = GPIO_WritePinLogic(&(lcd->lcd_pins[0]),(_data_command >>3)& (uint8)0x01);
        
        
    return ret;
} 
static std_ReturnType lcd_send_enable_4bits(const  lcd_4bit_t* lcd){
    
    std_ReturnType ret= E_OK;

        ret=GPIO_WritePinLogic(&(lcd->EN),HIGH);
        __delay_us(5);
        ret=GPIO_WritePinLogic(&(lcd->EN),LOW);
        
        
    return ret;
} 

static std_ReturnType lcd_send_enable_8bits(const  lcd_8bit_t* lcd){
    
    std_ReturnType ret= E_OK;

        ret=GPIO_WritePinLogic(&(lcd->EN),HIGH);
        __delay_us(5);
        ret=GPIO_WritePinLogic(&(lcd->EN),LOW);
        
        
    return ret;
} 
static std_ReturnType LCD_8bit_Set_cursor(const  lcd_8bit_t* lcd,uint8 row,uint8 coloumn){
    std_ReturnType ret= E_OK;
    coloumn--;
    switch(row){
        case 1: ret=LCD_8bit_Send_Command(lcd,(0x80+coloumn));break;
        case 2: ret=LCD_8bit_Send_Command(lcd,(0xc0+coloumn));break;
        case 3: ret=LCD_8bit_Send_Command(lcd,(0x94+coloumn));break;
        case 4: ret=LCD_8bit_Send_Command(lcd,(0xd4+coloumn));break;
        default: ;
        
        
        
        
    }
    
    return ret;
}
static std_ReturnType LCD_4bit_Set_cursor(const  lcd_4bit_t* lcd,uint8 row,uint8 coloumn){
    std_ReturnType ret= E_OK;
    coloumn--;
    switch(row){
        case 1: ret=LCD_4bit_Send_Command(lcd,(0x80+coloumn));break;
        case 2: ret=LCD_4bit_Send_Command(lcd,(0xc0+coloumn));break;
        case 3: ret=LCD_4bit_Send_Command(lcd,(0x94+coloumn));break;
        case 4: ret=LCD_4bit_Send_Command(lcd,(0xd4+coloumn));break;
        default: ;
        
        
        
        
    }
    
    return ret;
}