// hello.c
#include <stdio.h>

// variable
int g1 = 20;
static int s1 = 14;

/*
const를 함으로써 성능 개선
value 자체를 encoding 하여 메모리 로드하는 것을 없앰
*/ 
const int c1 = 100; 

// function
extern int increment(int i);
 
// main
int main() {
    int i = g1 + c1;

    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));

    return 0;
}

// int increment(int i){
//     return i+1;
// }
