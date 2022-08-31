// hello.c
#include <stdio.h>
 
void mem_inspection(unsigned char * p , int N)
{

for(int i=0; i<N; i++){
    printf("mem[%d] is 0x%02X at %p\n", i , *(p+i), p+i);
}

}

void main() {

    struct bits_8{
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
    };


    struct ADC_CONFIG {
        unsigned char CNFG1;
        unsigned char CNFG2;
        unsigned short MODE;
    };

    union flag_16bits{

        unsigned char bytes[2];
        struct bits_8 b[2];
        unsigned short bits16;

    
    };

    struct ADC_CONFIG adc1={0x01, 0x80, 0xF000};
    printf("CNFG1: 0x%02X\n",adc1.CNFG1);
    printf("CNFG2: 0x%02X\n",adc1.CNFG2);
    printf("MODE: 0x%04X\n",adc1.MODE);

    unsigned char* adc_p=(unsigned char*) &adc1;
    mem_inspection(adc_p,sizeof(adc1));

    *(adc_p+2)=0x5A;
    printf("MODE: 0x%04X\n",adc1.MODE);

    struct bits_8 bit8;
    printf("bits_8 is allocated with %d bytes\n",sizeof(bit8));


    unsigned char b8=0xB;
    // bytes=0x80; // try to set MSB;  -- overwrite all ->error
    b8|=0x80;

    printf("bytes : 0x%02x\n",b8);

    union flag_16bits size_test;
    printf("flag_16bits is allocated with %d bytes\n",sizeof(size_test));  //4bytes를 예상했는데 2bytes가 나오네...
    // why???  이게 union을 쓰는 이유다.

    size_test.bits16=0xF005; // 2bytes
    printf("flag16 is 0x%02X%02X\n", size_test.bytes[1],size_test.bytes[0]); 

    size_test.b[1].b7=0;
    printf("flag16 is 0x%02X%02X\n", size_test.bytes[1],size_test.bytes[0]);

    size_test.b[0].b3=1;
    printf("flag16 is 0x%02X%02X\n", size_test.bytes[1],size_test.bytes[0]);

}