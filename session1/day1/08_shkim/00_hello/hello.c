// hello.c
#include <stdio.h>

extern int increment(int i); // extern: 다른 어딘가에 이 함수가 있다고 알려주기

int main() {
    int i = 10;
    printf("Hello, world! %d\n", increment(i));
    return 0;
}

