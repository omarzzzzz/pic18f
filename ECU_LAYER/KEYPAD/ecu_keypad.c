#include "ecu_keypad.h"

static const uint8 btn_values[ROW_PINS][COLOUMN_PINS]={
                                                { '7','8','9','/'},
                                                { '4','5','6','*'},
                                                { '1','2','3','-'},
                                                { '#','0','=','+'}
                                              };

std_ReturnType Keypad_init(const keypad_t* keypad){
    uint8 rows=0,coloumns=0;
     std_ReturnType ret= E_OK;
    if (NULL == keypad)
    {
        ret=E_NOT_OK;
    }
    else{
        for(rows=0;rows<ROW_PINS;rows++ )
        {
         ret=GPIO_PinInit(&(keypad->rows[rows]));
        }
         for(coloumns=0;coloumns<COLOUMN_PINS;coloumns++ )
        {
            
            ret=GPIO_SetPinDir(&(keypad->coloumns[coloumns]));
        }
      
    }
          return ret; 
    
    
    
}

std_ReturnType Keypad_write(const keypad_t* keypad, uint8 *value){
    
    uint8 rows_index=0,coloumn_index=0, index=0;
    logic_t coloumn_logic=LOW;
      std_ReturnType ret= E_OK;
    if (NULL == keypad || NULL == value)
    {
        ret=E_NOT_OK;
    }
    else{
        for(rows_index=0;rows_index<ROW_PINS;rows_index++ ){
            for(index=0;index<ROW_PINS;index++ ){
                ret=GPIO_WritePinLogic(&(keypad->rows[index]),LOW);
            }
            ret= GPIO_WritePinLogic(&(keypad->rows[rows_index]),HIGH);
           //__delay_ms(50);
             for(coloumn_index=0;coloumn_index<COLOUMN_PINS;coloumn_index++ ){
            
            ret=GPIO_ReadPinLogic(&(keypad->coloumns[coloumn_index]),&coloumn_logic);
            if(HIGH == coloumn_logic){
                *value=btn_values[rows_index][coloumn_index];
               
               }
            }
        }
            
    }
          return ret; 
    
    
}
