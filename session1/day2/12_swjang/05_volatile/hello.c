// hello.c
#include <stdio.h>

int ADC_EOC_CHECK() {
    // wait for end of conversion
    int a;
    for(int i = 0; i < 100000; i++) // HW delay emulation
        a = 10; // do sth

    return 1; 
}

int main() {
    
    // ADC_DATA = ... will be executed(updated) by HW
    volatile int ADC_DATA = 3;
    while(ADC_EOC_CHECK() == 0);  // blocking until status is matched
    int comp_ADC = ADC_DATA + 7; // compensated ADC
    printf("ADC_DATA is %d\n", comp_ADC);

    return 0;
}

