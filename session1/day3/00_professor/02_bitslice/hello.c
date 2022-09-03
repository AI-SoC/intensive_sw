#include <stdio.h>

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
union PORT0 {
    unsigned char U;
    struct BITS8  B;
};

#define EOC_IDX 3
#define ADC_DATA_IDX 4

int main() {
    unsigned char P0 = 0x95;

    P0 = P0 & ~(1<<4);
    printf("P0: 0x%02X\n", P0);

    P0 = P0 & ~(0x80);
    printf("P0: 0x%02X\n", P0);

    union PORT0 port0;
    port0.U = 0xFF;
    port0.B.b4 = 0; // clear bit at index 4
    printf("port0: 0x%02X\n", port0.U);   

    // expecting 1, --> more complex
    if((port0.U & (1<<EOC_IDX)) == 8) // port0[3] bit is 1
        printf("End of Conversion (comparing 1)\n") ;
    else // otherwise, port0[3] is 0
        printf("port0[3] is still 0\n");
        
    // bit compare with 0, otherwise we expect value, more simple 
    if((port0.U & (1<<EOC_IDX)) == 0) // port0[3] bit is still 0
        printf("port0[3] is still 0\n");
    else // otherwise, port0[3] is 1
        printf("End of Conversion (comparing 0)\n") ;

    // check memory bus idle or flag check.. 
    // (via memory mapped-IO based hardware access)
    while ((port0.U & (1<<EOC_IDX)) == 0); // port0[3] is still 0, on ADC conversion

    // port0[3] is 1, so, while(false) --> stop loop
    // so, go through here,
    printf("End of Conversion (while self check technique)\n") ;

    // multi-bit slice update
    port0.U &= ~(0xF << ADC_DATA_IDX);
    port0.U |=  (0x3 << ADC_DATA_IDX);
    printf("port0: 0x%02X\n", port0.U);   

    return 0;
}