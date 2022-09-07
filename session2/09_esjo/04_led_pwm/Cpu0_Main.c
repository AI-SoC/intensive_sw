/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

#include "IfxCcu6_reg.h"
#include "IfxVadc_reg.h"
#include "IfxGtm_reg.h"

IfxCpu_syncEvent g_cpuSyncEvent = 0;

//  Port registers
#define PC1_BIT_LSB_IDX 11
#define PC2_BIT_LSB_IDX 19
#define PC3_BIT_LSB_IDX 27
#define PC5_BIT_LSB_IDX 11
#define PC7_BIT_LSB_IDX 27
#define P1_BIT_LSB_IDX  1
#define P2_BIT_LSB_IDX  2
#define P3_BIT_LSB_IDX  3
#define P5_BIT_LSB_IDX  5
#define P7_BIT_LSB_IDX  7

// SCU registers
#define LCK_BIT_LSB_IDX     1
#define ENDINIT_BIT_LSB_IDX 0
#define EXIS0_BIT_LSB_IDX   4
#define FEN0_BIT_LSB_IDX    8
#define REN0_BIT_LSB_IDX    9
#define EIEN0_BIT_LSB_IDX   11
#define INP0_BIT_LSB_IDX    12
#define IGP0_BIT_LSB_IDX    14

// SRC registers
#define SRPN_BIT_LSB_IDX    0
#define TOS_BIT_LSB_IDX     11
#define SRE_BIT_LSB_IDX     10

// CCU60 registers
#define DISS_BIT_LSB_IDX    1
#define DISR_BIT_LSB_IDX    0
#define CTM_BIT_LSB_IDX     7
#define T12PRE_BIT_LSB_IDX  3
#define T12CLK_BIT_LSB_IDX  0
#define T12STR_BIT_LSB_IDX  6
#define T12RS_BIT_LSB_IDX   1
#define INPT12_BIT_LSB_IDX  10
#define ENT12PM_BIT_LSB_IDX 7

// VADC registers
#define DISS_BIT_LSB_IDX    1
#define DISR_BIT_LSB_IDX    0
#define ANONC_BIT_LSB_IDX   0
#define ASEN0_BIT_LSB_IDX   24
#define CSM0_BIT_LSB_IDX    3
#define PRIO0_BIT_LSB_IDX   0
#define CSM_BIT_LSB_IDX     8
#define FLUSH_BIT_LSB_IDX   10
#define TREV_BIT_LSB_IDX    9
#define ENGT_BIT_LSB_IDX    0
#define RESPOS_BIT_LSB_IDX  21
#define RESREG_BIT_LSB_IDX  16
#define ICLSEL_BIT_LSB_IDX  0
#define VF_BIT_LSB_IDX      31
#define RESULT_BIT_LSB_IDX  0
#define ASSCH7_BIT_LSB_IDX  7

// GTM registers
#define DISS_BIT_LSB_IDX        1
#define DISR_BIT_LSB_IDX        0
#define SEL7_BIT_LSB_IDX        14
#define EN_FXCLK_BIT_LSB_IDX    22
#define FXCLK_SEL_BIT_LSB_IDX   0

// GTM - TOM0 registers
#define UPEN_CTRL1_BIT_LSB_IDX  18
#define HOST_TRIG_BIT_LSB_IDX  0
#define ENDIS_CTRL1_BIT_LSB_IDX 2
#define OUTEN_CTRL1_BIT_LSB_IDX 2
#define CLK_SRC_SR_BIT_LSB_IDX  12
#define OSM_BIT_LSB_IDX         26
#define TRIGOUT_BIT_LSB_IDX     24
#define SL_BIT_LSB_IDX          11 

unsigned int adcResult;

void initERU(void){
    // ERU settings

    // EXIS(External Input Selection) 001 => input 1 is selected
    // EXIS0 -> ESR2
    SCU_EICR1.U &= ~(0x7 << EXIS0_BIT_LSB_IDX); // clear 3 bits
    SCU_EICR1.U |= (0x1 << EXIS0_BIT_LSB_IDX);

    // ETL
    // detect falling edge
    // Falling Edge Enable(FEN)
    SCU_EICR1.U |= 0x1 << FEN0_BIT_LSB_IDX;
    SCU_EICR1.U |= 0x1 << REN0_BIT_LSB_IDX; // REN(rigine edge enable)

    //ETL
    // EIEN(External Input Enable)
    // enables the trigger generation
    SCU_EICR1.U |= 0x1 << EIEN0_BIT_LSB_IDX;

    // INP0(Input Node Pointer)
    // output 000(OGU 0)
    // event from ETL2 triggers OGU0
    SCU_EICR1.U &= ~(0x7 << INP0_BIT_LSB_IDX);

    // IGP(Interrupt Gating pattern)
    // OGU -> IOUT
    SCU_IGCR0.U &= ~(0x3 << IGP0_BIT_LSB_IDX);
    SCU_IGCR0.U |= 0x1 << IGP0_BIT_LSB_IDX;

    // SRC interrupt setting
    // SRPN(Service Request Priority Nubmer) setting.
    SRC_SCU_SCU_ERU0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |= 0x0A << SRPN_BIT_LSB_IDX; //id

    // T
    SRC_SCU_SCU_ERU0.U &= ~(0x3 << TOS_BIT_LSB_IDX); // CPU setting -> 0
    SRC_SCU_SCU_ERU0.U |= 1 << SRE_BIT_LSB_IDX; // service request is enabled
}

void initButton(void){
    P02_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX); // 0011 1110 mask
    P02_IOCR0.U |= ~(0x1F << PC1_BIT_LSB_IDX); // 0011 1110
}

void initLED(void){
    P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);
    P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX);

    P10_IOCR0.U |= 0x11 << PC1_BIT_LSB_IDX;
    P10_IOCR0.U |= 0x10 << PC2_BIT_LSB_IDX;

}

void initPWMLED(void){
    P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);  // reset P10_IOCR0 PC1
    P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX);  // reset P10_IOCR0 PC2

    P10_IOCR0.U |= 0x11 << PC1_BIT_LSB_IDX; // set P10.1 GTM Output (PWM)
    P10_IOCR0.U |= 0x10 << PC2_BIT_LSB_IDX; // set P10.2 push-pull general output

}

void initRGBLED(void){
    // reset Port IOCR register
    P02_IOCR4.U &= ~(0x1F << PC7_BIT_LSB_IDX);
    P10_IOCR4.U &= ~(0x1F << PC5_BIT_LSB_IDX);
    P10_IOCR0.U &= ~(0x1F << PC3_BIT_LSB_IDX);

    // set Port as general purpose output (push-pull)
    P02_IOCR4.U |= 0x10 << PC7_BIT_LSB_IDX;
    P10_IOCR4.U |= 0x10 << PC5_BIT_LSB_IDX;
    P10_IOCR0.U |= 0x10 << PC3_BIT_LSB_IDX;
}

void initCCU60(void){
    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0); //  wait until unlocked

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);

    CCU60_CLC.U &= ~(1 << DISR_BIT_LSB_IDX); // enable CCY

    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX); // 1111 1100
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0); // wait until unlocked

    // Modify Access to set ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0XFC) | (1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & ( 1 << LCK_BIT_LSB_IDX)) == 0); // wait until locked

    // CCU60 T12 configurations
    while((CCU60_CLC.U & ( 1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled

    CCU60_TCTR0.U &= ~(0x7 << T12CLK_BIT_LSB_IDX); // f_T12 = f_CCU6 / prescaler
    CCU60_TCTR0.U |= 0x2 << T12CLK_BIT_LSB_IDX; // f_CCU6 = 50 MHz, prescaler = 1024
    CCU60_TCTR0.U |= 0x1 << T12PRE_BIT_LSB_IDX; // f_T12 = 48,828 Hz

    CCU60_TCTR0.U &= ~(0x1 << CTM_BIT_LSB_IDX); // T12 auto reset when period match (PM) occur

    CCU60_T12PR.U = 24414 - 1;
    CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;

    CCU60_T12.U = 0;

    // CCU60 T12 PM interrupt setting
    CCU60_INP.U &= ~(0x3 << INPT12_BIT_LSB_IDX); // service request output SR0 selected
    CCU60_IEN.U |= 0x1 << ENT12PM_BIT_LSB_IDX; // enable T12 PM interrupt

    // SRC setting for CCU60
    SRC_CCU6_CCU60_SR0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_CCU6_CCU60_SR0.U |= 0x0B << SRPN_BIT_LSB_IDX; // set priority 0X0B
    SRC_CCU6_CCU60_SR0.U &= ~(0x3 << TOS_BIT_LSB_IDX); // CPU0 service T12 PM interrupt
    SRC_CCU6_CCU60_SR0.U |= 0x1 << SRE_BIT_LSB_IDX; // SR0 enabled

    // CCU60 T12 counting start
    CCU60_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX; // T12 start counting


}

void initVADC(void){
     // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0); //  wait until unlocked

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);

    VADC_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);     // enable VADC

    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & ( 1<< LCK_BIT_LSB_IDX)) != 0);  // wait until unlocked

    // Modify Access to set ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | ( 1 << LCK_BIT_LSB_IDX)) | ( 1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & ( 1 << LCK_BIT_LSB_IDX)) == 0);

    // VADC configurations
    while((VADC_CLC.U & ( 1 << DISS_BIT_LSB_IDX)) != 0);

    VADC_G4_ARBPR.U |= 0x3 << PRIO0_BIT_LSB_IDX;
    VADC_G4_ARBPR.U &= ~(0x1 << CSM0_BIT_LSB_IDX);
    VADC_G4_ARBPR.U |= 0x1 << ASEN0_BIT_LSB_IDX;

    VADC_G4_QMR0.U &= ~(0x3 << ENGT_BIT_LSB_IDX);
    VADC_G4_QMR0.U |= 0x1 << ENGT_BIT_LSB_IDX;
    VADC_G4_QMR0.U |= 0x1 << FLUSH_BIT_LSB_IDX;

    VADC_G4_ARBCFG.U |= 0x3 << ANONC_BIT_LSB_IDX;
    
    VADC_G4_ICLASS0.U &= ~(0x7 << ANONC_BIT_LSB_IDX);

    // VADC Group 4 Channel 7 configuration
    VADC_G4_CHCTR7.U |= 0x1 << RESPOS_BIT_LSB_IDX;
    VADC_G4_CHCTR7.U &= ~(0xF << RESREG_BIT_LSB_IDX);
    VADC_G4_CHCTR7.U &= ~(0x3 << ICLSEL_BIT_LSB_IDX);
    
    VADC_G4_CHASS.U |= 0x1 << ASSCH7_BIT_LSB_IDX;
}

void initGTM(void){
    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | ( 1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & ( 1 << LCK_BIT_LSB_IDX)) != 0); // wait until unlocked

    // Modify Access to clear ENDINT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTS_CON0.U ^ 0xFC) | ( 1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0 ); // wait until locked

    GTM_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);  // enable GTM

    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & ( 1 << LCK_BIT_LSB_IDX)) != 0); // wait until unlocked

    // Modify Access to clear ENDINT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTS_CON0.U ^ 0xFC) | ( 1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0 ); // wait until locked
    
    while((GTM_CLC.U & ( 1 << DISS_BIT_LSB_IDX)) != 0); // wait until GTM module enabled

    // GTM clock configuration
    GTM_CMU_FXCLK_CTRL.U &= ~(0xF << FXCLK_SEL_BIT_LSB_IDX);    // input clock of CLU_fXCLK --> CMU_GCLK_EN
    GTM_CMU_CLK_EN.U |= 0x2 << EN_FXCLK_BIT_LSB_IDX;    //enable all CMU_FXCLK

    // GTM TOM0 PWM configuration
    GTM_TOM0_TGC0_GLB_CTRL.U |= 0x2 << UPEN_CTRL1_BIT_LSB_IDX;      // TOM channel 1 update enable
    
    GTM_TOM0_TGC0_ENDIS_CTRL.U |= 0x2 << ENDIS_CTRL1_BIT_LSB_IDX;   // enable channel 1 on update trigger

    GTM_TOM0_TGC0_OUTEN_CTRL.U |= 0x2 << OUTEN_CTRL1_BIT_LSB_IDX;   // enable channel 1 output on update trigger

    GTM_TOM0_CH1_CTRL.U |= 0x1 << SL_BIT_LSB_IDX;           //high signal level for duty cycle
    GTM_TOM0_CH1_CTRL.U |= 0x1 << CLK_SRC_SR_BIT_LSB_IDX;   // clock source --> CMU_FXCLK(1) = 6250 kHz
    GTM_TOM0_CH1_CTRL.U &= ~(0x1 << OSM_BIT_LSB_IDX);       // continuous mode enable
    GTM_TOM0_CH1_CTRL.U &= ~(0x1 << TRIGOUT_BIT_LSB_IDX);   // TRIG[x] = TRIG[x-1]

    GTM_TOM0_CH1_SR0.U = 12500 - 1; // PWM freq. = 6250 kHz / 12500 = 500 Hz
    
    GTM_TOM0_CH1_SR1.U = 1250 - 1;  // duty cycle = 1250 / 12500 = 10 % (temporary)

    GTM_TOUTSEL6.U &= ~(0x3 << SEL7_BIT_LSB_IDX);   // TOUT103 --> TOM0 channel 1
                                                    // 103 = 16 * 6 + 7
}

void VADC_startConversion(void){
    VADC_G4_QINR0.U = 0x07;     // no.  of Request CHannel = 7

    VADC_G4_QMR0.U |= 0x1 << TREV_BIT_LSB_IDX;   // Generate Conversion Start Trigger Event
}

unsigned int VADC_readResult(void){
    unsigned int result;

    while( ( VADC_G4_RES0.U & (0x1 << VF_BIT_LSB_IDX)) == 0);   // wait until read available
    result = VADC_G4_RES0.U & (0xFFF << RESULT_BIT_LSB_IDX);    //  read ADC valud

    return result;
}

// __interrupt(0x0A) __vector_table(0)
// void ERU0_ISR(void){
//     P10_OUT.U ^= 0x1 << P1_BIT_LSB_IDX; // toggle P10.1 (LED D12 RED)
// }

// Pulse
//__interrupt(0x0A) __vector_table(0)
//void ERU0_ISR(void){
//     P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;
//     for(int i = 0 ; i < 1000000 ; i++);
//    P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);
//}

// delayed led on
// __interrupt(0x0A) __vector_table(0)
// void ERU0_ISR(void){
//     P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;
//     for(int i = 0 ; i < 1000000 ; i++);
//     P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);
// }
// __interrupt(0x0A) __vector_table(0)
// void ERU0_ISR(void){
//     // button status check
//     if( (P02_IN.U & (0x1 << P1_BIT_LSB_IDX)) == 0 ) // button pushed
//     {
//         P10_OUT.B.P1 = 0x1;
//         CCU60_T12PR.U = 12207 - 1;                      // PM interrupt freq. = f_T12 / (T12PR + 1)
//         CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;     // load T12PR from shadow register
//     }
//     else{       // button released
//         P10_OUT.B.P1 = 0x0;
//         CCU60_T12PR.U = 24414 - 1;                  // PM interrupt freq.  = f_T12 / (T12PR + 1)
//         CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX; // load T12PR from shadow register
//     }
// }


// __interrupt(0x0B) __vector_table(0)
// void CCU60_T12_ISR(void){
//     P10_OUT.U ^= 0x1 << P2_BIT_LSB_IDX; // toggle P10.2 (LED D13 BlUE)
// }

__interrupt(0x0B) __vector_table(0)
void CCU60_T12_ISR(void){
    P10_OUT.U ^= 0x1 << P2_BIT_LSB_IDX;

    VADC_startConversion();
    adcResult = VADC_readResult();
}


int core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    // initERU();
    initCCU60();
    initLED();
    initRGBLED();
    initVADC();
    initGTM();

    GTM_TOM0_TGC0_GLB_CTRL.U |= 0x1 << HOST_TRIG_BIT_LSB_IDX;   // trigger update request signal4

    while(1)
    {
    //    VADC_startConversion();
    //    adcResult = VADC_readResult();

       if(adcResult >= 3096){
           P02_OUT.U |= 0x1 << P7_BIT_LSB_IDX;     // P2.7
           P10_OUT.U &= ~(0x1 << P5_BIT_LSB_IDX);  // P10.5
           P10_OUT.U &= ~(0x1 << P3_BIT_LSB_IDX);  // P10.3

            GTM_TOM0_CH1_SR1.U = 0;
       }
       else if(adcResult >= 2048){
           P02_OUT.U &= ~(0x1 << P7_BIT_LSB_IDX);  // P2.7
           P10_OUT.U |= 0x1 << P5_BIT_LSB_IDX;     // P10.5
           P10_OUT.U &= ~(0x1 << P3_BIT_LSB_IDX);  // P10.3

           GTM_TOM0_CH1_SR1.U = 1000;
       }
       else if(adcResult >= 1024){
           P02_OUT.U &= ~(0x1 << P7_BIT_LSB_IDX);  // P2.7
           P10_OUT.U &= ~(0x1 << P5_BIT_LSB_IDX);  // P10.5
           P10_OUT.U |= 0x1 << P3_BIT_LSB_IDX;     // P10.3
           
           GTM_TOM0_CH1_SR1.U = 5000;

       }
       else{
           P02_OUT.U |= 0x1 << P7_BIT_LSB_IDX; // P2.7
           P10_OUT.U |= 0x1 << P5_BIT_LSB_IDX; // P10.5
           P10_OUT.U |= 0x1 << P3_BIT_LSB_IDX; // P10.3

           GTM_TOM0_CH1_SR1.U = 12500;

       }
    }
    return (1);
}
