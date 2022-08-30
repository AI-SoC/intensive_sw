// hello.c
#include <stdio.h>
extern int increment(int i);
int main() {
    int i = 10;
    printf("Hello, world %d\n", increment(i));
    return 0;
    
}