// hello.c
#include <stdio.h>

typedef enum ADC_STATUS{
    EOC=1, 
    SOC=0,
}adc;

typedef enum TIMER_MODE{
    TIMER_EN = (1<<7),
    TIMER_START = (1<<2),
}timer;
// 8bit = (EN/ / / / /ST/ / )
//         8  7 6 5 4 3  2 1

adc adc_status(){
    // activating ADC, reading ADC status
    // if (read_adc())
    //  return EOC;
    return SOC;
} 

int main() {
    if(adc_status() == 0){
        printf("still on conversion ...\n");
    }    

    // #define TMODE *((unsigned char*)0xFFFF0000)
    unsigned char TMODE = TIMER_EN;
    TMODE = TIMER_EN;
    TMODE |= TIMER_START;    // 해당 비트만 변경됨

    printf("TMODE: 0x%2X\n", TMODE);

    return 0;

}

