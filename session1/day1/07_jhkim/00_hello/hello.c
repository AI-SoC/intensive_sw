// hello.c
#include <stdio.h>
#define KK 200

int g1 = 20;
extern int increment(int i);

int main() {
    int i = g1;
    
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));

    return 0;

}

