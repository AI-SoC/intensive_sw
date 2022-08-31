// hello.c
#include <stdio.h>


void main(){
    struct ADC_CONFIG {
        unsigned char CNFG1;
        unsigned char CNFG2;
        unsigned short MODE;
    };

    struct ADC_CONFIG adc1 = {0x01, 0x80, 0xF000};
    printf("CNFG1 : 0x%02X\n", adc1.CNFG1);
    printf("CNFG2 : 0x%02X\n", adc1.CNFG1);
    printf("MODE : 0x%04X\n", adc1.MODE);
}