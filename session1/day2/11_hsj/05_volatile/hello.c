// hello.c
#include <stdio.h>

int ADC_EOC_CHECK() {
    int a;
    for(int i=0; i<100000; i++)
    {
        a=10;
    }
    return 1;
}

int main() {
    //ADC_DATA = ....will be executed by HW
    volatile int ADC_DATA = 3; //volatile 스스로 바뀔수 있음(휘발성)
    //blocking until status is matched
    while(ADC_EOC_CHECK() ==0);

    int compensated_ADC = ADC_DATA +7;
    printf("ADC_DATA is %d\n", compensated_ADC);
}

