#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxCcu6_reg.h"
#include "IfxVadc_reg.h"

// Port register
#define PC1_BIT_LSB_IDX     11
#define PC2_BIT_LSB_IDX     19
#define P1_BIT_LSB_IDX      1
#define P2_BIT_LSB_IDX      2

// SCU register
#define LCK_BIT_LSB_IDX     1
#define ENDINIT_BIT_LSB_IDX 0
#define EXIS0_BIT_LSB_IDX   4
#define FEN0_BIT_LSB_IDX    8
#define REN0_BIT_LSB_IDX    9
#define EIEN0_BIT_LSB_IDX   11
#define INP0_BIT_LSB_IDX    12
#define IGP0_BIT_LSB_IDX    14

// SRC register
#define SRPN_BIT_LSB_IDX    0
#define TOS_BIT_LSB_IDX     11
#define SRE_BIT_LSB_IDX     10

// CCU60 register
#define DISS_BIT_LSB_IDX    1
#define DISR_BIT_LSB_IDX    0
#define CTM_BIT_LSB_IDX     7
#define T12PRE_BIT_LSB_IDX  3
#define T12CLK_BIT_LSB_IDX  0
#define T12STR_BIT_LSB_IDX  6
#define T12RS_BIT_LSB_IDX   1
#define INPT12_BIT_LSB_IDX 10
#define ENT12PM_BIT_LSB_IDX 7

// RGBLED register
#define PC7_BIT_LSB_IDX     27
#define PC5_BIT_LSB_IDX     11
#define PC3_BIT_LSB_IDX     27
#define P7_BIT_LSB_IDX      7
#define P5_BIT_LSB_IDX      5
#define P3_BIT_LSB_IDX      3

// VADC register
#define ANONC_BIT_LSB_IDX   0
#define ASEN0_BIT_LSB_IDX   24
#define CSM0_BIT_LSB_IDX    3
#define PRIO0_BIT_LSB_IDX   0
#define CMS_BIT_LSB_IDX     8
#define FLUSH_BIT_LSB_IDX   10
#define TREV_BIT_LSB_IDX    9
#define ENGT_BIT_LSB_IDX     0
#define RESPOS_BIT_LSB_IDX  21
#define RESREG_BIT_LSB_IDX  16
#define ICLSEL_BIT_LSB_IDX  0
#define VF_BIT_LSB_IDX      31
#define RESULT_BIT_LSB_IDX  0
#define ASSCH7_BIT_LSB_IDX  7

// Port register
#define PC1_BIT_LSB_IDX     11
#define PC2_BIT_LSB_IDX     19
#define PC3_BIT_LSB_IDX     27
#define PC5_BIT_LSB_IDX     11
#define PC7_BIT_LSB_IDX     27
#define P1_BIT_LSB_IDX      1
#define P2_BIT_LSB_IDX      2
#define P3_BIT_LSB_IDX      3
#define P5_BIT_LSB_IDX      5
#define P7_BIT_LSB_IDX      7

// initButton
void initButton(void){
    P02_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);   // reset P02_IOCR0 PC1
    P02_IOCR0.U |= 0x02 << PC1_BIT_LSB_IDX;      // set P02.1 general input (pull-up connected)
}

// initLED
void initLED(void){
    P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX); // reset P10_IOCR0 PC1
    P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX); // reset P10_IOCR0 PC2
    P10_IOCR0.U |= 0x10 << PC1_BIT_LSB_IDX;   // set P10.1 push-pull general output
    P10_IOCR0.U |= 0x10 << PC2_BIT_LSB_IDX;   // set P10.2 push-pull general output
}
void initERU(void){
    SCU_EICR1.U &= ~(0x7 << EXIS0_BIT_LSB_IDX);  // ERS2에 EICR1. EXIS0 P02.1 enable
    SCU_EICR1.U |= (0x1 << EXIS0_BIT_LSB_IDX);   //

    // Detect Event (edge) 상승엣지냐 하강엣지냐?
    SCU_EICR1.U |= 0x1 << FEN0_BIT_LSB_IDX;   // 이 코드 실행시
    SCU_EICR1.U |= 0x1 << EIEN0_BIT_LSB_IDX;

    // 하강 EDGIE에서 작동하게 하는 코드
    SCU_EICR1.U |= 0x1 << REN0_BIT_LSB_IDX;

    SCU_EICR0.U &= ~(0x3 << IGP0_BIT_LSB_IDX);  // OGU0의 IGP0이 2BIT을 사용하니깐 CLEAR 과정
    SCU_IGCR0.U |= 0x1 << IGP0_BIT_LSB_IDX;     // CLEAR한 15 14부분에 IGP0값에 01값 넣어서 IOUT trigger event하게 해줌

    // 여기서부터 SRC Interrupt setting
    SRC_SCU_SCU_ERU0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |= 0x0A << SRPN_BIT_LSB_IDX;
    SRC_SCU_SCU_ERU0.U &= ~(0x3 << TOS_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |= 1 << SRE_BIT_LSB_IDX;
}

// initCCU60
void initCCU60(void){
    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1<<ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1<< LCK_BIT_LSB_IDX)) != 0);    // wait until unlocked

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX))==0);     // wait until locked

    CCU60_CLC.U &= ~(1 << DISR_BIT_LSB_IDX); // enable CCY

    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1<<ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1<< LCK_BIT_LSB_IDX)) != 0);    // wait until unlocked

    // Modify Access to SET ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX))==0);     // wait until locked

    //CCU60 T12 configurations
    while((CCU60_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0);  // wait until CCU60 module enabled

    CCU60_TCTR0.U &= ~(0x7 << T12CLK_BIT_LSB_IDX);    // f_T12 = f_CCU6 / prescaler
    CCU60_TCTR0.U |= 0X2 << T12CLK_BIT_LSB_IDX;       // f_CCU6 = 50MHz, prescaler = 1024
    CCU60_TCTR0.U |= 0X1 << T12PRE_BIT_LSB_IDX;       // f_T12 = 48,828Hz
    CCU60_TCTR0.U &= ~(0x1 << CTM_BIT_LSB_IDX);       // T12 auto reset when period match occur

    CCU60_T12PR.U = 48828 - 1;  // 0.5초마다 48828 / 2 -1
    CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;  // load T12PR from shadow register

    CCU60_T12.U = 0;  // Clear T12 counter register


    //CCU60 T12 PM interrupt setting
    CCU60_INP.U &= ~(0x3 << INPT12_BIT_LSB_IDX);   // service request output SR0 selected
    CCU60_IEN.U |= 0x1 << ENT12PM_BIT_LSB_IDX;     // enable T12 PM interrupt


    SRC_CCU6_CCU60_SR0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_CCU6_CCU60_SR0.U |= 0x0B << SRPN_BIT_LSB_IDX;    // set priority 0x08

    SRC_CCU6_CCU60_SR0.U &= ~(0x3 << TOS_BIT_LSB_IDX);   // CPU0 service T12 PM interrupt

    SRC_CCU6_CCU60_SR0.U |= 0x1 << SRE_BIT_LSB_IDX;      // SR0 enabled


    CCU60_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX;            // T12 start counting

}

// initRGBLED
void initRGBLED(void){
    P02_IOCR4.U &= ~(0x1F << PC7_BIT_LSB_IDX);      // P2.7     (RED)
    P10_IOCR4.U &= ~(0x1F << PC5_BIT_LSB_IDX);      // P10.5    (GREEN)
    P10_IOCR4.U &= ~(0x1F << PC3_BIT_LSB_IDX);      // P10.3    (BLUE)

    P02_IOCR4.U |= 0x10 << PC7_BIT_LSB_IDX;
    P10_IOCR4.U |= 0x10 << PC5_BIT_LSB_IDX;
    P10_IOCR4.U |= 0x10 << PC3_BIT_LSB_IDX;
}

// initVADC
void initVADC(void){
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1<<ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1<< LCK_BIT_LSB_IDX)) != 0);    // wait until unlocked

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX))==0);     // wait until locked

    VADC_CLC.U &= ~(1 << DISR_BIT_LSB_IDX); // enable CCY

    // Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1<<ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1<< LCK_BIT_LSB_IDX)) != 0);    // wait until unlocked

    // Modify Access to SET ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX))==0);     // wait until locked

    while((VADC_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0);

    // ARBPR(Arbitration Priority) register
    VADC_G4_ARBPR.U |= 0x3 << PRIO0_BIT_LSB_IDX;            // 0 make PRIO0 'Highest priority'
    VADC_G4_ARBPR.U &= ~(0x1 << CSM0_BIT_LSB_IDX);          // 3 make CSM0 Wait-for-start mode
    VADC_G4_ARBPR.U |= 0x1 << ASEN0_BIT_LSB_IDX;            // 24 ASEN0 make 1

    // QMR0(Queue Mode Register) register
    VADC_G4_QMR0.U &= ~(0x3 << ENGT_BIT_LSB_IDX);           // clear 해주는 과정이네
    VADC_G4_QMR0.U |= 0x1 << ENGT_BIT_LSB_IDX;              // 01 not use request gating active
    VADC_G4_QMR0.U |= 0x1 << FLUSH_BIT_LSB_IDX;             // clear ADC queue (FLUSH)

    // Arbitration Configuration
    VADC_G4_ARBCFG.U |= 0x3 << ANONC_BIT_LSB_IDX;           // ADC를 Normal Operation으로 동작

    // CLASS 정밀도를 높게 할거냐 낮게할거냐 설정
    VADC_G4_ICLASS0.U &= ~(0x7 << CMS_BIT_LSB_IDX);         // Class 0 Standard Conversion (12-bit 모두 사용) 10bit도 있고 8bit도 있다

    // VADC Group 4 Channel 7 configuration
    VADC_G4_CHCTR7.U |= 0x1 << RESPOS_BIT_LSB_IDX;          // result right-aligned
    VADC_G4_CHCTR7.U &= ~(0xF << RESREG_BIT_LSB_IDX);       // store result @ Result Register G4RES0
    VADC_G4_CHCTR7.U &= ~(0x3 << ICLSEL_BIT_LSB_IDX);       // Class 0

    VADC_G4_CHASS.U |= 0x1 << ASSCH7_BIT_LSB_IDX;
}

// Queue에 연결할 input 채널 설정
void VADC_startConversion(void){
    VADC_G4_QINR0.U |= 0x07;                                // no. of Request Channel = 7

    VADC_G4_QMR0.U |= 0x1 << TREV_BIT_LSB_IDX;              // Generate Conversion Start Trigger Event
}

unsigned int VADC_readResult(void){
    unsigned int result;

    while((VADC_G4_RES0.U & (0x1 << VF_BIT_LSB_IDX)) == 0);     // wait until read available
    result = VADC_G4_RES0.U & (0xFFF << RESULT_BIT_LSB_IDX);    // read ADC value

    return result;
}
IfxCpu_syncEvent g_cpuSyncEvent = 0;


// 이러한 interrupt 는 메인에서 호출할 수 없다 return값이 있을시 전역변수에 값 저장
__interrupt(0x0A) __vector_table(0)           //0x0A 고유 interrupt ID를 가지며, CPU0에서 처리됨
void ERU0_ISR(void){
    //button status check
    if((P02_IN.U & (0x1 << P1_BIT_LSB_IDX)) == 0){  // button pushed
        P10_OUT.B.P1 = 0x1;
        CCU60_T12PR.U = 12207 - 1;
        CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;    //load T12PR from shadow register
    }
    else{                                                   // button released
        P10_OUT.B.P1 = 0x0;
        CCU60_T12PR.U = 24414 - 1;
        CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;
    }
}
unsigned int adcResult;
__interrupt(0x0B) __vector_table(0)
void CCU60_T12_ISR(void){
    P10_OUT.U ^= 0x1 << P2_BIT_LSB_IDX;  // toggle P10.2 (LED D13 BLUE)

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
    
    //initERU();        // ERU
    initCCU60();      // TIMER
    initLED();          // LED
    //initButton();     // BUTTON
    initRGBLED();       // RGBLED
    initVADC();         // VADC



    while(1)
    {
        if( adcResult >= 3096){
            P02_OUT.U |= 0x1 << P7_BIT_LSB_IDX;
            P10_OUT.U &= ~(0x1 << P5_BIT_LSB_IDX);
            P10_OUT.U &= ~(0x1 << P3_BIT_LSB_IDX);
        }
        else if( adcResult >= 2048){
            P02_OUT.U &= ~(0x1 << P7_BIT_LSB_IDX);
            P10_OUT.U |= 0x1 << P5_BIT_LSB_IDX;
            P10_OUT.U &= ~(0x1 << P3_BIT_LSB_IDX);
        }
        else if( adcResult >= 1024){
            P02_OUT.U &= ~(0x1 << P7_BIT_LSB_IDX);
            P10_OUT.U &= ~(0x1 << P5_BIT_LSB_IDX);
            P10_OUT.U |= 0x1 << P3_BIT_LSB_IDX;
        }
        else{
            P02_OUT.U |= 0x1 << P7_BIT_LSB_IDX;
            P10_OUT.U |= 0x1 << P5_BIT_LSB_IDX;
            P10_OUT.U |= 0x1 << P3_BIT_LSB_IDX;
        }
    }
    return (1);
}
