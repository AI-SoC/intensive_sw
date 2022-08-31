// hello.c
#include <stdio.h>

void detect_v1(int a) {
    //do something
    printf("detect_v1() is activated\n");
}

void detect_v2(int a) {
    //do something
    printf("detect_v2() is activated\n");
}

void (*detect)(int) = detect_v2;

void main() {
    int k = 10;
    char c = 12;
    detect(10, 12); //함수 콜은 그 함수의 시작주소로 점프    
}

