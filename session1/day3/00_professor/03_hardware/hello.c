
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

union ADC_CONTROL adc_control1;
#define ADCC (*(volatile union ADC_CONTROL*)&adc_control1)

int main() {
    ADCC.U = 0x12345678;
    ADCC.B.F2 = 0xFF;
    printf("ADCC: 0x%08X\n", ADCC.U);
    return 0;
}