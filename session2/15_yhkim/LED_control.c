#include "LED_control.h"

void init_LED(void);
void init_LED_PWM(void);


void init_LED(void)
{
    //P10_IOCR0.U &= ~(0x1F << PC1_BIT_LSB_IDX);      //reset P10_IOCR0 PC1
    //P10_IOCR0.U &= ~(0x1F << PC2_BIT_LSB_IDX);      //reset P10_IOCR0 PC2

    //P10_IOCR0.U |= 0x10 << PC1_BIT_LSB_IDX;         // set P10.1 push-pull general output
    //P10_IOCR0.U |= 0x10 << PC2_BIT_LSB_IDX;         // set P10.2 push-pull general output

    P10_IOCR0.B.PC1 = 0x10; // General Purpose Output
    //P10_IOCR0.B.PC1 = 0x11; // 이건 PWM신호로 쏠때,,, P10.1에 GTM Output을 내보낼때!!
    P10_IOCR0.B.PC2 = 0x10;
}


void init_LED_PWM(void)
{
    P10_IOCR0.B.PC1 = 0x11; // 이건 PWM신호로 쏠때,,, P10.1에 GTM Output을 내보낼때!!
    P10_IOCR0.B.PC2 = 0x10;
}



