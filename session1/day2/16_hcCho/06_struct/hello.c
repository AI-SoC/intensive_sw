// hello.c
#include <stdio.h>

void mem_insepction(unsigned char *p, int N){
    for(int i = 0 ; i < N; i++) 
        printf("mem[%d] is 0x%02X at %p\n", i, *(p + i), p + i) ;
}

void main() {

    struct BITS_8{
        unsigned char  b0 : 1 ;
        unsigned char  b1 : 1 ;
        unsigned char  b2 : 1 ;
        unsigned char  b3 : 1 ;
        unsigned char  b4 : 1 ;
        unsigned char  b5 : 1 ;
        unsigned char  b6 : 1 ;
        unsigned char  b7 : 1 ; 
    }; 
    
    struct ADC_CONFIG { 
        unsigned char  CNFG1 ; 
        unsigned char  CNFG2 ; 
        unsigned short MODE  ; 
    }; 

    union FLAG_16BITS{
        unsigned char bytes[3] ; 
        struct BITS_8 bits8[2] ; 
        unsigned short bits16 ; 
    };

    struct ADC_CONFIG adc1 = {0x01, 0x80, 0xF000} ; 
    printf("CNFG1 : 0x%02X\n", adc1.CNFG1) ; 
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2) ; 
    printf("MODE  : 0x%04X\n", adc1.MODE) ; 


    unsigned char* adc_p = (unsigned char*)&adc1 ; 
    mem_insepction(adc_p, sizeof(adc1)) ; 

    *(adc_p + 1) = 0x5A ; 
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2) ; 
    
    struct BITS_8 bits_8 ; 

    printf("size of bits_8 struct : %lu\n", sizeof(bits_8)) ; 

    unsigned char b8 = 0x0B ;
    b8 |= 0x80 ; 

    printf("b8 : %02X\n", b8) ; 

    union FLAG_16BITS flag16 ; 

    flag16.bits16 = 0xF005 ; 
    flag16.bits8[0].b7 = 1 ; 
    printf("size of FLAG_16BITS struct : %lu\n", sizeof(flag16)) ; 

    printf("flag16 is 0x%02X %02X\n", flag16.bytes[1], flag16.bytes[0]) ; 

}

