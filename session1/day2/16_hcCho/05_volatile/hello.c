// hello.c
#include <stdio.h>

int ADC_EOC_CHECK(){

    // wait for end of conversion 
    // hardware delay emulation 
    int a ; 
    for(register unsigned int i = 0 ; i < 1e+5; i++){
        a = 10 ; // do something 
    }
    return 1 ; // end of conversion  
}

int main() {

    
    // ADC = ... will be executed by H/W 
    volatile int ADC = 03; 
    
    // blocking until satus is matched 
    while(ADC_EOC_CHECK() == 0) ; 

    int compensated_ADC = ADC + 7 ; 

    printf("ADC_DATA is %d\n"            , ADC) ; 
    printf("compensated ADC_DATA is %d\n", compensated_ADC) ; 


    return 0;

}

