// hello.c
#include <stdio.h>

void mem_inspection(unsigned char* p, int N){
    for(int i =0; i<N; i++)
        printf("mem[%d] is 0x%02X at %p \n", i, *(p+i), p+i);
}
void main(){
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

    struct ADC_CONFIG adc1 = {0x01, 0x80, 0xF000};
    printf("CNFG1 : 0x%02X\n", adc1.CNFG1);
    printf("CNFG2 : 0x%02X\n", adc1.CNFG1);
    printf("MODE : 0x%04X\n", adc1.MODE);

    unsigned char* adc_p = (unsigned char*)&adc1;
    mem_inspection(adc_p, sizeof(adc1));

    *(adc_p+1) = 0x5A;
    printf("CNFG2 : 0x%02X\n", adc1.CNFG2);

    printf("struct bits_8 is aloocated with %d bytes\n", sizeof(bits_8));


}