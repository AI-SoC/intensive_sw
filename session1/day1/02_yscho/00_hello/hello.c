// hello.c
#include <stdio.h>
 

 int g1=10;
extern int increment(int i);


int main() {
    int i=g1;
    printf("Hello, world! %d\n", increment(i));
    return 0;
}

