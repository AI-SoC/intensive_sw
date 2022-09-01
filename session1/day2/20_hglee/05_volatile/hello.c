// hello.c
#include <stdio.h>
 
int ADC_EOC_CHECK(){
    // wait for end of conversition
    // HW delay emulation
    int a = 0;
    // for (int i = 0 ; i < 10000; i++){

    // }
    return a;
}

int main() {
    // ADC_DATA = ... will be executed by HW.

    volatile int ADC_DATA = 3;

    // Blocking until status is matched
    // while (ADC_EOC_CHECK() == 0){    };

    int compensation_ADC = ADC_DATA + 7;
    printf("ADC DATA = %d \n", compensation_ADC);

    return 0;
}

