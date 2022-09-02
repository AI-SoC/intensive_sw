#include <stdio.h>
struct REG_BITS {
    unsigned int F0 : 8;
    unsigned int F1 : 8;
    unsigned int F2 : 8;
    unsigned int F3 : 8;
};
union ADC_CONTROL {
    unsigned int U;
    struct REG_BITS B;
};


#define HW_EMULATION

#ifdef HW_EMULATION 1
    union ADC_CONTROL adc_control1;
    #define ADCC (*(volatile union ADC_CONTROL*)&adc_control1)

#else
    #define ADCC (*(volatile union ADC_CONTROL*)&0xFFB00000)
#endif

int main() {
    ADCC.U = 0x12345678;
    ADCC.B.F2 = 0x5A;
    printf("ADCC : 0x%08X\n", ADCC.U);

    //ADCC.U = 0x12345678 & 0xFF00FFFF;
    ADCC.U = 0x12345678;
    ADCC.U &= 0xFF00FFFF; // masking
    ADCC.U |= 0x005A0000; // bit set
    //ADCC.B.F2 = 0xFF;
    printf("ADCC : 0x%08X\n", ADCC.U);

    return 0;
}