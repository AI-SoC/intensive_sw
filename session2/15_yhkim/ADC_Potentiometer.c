#include "ADC_Potentiometer.h"
#include "Cpu0_Main.h"

// 가변저항
void initVADC(void)
{
    //Password Access to unlock SCU_WDTSCON0
   SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
   while ((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0 );

   // Modify Access to clear ENDINIT
   SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
   while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);    // wait until locked

   VADC_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);    // enable VADC

   //Password Access to unlock SCU_WDTSCON0
   SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
   while ((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0 );

   // Modify Access to clear ENDINIT
   SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
   while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);    // wait until locked

   // CCU60 T12 configurations (DISR이 바뀌면 DISS가 따라서 바뀜(데이터 시트 참고), 그거 바뀌는거까지 확인하면서 기다림)
   while((VADC_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled.

   VADC_G4_ARBPR.B.PRIO0 = 0x3;
   VADC_G4_ARBPR.B.CSM0 = 0;
   VADC_G4_ARBPR.B.ASEN0 = 1;

   VADC_G4_QMR0.B.ENGT = 0x1;   // enable conversion request
   VADC_G4_QMR0.B.FLUSH = 0x1;  // clear ADC queue

   VADC_G4_ARBCFG.B.ANONC = 0x3;    // ADC normal operation

   VADC_G4_ICLASS0.B.CMS = 0;       // Class 0 standard Conversion (12bit)

   // VADC Group 4 channel 7 configuration.
   VADC_G4_CHCTR7.B.RESPOS = 1;     // result right-aligned.
   VADC_G4_CHCTR7.B.RESREG = 0x0;   // store result @ Result Register G4RES0

   VADC_G4_CHASS.B.ASSCH7 = 1;
}

void VADC_startConversion(void)
{
    VADC_G4_QINR0.U |= 0x07;    // no. of Request Channel = 7
    VADC_G4_QMR0.B.TREV = 1;    // Generate Conversion Start Trigger Event
}

unsigned int VADC_readResult(void)
{
    unsigned int result;

    while (VADC_G4_RES0.B.VF == 0); // 해당 레지스터에 새로운 값이 있는지 체크
    result = VADC_G4_RES0.B.RESULT; // 값 읽기

    return result;

}



