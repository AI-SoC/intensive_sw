#include <stdio.h>

struct BITS8{
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


int main(){
    union PORT0 port0;

    port0.U = 0xFF;
    port0.B.b4 = 0; // clear bit at index 4

    printf("port0: 0x%02X\n", port0.U);

    unsigned char P0 = 0x95;

    P0 = P0 & ~(1<<4);
    printf("1. P0 : 0x%02X\n", P0);

    P0 = P0 & ~(0x80);
    printf("2. P0 : 0x%02X\n", P0);
    return 0;
}