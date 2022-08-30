// hello.c
#include <stdio.h>

int g1 = 20;
static int s1 = 14;
//global 에서 static은 이 파일 안에로 제한 >> foo.c에서 extern int s1해도 사용불가
const int c1 = 100;
//const 선언시 나중에 변경 불가 (read only)
extern int increment(int i);


int main() {
    int i = g1 + c1;
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));
    return 0;
}

