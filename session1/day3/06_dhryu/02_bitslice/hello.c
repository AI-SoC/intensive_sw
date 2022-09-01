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
    struct BITS8  B;
}; //union이 둘중하나만 가지므로 선언은 U로 비트 하나하나 바꾸는거는 BITS8으로 비트 연산!

int main(void){
    unsigned char P0 = 0x95;

    P0 = P0 & ~(1<<4);
    P0 = P0 & ~(1<<7);
    //printf("P0 : 0x%02X\n", P0);

    union PORT0 port0;
    port0.U = 0xFF;
    port0.B.b4 = 0;
    printf("port0: 0x%02X\n", port0.U);
    printf("prot0 size : %ld\n", sizeof(port0));

    return 0;
}