// hello.c
#include <stdio.h>

int ADC_EOC_CHECK(){
    int a;
    for(int i=0; i<10000; i++);
        a=10;
    return 1;
}

int main(){
   
    //int ADC_DATA=0;
    volatile int ADC_DATA =3;
    while(ADC_EOC_CHECK() == 0);

    int compensated_ADC = ADC_DATA + 7;
    printf("ADC_DATA is %d\n", compensated_ADC);
    
    return 0;
}