#include <stdio.h>


extern int g1;
int s1=45;


int increment(int i) {
    static int status =0;
    status++;
    printf("gi is %d ,%d ,%d\n",g1,s1,status);
    return i+1;

}


