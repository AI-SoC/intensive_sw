
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#define PC1_BIT_LSB_IDXX 3
#define PC1_BIT_LSB_IDX 11
#define PC2_BIT_LSB_IDX 19
#define P1_BIT_LSB_IDX 1
#define P2_BIT_LSB_IDX 2

void initButton(void){
    P02_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);   // reset P02_IOCR0 PC1
    P02_IOCR0.U |= 0x02 << PC1_BIT_LSB_IDX;      // set P02.1 general input (pull-up connected)

    P02_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDXX);   // reset P02_IOCR0 PC1
    P02_IOCR0.U |= 0x02 << PC1_BIT_LSB_IDXX;      // set P02.1 general input (pull-up connected)
}

void initLED(void){
    P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX); // reset P10_IOCR0 PC1
    P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX); // reset P10_IOCR0 PC2
    P10_IOCR0.U |= 0x10 << PC1_BIT_LSB_IDX;   // set P10.1 push-pull general output
    P10_IOCR0.U |= 0x10 << PC2_BIT_LSB_IDX;   // set P10.2 push-pull general output
}
IfxCpu_syncEvent g_cpuSyncEvent = 0;

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
    
    initLED();
    initButton();

    while(1)
    {   /*
        int a = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(unsigned int i = 0; i< 10000000; i++);
        int b = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(unsigned int i = 0; i< 10000000; i++);
        int c = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
        for(unsigned int i = 0; i< 10000000; i++);
        if(a==0 && b==0 && c==0){
            P10_OUT.U |= (0x1<<P1_BIT_LSB_IDX);
        }
        else{
            P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);
        }*/

        if((P02_IN.U & (0x1 << 0))==0){
            P10_OUT.U |= 0x1 << P1_BIT_LSB_IDX;
        }
        else{
            P10_OUT.U &= ~(0x1 << P1_BIT_LSB_IDX);
        }
    }
    return (1);
}
