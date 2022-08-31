// hello.c
#include <stdio.h>

void mem_inspection(unsigned char* p, int N){
    for (int i = 0; i < N; i++){
        printf("mem[%d] is 0x%02X at %p\n", i, *(p + i), p + i);
    }
}

void main() {

    // 메모리를 딱 맞게 쓰기 위함
    // 구조체에서는 1 bit까지 줄일 수 있다
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
    
    
    struct ADC_CONFIG {
        unsigned char CNFG1;    // 1 byte
        unsigned char CNFG2;    // 1 byte   
        unsigned short NODE;    // 2 byte
    };

    union flag_16bits{  // 얘가 왜 2 byte라고 => 제일 큰 애
        unsigned char bytes[2]; 
        struct bits_8 b[2];
        unsigned short bits16;  
    };
     
    struct ADC_CONFIG adc1 = { 0x01, 0x80, 0xF000 };
    printf("CNFG1 : 0x%02X\n", adc1.CNFG1);
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2);
    printf("NODE : 0x%02X\n", adc1.NODE);

    unsigned char* adc_p = (unsigned char*)&adc1;   // 1 byte만 가리키게끔
    mem_inspection(adc_p, sizeof(adc1));        // sizeof(adc1) = 4 bytes

    *(adc_p+1) = 0x5A;  // write CNFG2;
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2);
    //mem_inspection(adc_p, sizeof(adc1));

    struct bits_8 bytes;
    printf("struct bits_8 is allocated with %ld bytes\n", sizeof(bytes));

    unsigned char b8 = 0xB;
    //bytes = 0x80;   // try to set MSB; -- overwrtie all --> error
    b8 |= 0x80;  // 최상위 비트만 1로 업데이트
    printf("bytes : %02X\n", b8);

    union flag_16bits flag16;
    printf("struct flag16 is allocated with %ld bytes\n", sizeof(flag16));  // 2 bytes

    flag16.bits16 = 0xF005;
    printf("flag16 is 0x%2X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    flag16.b[1].b7 = 0;
    printf("flag16 is 0x%2X%02X\n", flag16.bytes[1], flag16.bytes[0]);

    flag16.b[0].b3 = 1;
    printf("flag16 is 0x%2X%02X\n", flag16.bytes[1], flag16.bytes[0]);

}

 