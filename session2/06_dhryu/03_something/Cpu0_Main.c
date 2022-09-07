
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#define PC1_BIT_LSB_IDXX    3
#define PC1_BIT_LSB_IDX     11
#define PC2_BIT_LSB_IDX     19
#define P1_BIT_LSB_IDX      1
#define P2_BIT_LSB_IDX      2
#define EXIS0_BIT_LSB_IDX   4
#define FEN0_BIT_LSB_IDX    8
#define EIEN0_BIT_LSB_IDX   11
#define INP0_BIT_LSB_IDX    12
#define IGP0_BIT_LSB_IDX    14
#define SRPN_BIT_LSB_IDX    0
#define TOS_BIT_LSB_IDX     11
#define SRE_BIT_LSB_IDX     10
#define REN0_BIT_LSB_IDX    9

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
void initERU(void){
    SCU_EICR1.U &= ~(0x7 << EXIS0_BIT_LSB_IDX);  // ERS2�� EICR1. EXIS0 P02.1 enable
    SCU_EICR1.U |= (0x1 << EXIS0_BIT_LSB_IDX);   //

    // Detect Event (edge) ��¿����� �ϰ�������?
    SCU_EICR1.U |= 0x1 << FEN0_BIT_LSB_IDX;   // �� �ڵ� �����
    SCU_EICR1.U |= 0x1 << EIEN0_BIT_LSB_IDX;

    // �ϰ� EDGIE���� �۵��ϰ� �ϴ� �ڵ�
    //SCU_EICR1.U |= 0x1 << REN0_BIT_LSB_IDX;

    SCU_EICR0.U &= ~(0x3 << IGP0_BIT_LSB_IDX);  // OGU0�� IGP0�� 2BIT�� ����ϴϱ� CLEAR ����
    SCU_IGCR0.U |= 0x1 << IGP0_BIT_LSB_IDX;     // CLEAR�� 15 14�κп� IGP0���� 01�� �־ IOUT trigger event�ϰ� ����

    // ���⼭���� SRC Interrupt setting
    SRC_SCU_SCU_ERU0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |= 0x0A << SRPN_BIT_LSB_IDX;
    SRC_SCU_SCU_ERU0.U &= ~(0x3 << TOS_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |= 1 << SRE_BIT_LSB_IDX;

}
IfxCpu_syncEvent g_cpuSyncEvent = 0;

__interrupt(0x0A) __vector_table(0)           //0x0A ���� interrupt ID�� ������, CPU0���� ó����
void ERU0_ISR(void){
    unsigned char a,b,c;
    a = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
    for(unsigned int i = 0 ;i<9876543; i++);
    b = P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
    for(unsigned int i = 0;i<9876543;i++);
    c =  P02_IN.U & (0x1 << P1_BIT_LSB_IDX);
    if(a==0 && b==0 && c==0){
        P10_OUT.U ^= 0x1 << P1_BIT_LSB_IDX; // toggle P10.1 (LED D12 RED)
        for(int i = 0;i<98765432;i++);
        P10_OUT.U &= ~(0x1 <<P1_BIT_LSB_IDX);
    }

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
    
    initERU();
    initLED();
    initButton();

    while(1)
    {
    }
    return (1);
}
