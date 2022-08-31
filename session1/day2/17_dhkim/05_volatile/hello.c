// hello.c
#include <stdio.h>

int ADC_EOC_CHECK() {
    // wait for end of conversion
    int a;
    for(int i=0; i<100000; i++) // hardware delay emulation
        a = 10; // do something 
    
    return 1;
}

int main() {
    // ADC_DATA = ... will be executed by Hardware   => 스스로 업데이트 될 수 있다
    // 그래서, 변수가 맵핑된 곳에 하드웨어가 존재하면, volatile 키워드를 반드시 써줘야 한다 !!!
    volatile int ADC_DATA = 3;      
    // blocking until status is matched
    while(ADC_EOC_CHECK() == 0); 


    int compensated_ADC = ADC_DATA + 7;
    printf("ADC_DATA is %d\n", compensated_ADC);

    return 0;
}