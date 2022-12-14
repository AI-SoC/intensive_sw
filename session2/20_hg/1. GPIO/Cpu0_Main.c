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

// Port registers
#define PC1_BIT_LSB_IDX         11
#define PC2_BIT_LSB_IDX         19
#define P1_BIT_LSB_IDX          1
#define P2_BIT_LSB_IDX          2

// SCU REGISTER
#define LCK_BIT_LSB_IDX         1
#define ENDINIT_BIT_LSB_IDX     0
#define EXIS0_BIT_LSB_IDX       4
#define FEN0_BIT_LSB_IDX        8
#define EIEN0_BIT_LSB_IDX       11
#define INP0_BIT_LSB_IDX        12
#define IGP0_BIT_LSB_IDX        14

// SRC REGISTERS
#define SRPN_BIT_LSB_IDX        0
#define TOS_BIT_LSB_IDX         11
#define SRE_BIT_LSB_IDX         10

IfxCpu_syncEvent g_cpuSyncEvent = 0;

void initCCU60(void);
void initERU(void);
void initLED(void);
void initButton(void);

__interrupt(0x0A)   __vector_table(0) // interrupt ???? ?? ???????? ???? ????
void ERU0_ISR(void);

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
    
    initERU();
    initLED();
    initButton();

    // unsigned char pre = 1, cur = 1;

    while(1)
    {
        /*
        // 1. GPIO OUT
        for(uint32 i = 0; i <1000000; i++);   // sw DELAY

        P10_OUT.U ^= 0x1 << P1_BIT_LSB_IDX;

        for(uint32 i = 0; i <10000000; i++);   // sw DELAY
        P10_OUT.U ^= 0x1 << P2_BIT_LSB_IDX;

        // 2. GPOI IN
        if( (P02_IN.U & (0x1 << P1_BIT_LSB_IDX)) == 0 ) // check button status
        {
            P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;         // clear P10.1 (LED D13 RED)
        }
        else
        {
            P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);      // clear P10.1 (LED D13 RED)
        }
        */

        /*
        // 3.sampling
        int a, b, c;

        // 1 == on
        a = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(uint32 i = 0; i <10000; i++);   // sw DELAY;

        b = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(uint32 i = 0; i <10000; i++);   // sw DELAY

        c = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(uint32 i = 0; i <10000; i++);   // sw DELAY

        if (a == 0 && b == 0 && c == 0){
            P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;
        }
        else{
            P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);
        }
        */

        // 4. Edge Detection
        /*
        pre = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(uint32 i = 0; i <10000; i++);   // sw DELAY
        cur = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);

        if ((pre ^ cur) == 1)
        {
            P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;
            for(uint32 i = 0; i <100000; i++);   // sw DELAY
            P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);
        }
        */

        // 5. SCU [ERU]

    }


    return (1);
}

void initButton(void)
{
    P02_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);

    P02_IOCR0.U |= 0x02 << PC1_BIT_LSB_IDX;
}

void initLED(void)
{
    // RESET P10_IOCR0 PC1,2
    P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);
    P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX);

    // SET P10.1,2 push-pull general output
    P10_IOCR0.U |= (0x10 << PC1_BIT_LSB_IDX);
    P10_IOCR0.U |= (0x10 << PC2_BIT_LSB_IDX);
}


// ERU Interrupt ???????? ????
void initERU(void)
{
    // ERU setting
    // ~?????? ??????
    SCU_EICR1.U &= ~(0x7 << EXIS0_BIT_LSB_IDX);     // EICR1 ???????????? ?????? ??[EXIS0] ???? (1???? ????)
    SCU_EICR1.U |=  (0x1 << EXIS0_BIT_LSB_IDX);

    // ETL setting
    SCU_EICR1.U |=  0x1 << FEN0_BIT_LSB_IDX;      // Push ?????? falling edge ??????

    // 2 - ???? ?????? ?? ?? ??????????
    /*
    SCU_EICR1.U |= 0x1 << REN0_BIT_LSB_IDX;
    */


    SCU_EICR1.U |=  0x1 << EIEN0_BIT_LSB_IDX;     // trigger enable ??????

    // OGU - Output Gating Unit - Trigger ?????? ???????? Request ???? ?????? ??
    SCU_EICR1.U &= ~(0x7 << INP0_BIT_LSB_IDX);

    // IGCR - ???????? ?????? ???? ????
    SCU_IGCR0.U &= ~(0x3 << IGP0_BIT_LSB_IDX);
    SCU_IGCR0.U |=  (0x1 << IGP0_BIT_LSB_IDX);

    // SRC Interrupt setting
    SRC_SCU_SCU_ERU0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |=   0x0A << SRPN_BIT_LSB_IDX;       // ???????? ?? ???? ???? ????

    SRC_SCU_SCU_ERU0.U &= ~(0x3  << TOS_BIT_LSB_IDX);       //  TOS ????  - CPU0

    SRC_SCU_SCU_ERU0.U |=   1    << SRE_BIT_LSB_IDX;        // SRE 1?? ???? - interrupt enable
}

void ERU0_ISR(void)
{
    // 0
    /*
    P10_OUT.U ^= 0x1 << P1_BIT_LSB_IDX; // ?????? ???? ???????? ==>
    */

    // 1
    /*
    P10_OUT.U ^= 0x1 << P1_BIT_LSB_IDX;
    for(uint32 i = 0; i <300000; i++);   // sw DELAY;
    P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX); // ?????? ???? ????????
    */

    // 2?? init-setting ????

    // 3
    unsigned char a,b,c;

    a = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
    for(uint32 i = 0; i <10000000; i++);   // sw DELAY;

    b = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
    for(uint32 i = 0; i <10000000; i++);   // sw DELAY;

    c = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
    for(uint32 i = 0; i <10000000; i++);   // sw DELAY;

    if ( a == 0 && b == 0 && c == 0)
    {
        P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;
        for(uint32 i = 0; i <5000000; i++);   // sw DELAY;
        P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX); // ?????? ???? ????????
    }
}

void initCCU60(void)
{
    // PW Access to unlock SCU_WDTSCON0
        // unlock => ENDINIT ???? => CCY
            // ^?? ???? ???????? ???? -> PW?? ???????? ????????
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0);  // unlock ????

}

