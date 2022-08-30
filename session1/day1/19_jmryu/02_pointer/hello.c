// hello.c
#include <stdio.h>
#include <stdlib.h>

//extern int increment(int i);

int main() {
    int a = 10;
    printf("a is allocated with %d bytes @ %p\n", sizeof(a), &a);
    return 0;
}

