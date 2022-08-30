// hello.c
#include <stdio.h>

// extern: this function exists somewhere...
extern int increment(int i);

int main() {
    printf("Hello, world! %d \n", increment(10));
    return 0;
}

