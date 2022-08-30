// hello.c
#include <stdio.h>

int g1=20;
static int s1=14;                   // 다른 파일에서 접근 불가능  
const int c1=100;
extern int increment(int i);        // 모든 파일에서 접근 가능

int main(){
    int i=g1 + c1;
    printf("Hello, World! %d\n", increment(i));
    printf("Hello, World! %d\n", increment(i));
    
    return 0;
}

