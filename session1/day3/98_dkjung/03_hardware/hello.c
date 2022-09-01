#include <stdio.h>
struct REG_BITS {
    unsigned char F0 : 8;
    unsigned char F1 : 8;
    unsigned char F2 : 8;
    unsigned char F3 : 8;
};
union ADC_CONTROL{
    unsigned int    U;
    struct REG_BITS B;
};

#define HW_EMULATION 1
#ifdef HW_EMULATION
    union ADC_CONTROL adc_control1;
    #define ADCC (*(volatile union ADC_CONTROL*)&adc_control1)
#else
    #define ADCC (*(volatile union ADC_CONTROL*)0xFFB00000)
#endif

int main ()
{
    ADCC.U = 0x12345678;
    ADCC.B.F2 = 0xFF;
    printf("port0 : 0x%08X\n",ADCC.U);

    ADCC.U = 0x12345678;
    ADCC.U &= 0xFF00FFFF;
    ADCC.U |= 0x005A0000;
    printf("port0 : 0x%08X\n",ADCC.U);

    return 0;
}