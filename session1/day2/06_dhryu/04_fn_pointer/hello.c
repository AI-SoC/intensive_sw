// hello.c
#include <stdio.h>

void detect_v1(int a){
    // do something
    printf("detect_v1() is activated");
}

void detect_v2(int a){
    // do something
    printf("detect_v2() is activated\n");
}

void (*detect)(int) = detect_v1;
//함수를 가리키는 포인터
//뒤에 괄호는 인자!!

int main() {
    int k = 10;
    char c = 12;
    detect(10);

    return 0;
}

