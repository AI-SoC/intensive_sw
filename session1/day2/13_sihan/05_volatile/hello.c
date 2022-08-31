// hello.c
#include <stdio.h>
 
int ADC_EOC_CHECK() {
    int a=10;
    for(int i=0; i<100000; i++) // hardware delay emulation
        a=10; //do something.
    return 1; //endo of conversion
}

int main(void) {
    
    // ADC_DATA = ..... will be excuted by Hardware.
    volatile int ADC_DATA=3;
    //blocking untill status is matched
    while(ADC_EOC_CHECK()==0);
    
    int compenstation_ADC=ADC_DATA+7;
    printf("ADC_DATAis %d\n", compenstation_ADC);

    return 0;
}

