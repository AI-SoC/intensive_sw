// hello.c
#include <stdio.h>

enum ADC_STATUS{
    EOC=1, SOC=0
};
enum TIMER_MODE { 
    TIMER_EN = (1<<7),
    TIMER_START = (1<<2)
};
int abc_status()
{
    //activation ADC, READING ADC STATUS
    //if(read_Adc())
    //return EOC;
    return SOC;
}

int main() {
    if(abc_status() == SOC)
    {
        printf("still on conversion...\n");
    }

    //#define TMODE((unsigned char*)0xFFFF0000)
    unsigned char TMODE = TIMER_EN;
    TMODE |= TIMER_START; //기존 값 유지하고 해당 비트 올리기?
    printf("TMODE: 0x%2X\n", TMODE);
    return 0;
}
