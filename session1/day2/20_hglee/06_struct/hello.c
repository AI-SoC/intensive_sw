// hello.c
#include <stdio.h>

void mem_inspection(unsigned char* p, int N){
    for (int i = 0; i<N; i++){
        printf("mem[%d] is %02x at %p \n", i, *(p+i), p+i);
    }
}

int main() {
    struct bits_8 {
        unsigned char b0 : 1;   // 1 bit allocate
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;

    };

    struct ADC_CONFIG {
        unsigned char CNFG1;
        unsigned char CNFG2;
        unsigned short MODE;
    };

    union flag_16bits
    {
        /* data */
        unsigned char bytes[2];
        struct bits_8 b8[2];
        unsigned short bits16;
    };
    

    struct ADC_CONFIG adc1 = {
        0x01,
        0x80,
        0xF000
    };


    // printf("CNFG1   : %2X \n", adc1.CNFG1);
    // printf("CNFG2   : %2X \n", adc1.CNFG2);
    // printf("MODE    : %4X \n", adc1.MODE);

    unsigned char* adc_p = (unsigned char*)&adc1;
    // mem_inspection(adc_p, sizeof(adc1));

    *(adc_p+1) = 0x5A;
    // mem_inspection(adc_p, sizeof(adc1));
    // printf("\nCNFG1   : %2X \n", adc1.CNFG1);
    // printf("CNFG2   : %2X \n", adc1.CNFG2);
    // printf("MODE    : %4X \n", adc1.MODE);

    struct bits_8 bytes;
    // printf("struct bits_8 is with %d bytes\n", sizeof(bytes));
    
    unsigned char b8 = 0x8;
    b8 |= 0x80;

    union flag_16bits flag16;
    // printf("union flag16 is with %d bytes\n", sizeof(flag16));

    flag16.bits16 = 0xF005;
    // little endian
    printf("flag 16 is 0x%02X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    flag16.b8[1].b7 = 0;
    printf("flag 16 revised is 0x%02X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    flag16.b8[1].b3 = 1;
    printf("flag 16 revised is 0x%02X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    return 0;
}

