// hello.c
#include <stdio.h>

void mem_inspection(unsigned char* p, int N){
    for(int i = 0;i<N;i++){
        printf("mem[%d] is 0x%02X at %p\n", i, *(p+i), p+i);
    }
}

int main() {
    struct bits_8{
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    };
    //구조체를 쓰는이유? 메모리를 아주 효율적으로 사용 가능
    struct ADC_CONFIG {
        unsigned char CNFG1;
        unsigned char CNFG2;
        unsigned short MODE;
    };
    union flag_16bits {
        unsigned char bytes[2];
        struct bits_8 b[2];
        unsigned short bits16;
    };

    struct ADC_CONFIG adc1 = {0x01, 0x80, 0xF000};
    printf("CNFG1 : 0x%02X\n", adc1.CNFG1);
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2);
    printf("MODE : 0x%04X\n", adc1.MODE);
    
    unsigned char* adc_p = (unsigned char*)&adc1;
    mem_inspection(adc_p, sizeof(adc1));

    *(adc_p+1) = 0x5A; // write CNFG2
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2);

    struct bits_8 bytes;
    printf("struct bits_8 is allocated with %ld bytes\n", sizeof(bytes));
    //character 8개 사용한 struct인데 sizeof해보니 1바이트! b0~b7이 각각 하나의 비트만 차지

    unsigned char b8 = 0xB;
    // b8 = 0x80; //try to set MSB --> overwrite all --> error
    b8 |= 0x80;
    printf("bytes: %02X\n", b8);

    union flag_16bits flags16;
    printf("flag_16bits is with %d bytes\n", sizeof(flags16));
    //2바이트 차지한다!! 왜? 
    flags16.bits16 = 0xF005;
    printf("flag16 is 0x%02X%02X\n", flags16.bytes[1], flags16.bytes[0]);

    flags16.b[1].b7 = 0;
    printf("flag16 is 0x%02X%02X\n", flags16.bytes[1], flags16.bytes[0]);
    
    flags16.b[0].b3 = 1;
    printf("flag16 is 0x%02X%02X\n", flags16.bytes[1], flags16.bytes[0]);
    

    return 0;
}

