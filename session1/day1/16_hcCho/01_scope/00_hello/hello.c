// hello.c
#include <stdio.h>

extern int increment(int i) ; 

int main() {

    int i = 10 ; 

    printf("Hello, world!\n");
    printf("Number : %d\n", increment(i)) ;

    return 0;
}

