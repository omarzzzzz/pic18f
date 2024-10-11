#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/application.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/application.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_LAYER/BUTTON/button.c ECU_LAYER/DC_MOTOR/ecu_dcMotor.c ECU_LAYER/ecu_seven_segment/seven_segment.c ECU_LAYER/KEYPAD/ecu_keypad.c ECU_LAYER/LCD/ecu_lcd.c ECU_LAYER/LED/ecu_led.c ECU_LAYER/Relay/relay.c MCAL_LAYER/ADC/hal_adc.c MCAL_LAYER/CCP/hal_ccp.c MCAL_LAYER/EEPROM/hal_eeprom.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/Interrupt/mcal_internal_interrupt.c MCAL_LAYER/Interrupt/mcal_external_interrupt.c MCAL_LAYER/Interrupt/mcal_interrupt_manager.c MCAL_LAYER/timer0/hal_timer0.c MCAL_LAYER/TIMER1/hal_timer1.c MCAL_LAYER/TIMER2/hal_timer2.c MCAL_LAYER/TIMER3/hal_timer3.c application.c MCAL_LAYER/device_config.c MCAL_LAYER/USART/hal_usart.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1 ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1 ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1 ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1 ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1 ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1 ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1 ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1 ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1 ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1 ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1 ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1 ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1

# Source Files
SOURCEFILES=ECU_LAYER/BUTTON/button.c ECU_LAYER/DC_MOTOR/ecu_dcMotor.c ECU_LAYER/ecu_seven_segment/seven_segment.c ECU_LAYER/KEYPAD/ecu_keypad.c ECU_LAYER/LCD/ecu_lcd.c ECU_LAYER/LED/ecu_led.c ECU_LAYER/Relay/relay.c MCAL_LAYER/ADC/hal_adc.c MCAL_LAYER/CCP/hal_ccp.c MCAL_LAYER/EEPROM/hal_eeprom.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/Interrupt/mcal_internal_interrupt.c MCAL_LAYER/Interrupt/mcal_external_interrupt.c MCAL_LAYER/Interrupt/mcal_interrupt_manager.c MCAL_LAYER/timer0/hal_timer0.c MCAL_LAYER/TIMER1/hal_timer1.c MCAL_LAYER/TIMER2/hal_timer2.c MCAL_LAYER/TIMER3/hal_timer3.c application.c MCAL_LAYER/device_config.c MCAL_LAYER/USART/hal_usart.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/application.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1: ECU_LAYER/BUTTON/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1 ECU_LAYER/BUTTON/button.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.d ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1: ECU_LAYER/DC_MOTOR/ecu_dcMotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1 ECU_LAYER/DC_MOTOR/ecu_dcMotor.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.d ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1: ECU_LAYER/ecu_seven_segment/seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/ecu_seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1 ECU_LAYER/ecu_seven_segment/seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.d ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1: ECU_LAYER/KEYPAD/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1 ECU_LAYER/KEYPAD/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.d ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1: ECU_LAYER/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ECU_LAYER/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1: ECU_LAYER/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LED" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1 ECU_LAYER/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.d ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/Relay/relay.p1: ECU_LAYER/Relay/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/Relay" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1 ECU_LAYER/Relay/relay.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/Relay/relay.d ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1: MCAL_LAYER/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 MCAL_LAYER/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1: MCAL_LAYER/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/CCP" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1 MCAL_LAYER/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.d ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1: MCAL_LAYER/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 MCAL_LAYER/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1: MCAL_LAYER/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 MCAL_LAYER/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1: MCAL_LAYER/timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/timer0" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1 MCAL_LAYER/timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.d ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1: MCAL_LAYER/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 MCAL_LAYER/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1: MCAL_LAYER/TIMER2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1 MCAL_LAYER/TIMER2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.d ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1: MCAL_LAYER/TIMER3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1 MCAL_LAYER/TIMER3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.d ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1: MCAL_LAYER/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/USART" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 MCAL_LAYER/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1: ECU_LAYER/BUTTON/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1 ECU_LAYER/BUTTON/button.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.d ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/BUTTON/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1: ECU_LAYER/DC_MOTOR/ecu_dcMotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1 ECU_LAYER/DC_MOTOR/ecu_dcMotor.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.d ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/DC_MOTOR/ecu_dcMotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1: ECU_LAYER/ecu_seven_segment/seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/ecu_seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1 ECU_LAYER/ecu_seven_segment/seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.d ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ecu_seven_segment/seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1: ECU_LAYER/KEYPAD/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1 ECU_LAYER/KEYPAD/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.d ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/KEYPAD/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1: ECU_LAYER/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LCD" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1 ECU_LAYER/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1: ECU_LAYER/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LED" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1 ECU_LAYER/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.d ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/Relay/relay.p1: ECU_LAYER/Relay/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/Relay" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1 ECU_LAYER/Relay/relay.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/Relay/relay.d ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/Relay/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1: MCAL_LAYER/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 MCAL_LAYER/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1: MCAL_LAYER/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/CCP" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1 MCAL_LAYER/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.d ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1: MCAL_LAYER/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1 MCAL_LAYER/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1: MCAL_LAYER/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 MCAL_LAYER/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1: MCAL_LAYER/timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/timer0" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1 MCAL_LAYER/timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.d ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1: MCAL_LAYER/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1 MCAL_LAYER/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.d ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1: MCAL_LAYER/TIMER2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1 MCAL_LAYER/TIMER2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.d ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1: MCAL_LAYER/TIMER3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1 MCAL_LAYER/TIMER3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.d ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/TIMER3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1: MCAL_LAYER/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/USART" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1 MCAL_LAYER/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/application.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/application.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/application.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/application.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/application.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/application.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/application.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
