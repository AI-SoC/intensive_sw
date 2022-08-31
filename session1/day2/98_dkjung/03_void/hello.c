// hello.c
#include <stdio.h>

int compare_int(int a, int b){
    return (a==b);
}
int compare_float(float a, float b){
    return (a==b);
}
int compare(int type, void* ap, void* bp)
{
    if(type == 0)
    {
        int* a = (int*)ap;
        int* b = (int*)bp;
        return (*a==*b);
    }
    else
    {
        float* a = (float*)ap;
        float* b = (float*)bp;
        return (*a==*b);
    }
}

int main() {
    int a = 100;
    int b = 200;
    if(compare(1,&a,&b) == 1)
        printf("a is equel to b\n");
    else
        printf("a is not equel to b\n");

    float c = 100.25;
    float d = 200.96;
    if(compare(0,&c,&d) == 1)
        printf("c is equel to d\n");
    else
        printf("c is not equel to d\n");
    
    return 0;
}

