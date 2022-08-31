#include <stdio.h>

void detect_v1(int a, char c){
    // do something
    printf("detect_v1() is activated\n");
}

void detect_v2(int a, char c){
    // do something
    printf("detect_v2() is activated\n");
}

void (*detect)(int, char) = detect_v1; // 함수의 이릉은 함수의 시작 주소 -> 함수의 첫번째 CMD가 시작되는 주소

int main()
{
    int k = 10;
    char c = 12;
    int cond = 1;
    if (cond == 1)
        detect = detect_v2;
    else
        detect = detect_v1;
    detect(k, c);

    return 0;
}