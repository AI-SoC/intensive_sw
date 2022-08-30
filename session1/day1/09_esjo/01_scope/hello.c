// hello.c
#include <stdio.h>

// extern: this function exists somewhere...
int g1 = 20;
static int s1=14;
const int c1 = 100; // no need to be assigned to memory...
extern int increment(int i);

int main() {
    c1 = 12;
    int i = g1 +c1;
    printf("Hello, world! %d \n", increment(10));
    printf("Hello, world! %d \n", increment(10));
    return 0;
}

