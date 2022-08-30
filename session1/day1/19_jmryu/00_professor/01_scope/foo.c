#include <stdio.h>

//int g1; // 원래는 충돌이 나야 하는데 제대로 나옴 => compiler가 알아서 해준거임
extern int g1;
int s1 = 45;

int increment(int i){
    static int status = 0;  // global 변수 메모리 영역에 있음
    status++;
    printf("g1 is %d, %d, %d\n", g1, s1, status);
    return i + 1;
}