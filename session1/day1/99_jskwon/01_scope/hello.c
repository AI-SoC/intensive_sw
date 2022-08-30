// hello.c
#include <stdio.h>
#define KK 200
int g1=20;
static int s1=14;
const int c1 = 100;
int k1 = KK;
extern int increment(int i);

int main() {
    int i=g1 + c1;
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));
 
    return 0;
}

