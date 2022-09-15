#include "Pedal.h"

extern unsigned int range_right;
extern unsigned int range_left;

__interrupt(0x0E) __vector_table(0)
void ERU_ISR_D2(void) // BRAKE INTERRUPT
{

    // Brake (button D3) pushed
    unsigned char a, b, c;

    a = P02_IN.U & (0x1 << P0_BIT_LSB_IDX);
    for(unsigned int i = 0; i < 100; i++);

    b = P02_IN.U & (0x1 << P0_BIT_LSB_IDX);
    for(unsigned int i = 0; i < 100; i++);

    c = P02_IN.U & (0x1 << P0_BIT_LSB_IDX);
    for(unsigned int i = 0; i < 100; i++);

    if( a == 0 && b == 0 && c == 0 ) {

        // P00.2 (PIN29)
        P00_OUT.U &= ~(0x1 << P2_BIT_LSB_IDX);
        for(int i = 0; i < 100000; i++);
        P00_OUT.U |= 0x1 << P2_BIT_LSB_IDX;

        if((P10_OUT.U & (0x1 << P5_BIT_LSB_IDX)) == (0x1 << P5_BIT_LSB_IDX)) { // if GREEN light is ON

            if(range_right >= 40 && range_left >= 40) {
            // Leading Vehicle Departure Warning

                GTM_TOM0_CH11_SR0.B.SR0 = 6250000 / 783;
                GTM_TOM0_CH11_SR1.B.SR1 = 3125000 / 783;
                for(int i = 0; i < 2000000; i++);
                GTM_TOM0_CH11_SR0.B.SR0 = 0;
                GTM_TOM0_CH11_SR1.B.SR1 = 0;
                for(int i = 0; i < 2000000; i++);

                GTM_TOM0_CH11_SR0.B.SR0 = 6250000 / 1046;
                GTM_TOM0_CH11_SR1.B.SR1 = 3125000 / 1046;
                for(int i = 0; i < 2000000; i++);
                GTM_TOM0_CH11_SR0.B.SR0 = 0;
                GTM_TOM0_CH11_SR1.B.SR1 = 0;
                for(int i = 0; i < 2000000; i++);
            }
        }
    }
}

void initConnect(void) {
    P00_IOCR0.U &= ~(0x1F << PC3_BIT_LSB_IDX);
    P00_IOCR0.U |= (0x10 << PC3_BIT_LSB_IDX);

    P00_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX);
    P00_IOCR0.U |= (0x10 << PC2_BIT_LSB_IDX);

    P00_OUT.U |= 0x1 << P3_BIT_LSB_IDX;
    P00_OUT.U |= 0x1 << P2_BIT_LSB_IDX;
}

void initButton(void) {
    P02_IOCR0.U &= ~(0X1F << PC1_BIT_LSB_IDX);
    P02_IOCR0.U &= ~(0X1F << PC0_BIT_LSB_IDX);

    P02_IOCR0.U |= 0x02 << PC1_BIT_LSB_IDX;
    P02_IOCR0.U |= 0x02 << PC0_BIT_LSB_IDX;
}

void initERUD2(void)
{
    // ERU setting for switch D2
    SCU_EICR1.U &= ~(0x7 << EXIS1_BIT_LSB_IDX);
    SCU_EICR1.U |= (0x2 << EXIS1_BIT_LSB_IDX);

    SCU_EICR1.U |= 0x1   << FEN1_BIT_LSB_IDX;
    SCU_EICR1.U |= 0x1   << EIEN1_BIT_LSB_IDX;

    SCU_EICR1.U &= ~(0x7 << INP1_BIT_LSB_IDX);
    SCU_EICR1.U |= (0x3 << INP1_BIT_LSB_IDX); // setting output channel as OGU3

    SCU_IGCR1.U &= ~(0x3 << IGP1_BIT_LSB_IDX);
    SCU_IGCR1.U |= 0x1   << IGP1_BIT_LSB_IDX;

    // SRC Interrupt setting
    SRC_SCU_SCU_ERU3.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU3.U |= 0x0E   << SRPN_BIT_LSB_IDX;

    SRC_SCU_SCU_ERU3.U &= ~(0x3  << TOS_BIT_LSB_IDX);

    SRC_SCU_SCU_ERU3.U |= 1      << SRE_BIT_LSB_IDX;
}

void initGTM(void)
{
    unlock_clear_ENDINIT();
    GTM_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);    // enable GTM
    unlock_set_ENDINIT();

    while((GTM_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until GTM module enabled

    // GTM clock configuration
    GTM_CMU_FXCLK_CTRL.U &= ~(0xF << FXCLK_SEL_BIT_LSB_IDX);  // input clock of CMU_FXCLK --> CMU_GCLK_EN
    GTM_CMU_CLK_EN.U |= 0x2 << EN_FXCLK_BIT_LSB_IDX;        // enable all CMU_FXCLK

    // set TGC0 to enable GTM TOM0 channel 1
    GTM_TOM0_TGC0_GLB_CTRL.U |= 0x2 << UPEN_CTRL1_BIT_LSB_IDX;  // TOM channel 1 enable
    GTM_TOM0_TGC0_ENDIS_CTRL.U |= 0x2 << ENDIS_CTRL1_BIT_LSB_IDX;   // enable channel 1 on update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL.U |= 0x2 << OUTEN_CTRL1_BIT_LSB_IDX;   // enable channel 1 output on update trigger


    // set TGC0 to enable GTM TOM0 channel 2, 3, 15
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL2 |= 0x2;  // TOM0 channel 2 enable
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL3 |= 0x2;  // TOM0 channel 3 enable
    GTM_TOM0_TGC1_GLB_CTRL.B.UPEN_CTRL7 |= 0x2;  // TOM0 channel 15 enable

    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL2 |= 0x2;   // enable channel 2 on update trigger
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL3 |= 0x2;   // enable channel 3 on update trigger
    GTM_TOM0_TGC1_ENDIS_CTRL.B.ENDIS_CTRL7 |= 0x2;   // enable channel 15 on update trigger

    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL2 |= 0x2;   // enable channel 2 output on update trigger
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL3 |= 0x2;   // enable channel 3 output on update trigger
    GTM_TOM0_TGC1_OUTEN_CTRL.B.OUTEN_CTRL7 |= 0x2;   // enable channel 15 output on update trigger


    // TOM 0_1
    GTM_TOM0_CH1_CTRL.U |= 0x1 << SL_BIT_LSB_IDX;                   // high signal level for duty cycle

    GTM_TOM0_CH1_CTRL.U &= ~(0x7 << CLK_SRC_SR_BIT_LSB_IDX);
    GTM_TOM0_CH1_CTRL.U |= 0x1 << CLK_SRC_SR_BIT_LSB_IDX;           // clock source --> CMU_FXCLK(1) = 6250 kHz

    GTM_TOM0_CH1_SR0.U = 12500 - 1;                                 // PWM freq. = 6250 kHz / 12500 = 250 kHz
    GTM_TOM0_CH1_SR1.U = 1250 - 1;                                  // duty cycle = 6250 / 12500 = 50 %

    // ULTRASONICULTRASONICULTRASONICULTRASONICULTRASONIC
    GTM_TOM0_CH1_CTRL.U &= ~(0x1 << OSM_BIT_LSB_IDX);               // continuous mode enable
    GTM_TOM0_CH1_CTRL.U &= ~(0x1 << TRIOUT_BIT_LSB_IDX);            // TRIG[x] = TRIG[x-1]

    // TOM 0_2
    GTM_TOM0_CH2_CTRL.U |= 0x1 << SL_BIT_LSB_IDX;                   // high signal level for duty cycle
    GTM_TOM0_CH2_CTRL.U &= ~(0x7 << CLK_SRC_SR_BIT_LSB_IDX);
    GTM_TOM0_CH2_CTRL.U |= 0x1 << CLK_SRC_SR_BIT_LSB_IDX;           // clock source --> CMU_FXCLK(1) = 6250 kHz

    GTM_TOM0_CH2_SR0.U = 12500 - 1;                                 // PWM freq. = 6250 kHz / 12500 = 250 kHz
    //GTM_TOM0_CH2_SR1.U = 12500 - 1;                               // duty cycle = 6250 / 12500 = 50 %

    // ULTRASONICULTRASONICULTRASONICULTRASONICULTRASONIC
    GTM_TOM0_CH2_CTRL.U &= ~(0x1 << OSM_BIT_LSB_IDX);               // continuous mode enable
    GTM_TOM0_CH2_CTRL.U &= ~(0x1 << TRIOUT_BIT_LSB_IDX);            // TRIG[x] = TRIG[x-1]

    // TOM 0_3
    GTM_TOM0_CH3_CTRL.U |= 0x1 << SL_BIT_LSB_IDX;                   // high signal level for duty cycle
    GTM_TOM0_CH3_CTRL.U &= ~(0x7 << CLK_SRC_SR_BIT_LSB_IDX);
    GTM_TOM0_CH3_CTRL.U |= 0x1 << CLK_SRC_SR_BIT_LSB_IDX;           // clock source --> CMU_FXCLK(1) = 6250 kHz

    GTM_TOM0_CH3_SR0.U = 12500 - 1;                                 // PWM freq. = 6250 kHz / 12500 = 250 kHz
    //GTM_TOM0_CH3_SR1.U = 125 - 1;                                 // duty cycle = 6250 / 12500 = 50 %

    // TOM 0_15
    GTM_TOM0_CH15_CTRL.B.SL |= 0x1;                                 // high signal level for duty cycle
    GTM_TOM0_CH15_CTRL.B.CLK_SRC_SR |= 0x1;                         // clock source --> CMU_FXCLK(1) = 6250 kHz

    GTM_TOM0_CH15_SR0.U = 12500 - 1;                                // PWM freq. = 6250 kHz / 12500 = 250 kHz
    //GTM_TOM0_CH15_SR1.U = 125 - 1;                                // duty cycle = 6250 / 12500 = 50 %


    // TOUT pin selection
    GTM_TOUTSEL6.U &= ~(0x3 << SEL7_BIT_LSB_IDX);                   // TOUT103  --> TOM0 channel 1
    GTM_TOUTSEL0.U &= ~(0x3 << SEL7_BIT_LSB_IDX);                   // TOUT7    --> TOM0 channel 15
    GTM_TOUTSEL6.U &= ~(0x3 << SEL8_BIT_LSB_IDX);                   // GTM output --> TOUT104 --> TOM0_2
    GTM_TOUTSEL6.U &= ~(0x3 << SEL9_BIT_LSB_IDX);                   // TOUT105  --> TOM0 channel 3
    GTM_TOUTSEL6.U &= ~(0x3 << SEL11_BIT_LSB_IDX);                  // TOUT103  --> TOM0 channel 2


    // set GTM TOM0 channel 11 - Buzzer
    GTM_TOM0_TGC1_GLB_CTRL.B.UPEN_CTRL3     |= 0x2;                   // TOM0 channel 11 enable
    GTM_TOM0_TGC1_ENDIS_CTRL.B.ENDIS_CTRL3  |= 0x2;                   // enable channel 11 on update trigger
    GTM_TOM0_TGC1_OUTEN_CTRL.B.OUTEN_CTRL3  |= 0x2;                   // enable channel 11 output on update trigger


    // TOM 0_11
    GTM_TOM0_CH11_CTRL.B.SL = 0x1;                                  // high signal level for duty cycle
    GTM_TOM0_CH11_CTRL.B.CLK_SRC_SR = 0x1;                          // clock source --> CMU_FXCLK(1) = 6250 kHz
    //GTM_TOM0_CH11_SR0.B.SR0 = 12500 - 1;                            // PWM freq. = 6250 kHz / 12500 = 500 Hz
    //GTM_TOM0_CH11_SR1.B.SR1 = 6250 - 1;                             // duty cycle = 6250 / 12500 = 50 %

    // TOUT pin selection
    GTM_TOUTSEL0.B.SEL3 = 0x0;                                      // TOUT3  --> TOM0 channel 11
}

void initBuzzer(void)
{
    P02_IOCR0.B.PC3 = 0x11;
}
