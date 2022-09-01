#include <stdio.h>

int main(){
    unsigned char p0 = 0x95;
    struct BITS8 {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    };

    union PORT0{
        unsigned char U;
        struct BITS8 B;
    };

    union PORT0 port0;
    port0.U = 0xFF;
    port0.B.b4 = 0;
    printf("port0: 0x%02X\n",port0.U);

    p0 = p0 & ~(1<<4);
    printf("p0: 0x%02X\n", p0);

    p0 =p0 & ~(0x80);
    printf("p0: 0x%02X\n", p0);


    return 0;
}