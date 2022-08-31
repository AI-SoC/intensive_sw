// hello.c
#include <stdio.h>
 
enum ADC_STATUS
{
    EOC = 0,    // End Of Conversion
    SOC = 1,    // Still On Conversion
};

enum TIMER_MODE
{
    TIMER_EN = (1<<7),
    TIMER_START = (1<<2),
};

int adc_status()
{
    // activating ADC, reading ADC status
    return EOC;
}


int main() {
    if(adc_status() == 1)
    {
        printf("still on conversion...\n");
    }
    else{
        printf("EOC\n");
    }
    
    enum TIMER_MODE TMODE = TIMER_EN;
    printf("TMODE: 0x%2X\n", TMODE); 
    return 0;
}

