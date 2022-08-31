#include<stdio.h>

int g1;
int s1= 45;
int increment(int i)
{
    static int status = 0;
    status++;
    printf("g1: %d\ts1: %d\t", g1, s1);
    printf("status: %d\n", status);
    return i+1;
}





