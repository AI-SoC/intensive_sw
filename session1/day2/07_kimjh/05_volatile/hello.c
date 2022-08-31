// hello.c
#include <stdio.h>
 
int ADC_EOC_ECHECK()
{
    //wait for end of conversion
    int a;
    for(int i=0; i<100000; i++)//hardware delay emulation
    {
        a = 10;
        
    }
    return 1;//end of convesion
}
int main() {
    printf("Hello, world!\n");
    volatile int ADC_DATA=3; //ADC_DATA will be executed by Hardware
    while(ADC_EOC_ECHECK()==0); //blocking until status is matched
    int compensated_ADC = ADC_DATA + 7;
    printf("ADC_DATA is %d \n", compensated_ADC);

    return 0;
}

