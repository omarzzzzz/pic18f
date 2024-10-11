
/* 
 * File:   hal_usart.c
 * Author: omars
 *
 * Created on August 15, 2024, 11:09 PM
 */
#include "hal_usart.h"

static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart);

std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart){
    std_ReturnType ret=0;
    if(NULL == _eusart )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}
std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart){
     std_ReturnType ret=0;
        if(NULL == _eusart )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}

std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data){
     std_ReturnType ret=0;
        if(NULL == _data )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}
std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data){
     std_ReturnType ret=0;
            if(NULL == _data )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}
std_ReturnType EUSART_ASYNC_RX_Restart(void){
    
}

std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data){
     std_ReturnType ret=0;
            if(NULL == _data )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}
std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data, uint16 str_len){
     std_ReturnType ret=0;
            if(NULL == _data )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}
std_ReturnType EUSART_ASYNC_WriteByteNonBlocking(uint8 _data){
     std_ReturnType ret=0;
            if(NULL == _data )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}
std_ReturnType EUSART_ASYNC_WriteStringNonBlocking(uint8 *_data, uint16 str_len){
     std_ReturnType ret=0;
            if(NULL == _data )
    {
        ret=E_NOT_OK;
    }
    else
    {
        
    }
}


static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart)
{
    
     float Baud_Rate_Temp = 0;
    switch(_eusart->baudrate_gen_gonfig){
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 64) - 1;
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        default : ;
    }
    SPBRG = (uint8)((uint32)Baud_Rate_Temp);
    SPBRGH = (uint8)(((uint32)Baud_Rate_Temp) >> 8);
}