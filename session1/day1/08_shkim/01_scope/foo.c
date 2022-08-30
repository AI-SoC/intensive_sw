#include <stdio.h>

extern int g1; // 다른 파일 어딘가에 있으니 링킹 과정에서 찾아봐라
int s1 = 45; // hello.c 에 있는 s1과는 다름

int increment(int i){
    static int status = 0; // 다른 함수에서는 접근하지 못하는 전역변수화
    status++;
    printf("g1 is %d, %d, %d\n", g1, s1, status);
    return i + 1;
}