#include "Ultrasonic.h"

extern unsigned int range_right;
extern unsigned int range_left;
extern unsigned char range_valid_flag_right;
extern unsigned char range_valid_flag_left;


__interrupt(0x0A) __vector_table(0)
void ERU_ISR_right() {
    if ((P00_IN.U & (0x1 << P4_BIT_LSB_IDX)) != 0) // rising edge of echo
    {
        //                   ___________
        //    echo__________|
        //                  ^
        CCU61_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX; // start CCU61 T12 counter
    }
    else // falling edge of echo
    {
        //        ___________
        //    echo           |__________
        //                   ^
        CCU61_TCTR4.B.T12RR = 0x1; // stop CCU61 T12 counter

        // (1 / t_freq) * counter * 1000000 / 58 = centimeter
        range_right = ((CCU61_T12.B.T12CV * 1000000) / 48828) / 58;
        range_valid_flag_right = 1;

        CCU61_TCTR4.B.T12RES = 0x1; // reset CCU61 T12 counter
    }
}

__interrupt(0x0B) __vector_table(0)
void ERU_ISR_left() {
    if ((P11_IN.U & (0x1 << P10_BIT_LSB_IDX)) != 0) // rising edge of echo
    {
        //                   ___________
        //    echo__________|
        //                  ^
        CCU61_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX; // start CCU61 T12 counter
    }
    else // falling edge of echo
    {
        //        ___________
        //    echo           |__________
        //                   ^
        CCU61_TCTR4.B.T12RR = 0x1; // stop CCU61 T12 counter

        // (1 / t_freq) * counter * 1000000 / 58 = centimeter
        range_left = ((CCU61_T12.B.T12CV * 1000000) / 48828) / 58;
        range_valid_flag_left = 1;

        CCU61_TCTR4.B.T12RES = 0x1; // reset CCU61 T12 counter
    }
}

__interrupt(0x0C) __vector_table(0)
void CCU60_T12_ISR() {
    // end of 10 us Trigger
    P02_OUT.U &= ~(0x1 << P6_BIT_LSB_IDX); // right -> red
    P02_OUT.U &= ~(0x1 << P5_BIT_LSB_IDX); // left -> blue
}

// External Request selection Unit
void initERURight() {
    // ERU setting - ERS2, P00.4 selection
    // External Input Channel Register 1

    SCU_EICR1.U &= ~(0x7 << EXIS0_BIT_LSB_IDX);
    SCU_EICR1.U |= 0x2 << EXIS0_BIT_LSB_IDX; // P00.4 --> external interrupt (ERS2 - Input 2)

    SCU_EICR1.U |= 0x1 << FEN0_BIT_LSB_IDX; // falling edge
    SCU_EICR1.U |= 0x1 << REN0_BIT_LSB_IDX; // rising edge

    // External input enable
    SCU_EICR1.U |= 0x1 << EIEN0_BIT_LSB_IDX;

    // Output Gating Unit channel 0
    SCU_EICR1.U &= ~(0x7 << INP0_BIT_LSB_IDX);

    // OGU0 trigger
    // Interrupt Gating Register 0
    SCU_IGCR0.U &= ~(0x3 << IGP0_BIT_LSB_IDX);
    SCU_IGCR0.U |= 0x1 << IGP0_BIT_LSB_IDX;


    // SRC Interrupt setting
    // Service request priority number -> 0x0A (randomly)
    SRC_SCU_SCU_ERU0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.U |= 0x0A << SRPN_BIT_LSB_IDX;

    // CPU0 service is initiated
    SRC_SCU_SCU_ERU0.U &= ~(0x3 << TOS_BIT_LSB_IDX);

    // Service request is enabled (must set last)
    SRC_SCU_SCU_ERU0.U |= 1 << SRE_BIT_LSB_IDX;
}

// External Request selection Unit
void initERULeft() {
    // ERU setting - ERS6, P11.10 selection
    // External Input Channel Register 1
    SCU_EICR3.U &= ~(0x7 << EXIS0_BIT_LSB_IDX);
    SCU_EICR3.U |= 0x3 << EXIS0_BIT_LSB_IDX; // P11.10 --> external interrupt (ERS6 - Input 3)

    // Falling edge enable
    SCU_EICR3.U |= 0x1 << FEN0_BIT_LSB_IDX;
    // Rising edge enable
    SCU_EICR3.U |= 0x1 << REN0_BIT_LSB_IDX;

    // External input enable
    SCU_EICR3.U |= 0x1 << EIEN0_BIT_LSB_IDX;

    SCU_EICR3.U &= ~(0x7 << INP0_BIT_LSB_IDX);
    SCU_EICR3.U |= (0x1 << INP0_BIT_LSB_IDX);

    // OGU1 trigger
    // Interrupt Gating Register 1
    SCU_IGCR0.U &= ~(0x3 << IGP1_BIT_LSB_IDX);
    SCU_IGCR0.U |= 0x1 << IGP1_BIT_LSB_IDX;


    // SRC Interrupt setting
    // Service request priority number -> 0x0B (randomly)
    SRC_SCU_SCU_ERU1.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU1.U |= 0x0B << SRPN_BIT_LSB_IDX;

    // CPU0 service is initiated
    SRC_SCU_SCU_ERU1.U &= ~(0x3 << TOS_BIT_LSB_IDX);

    // Service request is enabled (must set last)
    SRC_SCU_SCU_ERU1.U |= 1 << SRE_BIT_LSB_IDX;
}

void initCCU60() {
    unlock_clear_ENDINIT();
    CCU60_CLC.U &= ~(1 << DISR_BIT_LSB_IDX); // enable CCU
    unlock_set_ENDINIT();

    // CCU60 T12 configurations
    while((CCU60_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0);    // wait until CCU60 module enabled

    CCU60_TCTR0.U &= ~(0x7 << T12CLK_BIT_LSB_IDX);          // f_T12 = f_CCU6 / prescaler
    CCU60_TCTR0.U |= 0x2 << T12CLK_BIT_LSB_IDX;             // f_CCU6 = 50 MHz, prescaler = 1024
    // CCU60_TCTR0.U |= 0x1 << T12PRE_BIT_LSB_IDX;          // f_T12 = 48,828 Hz

    CCU60_TCTR0.U &= ~(0x1 << CTM_BIT_LSB_IDX);             // T12 auto reset when period match (PM) occur

    // 48828, 24414, 12207
    // CCU60_T12PR.U = 48828 - 1;                           // PM interrupt freq. = f_T12 / (T12PR + 1)
    CCU60_T12PR.U = 125 - 1;                                // freq. = 12.5 Mhz --> period = 0.08 us // after 10 us, period match
    // 10 us / 0.08 us = 125
    CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;             // load T12PR from shadow register

    CCU60_TCTR2.B.T12SSC = 0x1;                             // Single Shot Control

    CCU60_T12.U = 0;                                        // clear T12 counter register

    // CCU60 T12 PM interrupt setting
    CCU60_INP.U &= ~(0x3 << INPT12_BIT_LSB_IDX);            // service request output SR0 selected
    CCU60_IEN.U |= 0x1 << ENT12PM_BIT_LSB_IDX;              // enable T12 PM interrupt

    // SRC setting for CCU60 -> ID: 0x0C
    SRC_CCU6_CCU60_SR0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_CCU6_CCU60_SR0.U |= 0x0C << SRPN_BIT_LSB_IDX;       // set priority 0x0C
    SRC_CCU6_CCU60_SR0.U &= ~(0x3 << TOS_BIT_LSB_IDX);      // CPU0 service T12 PM interrupt
    SRC_CCU6_CCU60_SR0.U |= 0x1 << SRE_BIT_LSB_IDX;         // SR0 enabled
}

void initCCU61() {
    unlock_clear_ENDINIT();
    CCU61_CLC.U &= ~(1 << DISR_BIT_LSB_IDX); // enable CCU
    unlock_set_ENDINIT();

    // CCU61 T12 configurations
    while((CCU61_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled

    CCU61_TCTR0.U &= ~(0x7 << T12CLK_BIT_LSB_IDX); // f_T12 = f_CCU6 / prescaler
    CCU61_TCTR0.U |= 0x2 << T12CLK_BIT_LSB_IDX; // f_CCU6 = 50 MHz, prescaler = 1024

    CCU61_TCTR0.U |= 0x1 << T12PRE_BIT_LSB_IDX; // f_T12 = 48,828 Hz


    CCU61_T12PR.U = 100000 - 1; // not an alarm, but chronometry
    CCU61_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX; // load T12PR from shadow register

    CCU61_T12.U = 0; // clear T12 counter register
}

void initUsonic() {
    // right
    P02_IOCR4.U &= ~(0x1F << PC6_BIT_LSB_IDX); // reset P02_IOCR4 PC6
    P00_IOCR4.U &= ~(0x1F << PC4_BIT_LSB_IDX); // reset P00_IOCR4 PC4

    P02_IOCR4.U |= 0x10 << PC6_BIT_LSB_IDX; // set P02.6 push-pull general output [TRIG]
    P00_IOCR4.U |= 0x01 << PC4_BIT_LSB_IDX; // set P00.4 general input (pull-down connected) [ECHO]

    P02_OUT.U &= ~(0x1 << P6_BIT_LSB_IDX); // initializing

    // left
    P02_IOCR4.U &= ~(0x1F << PC5_BIT_LSB_IDX); // reset P02_IOCR4 PC5
    P11_IOCR8.U &= ~(0x1F << PC10_BIT_LSB_IDX); // reset P11_IOCR8 PC10

    P02_IOCR4.U |= 0x10 << PC5_BIT_LSB_IDX; // set P02.5 push-pull general output [TRIG]
    P11_IOCR8.U |= 0x01 << PC10_BIT_LSB_IDX; // set P11.10 general input (pull-down connected) [ECHO]

    P02_OUT.U &= ~(0x1 << P5_BIT_LSB_IDX); // initializing
}

void usonicTriggerRight() {
    // start if 10us Trigger Pulse
    // GPIO P02.6 --> High
    P02_OUT.U |= 0x1 << P6_BIT_LSB_IDX;
    range_valid_flag_right = 0;
    CCU60_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX; // T12 start counting
}

void usonicTriggerLeft() {
    // start if 10us Trigger Pulse
    // GPIO P02.5 --> High
    P02_OUT.U |= 0x1 << P5_BIT_LSB_IDX;
    range_valid_flag_left = 0;
    CCU60_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX; // T12 start counting
}
