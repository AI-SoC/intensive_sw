#ifndef CPU0_MAIN_H
#define CPU0_MAIN_H


#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxCcu6_reg.h"
#include "IfxVadc_reg.h"
#include "IfxGtm_reg.h"
#include "IfxSrc_reg.h"

#include "ADC_Potentiometer.h"
#include "CCU_Timer.h"
#include "ERU_switch_interrupt.h"
#include "GTM_control_PWM.h"
#include "LED_control.h"
#include "RGB_control.h"
#include "GPIO_Button.h"

// Port Register
#define PC1_BIT_LSB_IDX     11  //Offset (P10_IOCR0 -> PC1)
#define PC2_BIT_LSB_IDX     19  //Offset (P10_IOCR0 -> PC2)
#define P1_BIT_LSB_IDX      1
#define P2_BIT_LSB_IDX      2


// SCU register
#define LCK_BIT_LSB_IDX         1
#define ENDINIT_BIT_LSB_IDX     0
#define EXIS0_BIT_LSB_IDX   4
#define FEN0_BIT_LSB_IDX    8
#define EIEN0_BIT_LSB_IDX   11
#define INP0_BIT_LSB_IDX    12
#define IGP0_BIT_LSB_IDX    14

//SRC register
#define SRPN_BIT_LSB_IDX    0
#define TOS_BIT_LSB_IDX     11
#define SRE_BIT_LSB_IDX     10

// CCU Register
#define DISR_BIT_LSB_IDX    0
#define DISS_BIT_LSB_IDX    1
#define CTM_BIT_LSB_IDX     7
#define T12CLK_BIT_LSB_IDX  0
#define T12PRE_BIT_LSB_IDX  3

#define T12STR_BIT_LSB_IDX  6
#define T12RS_BIT_LSB_IDX   1

#define INPT12_BIT_LSB_IDX  10
#define ENT12PM_BIT_LSB_IDX 7




#endif /* GTM_CONTROL_PWM_H_ */
