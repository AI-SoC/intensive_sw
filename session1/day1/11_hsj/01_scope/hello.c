// hello.c
#include <stdio.h>

int g1 = 20;
static int s1 = 14;
const int c1 = 100;
extern int increment(int i);

int main() {
    int i=g1;
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));
    return 0;
}

int increment(int i) {
    return i+1;
}