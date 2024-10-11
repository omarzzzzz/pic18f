/* 
 * File:   hal_eeprom.c
 * Author: omars
 *
 * Created on July 16, 2024, 10:49 PM
 */

#include "hal_eeprom.h"
#include "../Interrupt/mcal_internal_interrupt.h"

std_ReturnType EEPROM_Data_Write_byte(uint16 bAdd,uint8 bData){
    std_ReturnType ret=E_OK;
    
    /*Read the interrupt if enabled or disabled*/
    uint8 interrupt_var=INTCONbits.GIE;
    /*Update The Address Registers*/
    EEADRH =(uint8)((bAdd >>8) & 0x03);
    EEADR=(uint8) (bAdd & 0xFF);
    /*update the data register*/
    EEDATA= bData;
    /* Select access EEPROM Data*/
    EECON1bits.EEPGD =0; // PUT 1 TO ACCESS FLASH MEMORY
    EECON1bits.CFGS =0; // 1 TO ACCESS CONFIGURATION REGISTERS
    /*Allow writing cycles to EEprom*/
    EECON1bits.WREN =1;
    /* Disable all interrupts */
#if INTERUPT_PRIORITY__FEATURE_ENABLE == 1
        /* this function enables all high prio interrupts*/
        INTERRUPT_GLOBAL_HIGH_ENABLE()  ;   
#else            
        INTERRUPT_GLOBAL_DISABLE();
#endif
    /* write the required sequence*/
    EECON2=0X55;
    EECON2=0XAA;
    /* INITITATES A DATA EEPROM ERASE/WRITE  */
    EECON1bits.WR=1;
    /* wait for write to be finished*/
    while(EECON1bits.WR);
   
    EECON1bits.WREN=0;            
    /* enable all inetrrupts*/
    INTCONbits.GIE=interrupt_var;
    
    return ret;
}
std_ReturnType EEPROM_Data_Read_byte(uint16 bAdd,uint8 *bData){
    std_ReturnType ret=E_OK;
    if(NULL == bData )
    {
        ret=E_NOT_OK;
    }
    else
    {
         /*Read the interrupt if enabled or disabled*/
    uint8 interrupt_var=INTCONbits.GIE;
    /*Update The Address Registers*/
    EEADRH =(uint8)((bAdd >>8) & 0x03);
    EEADR=(uint8) (bAdd & 0xFF);
    /* Select access EEPROM Data*/
    EECON1bits.EEPGD =0; // PUT 1 TO ACCESS FLASH MEMORY
    EECON1bits.CFGS =0; // 1 TO ACCESS CONFIGURATION REGISTERS
    
    EECON1bits.RD=1;
    NOP();
    NOP();
    *bData=EEDATA;
    }
    return ret;
    
    
}