// hello.c
#include <stdio.h>
 
int g1 = 10;
static int s1 = 14;
const int c1 = 100;
extern int increment(int i);

int main() {
    int i = g1+c1;
    
    printf("Hello, world! %d\n",increment(i));
    printf("Hello, world! %d\n",increment(c1));
    return 0;
}