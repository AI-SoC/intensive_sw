// hello.c
#include <stdio.h>

void mem_inspection(unsigned char* p, int n){
    for (int i = 0; i < n; i++)
        printf("mem[%d] is 0x%02X at %p\n", i, p[i], p + i);
}

int main()
{
    struct bits_8{
        unsigned char b0 : 1; // 1 bit씩 할당
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    }; // 1 byte

    struct ADC_CONFIG{
        unsigned char CNFG1;
        unsigned char CNFG2;
        unsigned short MODE;
    };

    // union의 속성은 모두 크기가 같아야 함
    union flag_16bits{
        unsigned char bytes[2];
        struct bits_8 b[2];
        unsigned short bits16; 
    };

    struct ADC_CONFIG adc1 = {0x01, 0x80, 0xF000};
    printf("CNFG1: 0x%02X\n", adc1.CNFG1);
    printf("CNFG2: 0x%02X\n", adc1.CNFG2);
    printf("MODE: 0x%04X\n", adc1.MODE);

    unsigned char* adc_p = (unsigned char*)&adc1;
    mem_inspection(adc_p, sizeof(adc1));

    *(adc_p + 1) = 0x5A; // write CNFG2
    printf("CNFG2: 0x%02X\n", adc1.CNFG2);
    //mem_inspection(adc_p, sizeof(adc1));

    struct bits_8 bytes;
    printf("struct bits_8 is allocated with %ld bytes\n", sizeof(bytes));

    unsigned char b8 = 0xB;
    //bytes = 0x80; // try to set MSB -> overwrite (error)
    b8 |= 0x80;
    printf("bytes: %02X\n", b8);

    union flag_16bits flag16;
    printf("union flag_16 is allocated with %ld bytes\n", sizeof(flag16));    

    flag16.bits16 = 0xF005;
    printf("flags16 is 0x%02X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    flag16.b[1].b7 = 0;
    printf("flags16 is 0x%02X%02X\n", flag16.bytes[1], flag16.bytes[0]);
    flag16.b[0].b7 = 1;
    printf("flags16 is 0x%02X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    return 0;
}

