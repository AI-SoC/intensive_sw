#include "Traffic_Light.h"

void initRGBLED(void) {
    // reset port IOCR register
    P02_IOCR4.U &= ~(0x1F << PC7_BIT_LSB_IDX); // P2.7
    P10_IOCR0.U &= ~(0x1F << PC3_BIT_LSB_IDX); // P10.3
    P10_IOCR4.U &= ~(0x1F << PC5_BIT_LSB_IDX); // P10.5

    // set port as general purpose output push-pull)
    P02_IOCR4.U |= 0x10 << PC7_BIT_LSB_IDX; // P2.7
    P10_IOCR0.U |= 0x10 << PC3_BIT_LSB_IDX; // P10.3
    P10_IOCR4.U |= 0x10 << PC5_BIT_LSB_IDX; // P10.5
}
