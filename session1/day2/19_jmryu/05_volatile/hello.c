// hello.c
#include <stdio.h>
 
int ADC_EOC_CHECK(){
    // wait for end of conversion
    int a;
    for (int i = 0; i < 100000; i++)    // hardware delay emulation
    {
        a = 10; // do something
    }
    return 1;   // end of conversion
}

int main() {
    printf("Hello, world!\n");
    // ADC_DATA = .... WILL BE EXECUTED BY HW  
    
    volatile int ADC_DATA = 3;  // volatile : 스스로 값이 바뀐다, 휘발성
    // 변수가 매핑된 곳에 hw가 존재한다면 volatile붙여야 됨
    // 최적화 막아주는 기능

    while (ADC_EOC_CHECK == 0);

    int compensated_ADC = ADC_DATA + 7;
    printf("ADC_DATA is %d\n", compensated_ADC);

    return 0;
}

 