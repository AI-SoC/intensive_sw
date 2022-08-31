// hello.c
#include <stdio.h>

enum ADC_STTUS { EOC = 1, SOC = 0};
enum TIMER_MODE{
    TIMER_EN    = (1<<7),
    TIMER_START = (1<<2)
};

int adc_status() {
    // activation ADC, reading ADC status
    // if (read_adc())
    //  return EOC;
    return SOC;
}

int main(){

    if(adc_status() == 0){
        printf("still conversion...\n");

    }

    // #define TMODE *((unsigned char*) 0xFFFF0000)
    unsigned char TMODE =TIMER_EN;
    TMODE = TIMER_START;
    printf("TMODE: 0x%2X\n", TMODE);


    return 0;
}

