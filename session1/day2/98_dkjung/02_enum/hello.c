// hello.c
#include <stdio.h>
enum ADC_STATUS { EOC=1, SOC=0 };
enum TIMER_MODE {
    TIMER_EN = (1<<7),
    TIMER_START = (1<<2)
};
int adc_status() {
    // activating ADC, reading ADC status
    // if( rad_adc())
    //  return EOC
    return SOC;
}

int main() {
    if(adc_status() == 0){
        printf("still on conversion...\n");
    }

    // #define TMODE *((unsigned char*)0xFFFF0000)
    unsigned char TMODE; 
    TMODE = TIMER_EN;
    TMODE |= TIMER_START;
    printf("TMODE: %2X\n",TMODE);

    return 0;
}

