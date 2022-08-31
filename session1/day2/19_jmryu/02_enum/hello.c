// hello.c
#include <stdio.h>

enum ADC_STATUS { EOC = 1, SOC = 0 };   // end of conversion, still on conversion
enum TIMER_MODE {
    TIMER_EN = (1 << 7),    // 1을 왼쪽으로 7번 SHIFT = 0X80
    TIMER_START = (1 << 2)  // 1을 왼쪽으로 2번 SHIFT = 0X4
};

int adc_status(){
    // activating ADC, reading ADC status
    // if (read_adc())
    // return EOC;
    return SOC;
}

int main() {
    
    if (adc_status() == 0){
        printf("still conversion...\n");
    }

    // #define TMODE *((unsigned char*)0xFFFF0000)
    unsigned char TMODE;
    TMODE = TIMER_EN;
    TMODE |= TIMER_START;
    printf("TMODE : 0X%2X\n", TMODE);

    return 0;
}

 