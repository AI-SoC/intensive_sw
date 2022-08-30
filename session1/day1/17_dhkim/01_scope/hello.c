// hello.c
#include <stdio.h>
#define KKK 100

int g1 = 10;
static int s1 = 14;
const int c1 = 100;
int k1 = KKK;
extern int increment(int i);
int main() {
    int i = g1 + c1;
    
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));
    return 0;
}

