#include "RGB_control.h"

void initRGBLED(void);

void initRGBLED(void)
{
    //reset Port IOCR register
    // set Port as general purpose output (push-pull)
    P02_IOCR4.B.PC7 = 0x10;
    P10_IOCR4.B.PC5 = 0x10;
    P10_IOCR0.B.PC3 = 0x10;
}


