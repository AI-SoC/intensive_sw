// hello.c
#include <stdio.h>
 
int ADC_EOC_CHECK(){
    //wiat for end of conversion
    int a; 
    for(int i=0; i<10000; i++)//hardware delay emulation
        a=10; //do something

    return 1; //end of conversion
}
int main() {
    //ADC_DATA = .... will be executed by hardware
    volatile int ADC_DATA=3;
    while(ADC_EOC_CHECK()==0); //blocking until status is matched

    int compensated_ADC = ADC_DATA + 7;
    printf("ADC_DATA is %d\n", compensated_ADC);

    return 0;
}

