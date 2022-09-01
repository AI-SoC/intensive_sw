// hello.c
#include <stdio.h>

void mem_inspection(unsigned char* p, int N) {

    for(int i = 0; i < N; i++)
        printf("mem[%d] is 0x%02X at %p\n", i, *(p+i), p+i);
}

int main() {
    
    struct bits_8 {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    };

    union flag_16bits {
        unsigned char bytes[2];
        struct bits_8 b[2];
        unsigned short bits16;
    };

    struct ADC_CONFIG {
        unsigned char CNFG1;
        unsigned char CNFG2;
        unsigned short MODE;
    };

    struct ADC_CONFIG adc1 = { 0x01, 0x80, 0xF000 };
    printf("CNFG1 : %02X\n", adc1.CNFG1);
    printf("CNFG2 : %02X\n", adc1.CNFG2);
    printf("MODE : %04X\n", adc1.MODE);
    printf("size : %d\n", (int)sizeof(adc1));

    unsigned char* adc_p = (unsigned char*)&adc1;
    mem_inspection(adc_p, sizeof(adc1));
    *(adc_p+2) = 0x5A;
    //mem_inspection(adc_p, sizeof(adc1));

    struct bits_8 bytes;
    printf("size : %d\n", (int)sizeof(bytes));
    
    unsigned char b8 = 0xB;
    //bytes = 0x80; // try to set MSB; -> overwrite all -> error
    b8 |= 0x80;
    printf("bytes : %02X\n", b8);

    union flag_16bits b16;
    printf("size : %d\n", (int)sizeof(b16));
    b16.bits16 = 0xF005;
    printf("b16 is 0x%2X%02X\n", b16.bytes[1], b16.bytes[0]);
    b16.b[1].b6 = 0;
    printf("b16 is 0x%2X%02X\n", b16.bytes[1], b16.bytes[0]);

    return 0;
}

