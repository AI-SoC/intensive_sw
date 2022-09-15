#include "Steer_Wheel.h"

void VADC_startConversion(void){
    VADC_G4_QINR0.U |= 0x07;                    // # of request channel = 7
    VADC_G4_QMR0.U |= 0x1 << TREV_BIT_LSB_IDX;  // generate conversion start trigger event
}

unsigned int VADC_readResult(void){
    unsigned int result;

    while( (VADC_G4_RES0.U & (0x1 << VF_BIT_LSB_IDX)) == 0);    // wait until read available
    result = VADC_G4_RES0.U & (0xFFF << RESULT_BIT_LSB_IDX);

    return result;
}

void initPWM_LED(void){
    P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);  // reset to zero
    P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX);  // reset to zero

    P10_IOCR0.U |= 0x11 << PC1_BIT_LSB_IDX;     // set to p10.1 GTM output (PWM Generation)
    P10_IOCR0.U |= 0x11 << PC2_BIT_LSB_IDX;     // set to p10.2 GTM output (PWM Generation)
}

void initVADC(void){
    // ======================================================================================
    unlock_clear_ENDINIT();
    VADC_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);

    unlock_set_ENDINIT();
    while((VADC_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled

    // ======================================================================================
    // ### setting registers to use VADC
    VADC_G4_ARBPR.U |= 0x3 << PRIO0_BIT_LSB_IDX;    // highest priority for Request Source 0
    VADC_G4_ARBPR.U &= ~(0x1 << CSM0_BIT_LSB_IDX);  // Wait-for-Start Mode
    VADC_G4_ARBPR.U |= 0x1 << ASEN0_BIT_LSB_IDX;    // Arbitration Source Input 0 Enable

    VADC_G4_QMR0.U &= ~(0x3 << ENGT_BIT_LSB_IDX);
    VADC_G4_QMR0.U |= 0x1 << ENGT_BIT_LSB_IDX;      // enable conversion request
    VADC_G4_QMR0.U |= 0x1 << FLUSH_BIT_LSB_IDX;     // clear ADC queue

    VADC_G4_ARBCFG.U |= 0x3 << ANONC_BIT_LSB_IDX;   // ADC normal operation

    VADC_G4_ICLASS0.U &= ~(0x7 << CMS_BIT_LSB_IDX); // Class 0 Standard Conversion (12-bit)

    // VADC Group 4 Channel 7 configuration
    VADC_G4_CHCTR7.U |= 0x1 << RESPOS_BIT_LSB_IDX;      // result right-aligned
    VADC_G4_CHCTR7.U &= ~(0xF << RESREG_BIT_LSB_IDX);   // store result @ Result Register G4RES0
    VADC_G4_CHCTR7.U &= ~(0x3 << ICLSEL_BIT_LSB_IDX);   // Class 0

    VADC_G4_CHCTR7.U |= 0x1 << ASSCH7_BIT_LSB_IDX;

}


