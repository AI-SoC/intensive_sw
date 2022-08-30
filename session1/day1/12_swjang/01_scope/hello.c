// hello.c
#include <stdio.h>
#define AA 200
 
int g1 = 20;
static int s1 = 14;
const int c1 = 100;  // 명령어에 해당되는 값을 인코딩한다 
int k1 = KK;
extern int increment(int i);

int main() {
    int i = g1;
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));
    return 0;
}
