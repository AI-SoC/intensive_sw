/* 
.c 소스코드 
.i 전처리 결과
.s 어셈블리어 파일
.o 기계어
.exe 실행파일
*/
// hello.c
#include <stdio.h>

int ADC_EOC_CHECK(){
    int a;

    for(int i=0; i<10000; i++){
        a=10;
    }
    return 1;
}


int main() {
    volatile int ADC_DATA=3;
    // ADC_DATA = ... will be executed by HW
    while(ADC_EOC_CHECK()==0);

    int compenstated_ADC = ADC_DATA + 7;
    printf("ADC_DATA is %d \n", compenstated_ADC);

    return 0;
}

