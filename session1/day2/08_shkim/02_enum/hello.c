#include <stdio.h>

enum ADC_STATUS {EOC = 1, SOC = 0};
enum TIMER_MODE {
    TIMER_EN    = (1<<7), // 1을 7번 shift -> 7번째 비트를 1로
    TIMER_START = (1<<2)
};

int adc_status(){
    // activating ADC, reading ADC status
    // if (read_adc())
    // return EOC;
    return SOC;
}

int main()
{
    if (adc_status() == SOC){
        printf("still on conversion...\n");
    }

    // #define TMODE *((unsigned char*)0xFFFF0000)
    unsigned char TMODE; 
    TMODE  = TIMER_EN;
    TMODE |= TIMER_START;
    printf("TMODE: 0x%2X\n", TMODE); 

    return 0;
}