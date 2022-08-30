#include <stdio.h>

extern int g1;
int s1 = 45;

int increment(int i){
    static int status = 0;
    status++;

    printf("g1 is %d\n", g1);
    printf("s1 is %d\n", s1);
    printf("status is %d\n", status);

    return i+1;
}