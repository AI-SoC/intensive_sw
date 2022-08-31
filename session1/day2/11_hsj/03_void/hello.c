// hello.c
#include <stdio.h>

int compare_int(int a, int b) {
    return (a==b);
}

int compare_float(float a, float b) {
    return (a==b);
}

int compare(int type, void* ap, void* bp){ //주소지만 가르키는 대상이 명시되지 않은
    if(type==0) {
        int* a = (int*)ap;
        int* b = (int*)bp;
        return *a == *b;
    } else {
        float* a = (float*)ap;
        float* b = (float*)bp;
    } 


}


int main() {
    int a = 100;
    int b = 200;
    if (compare_int(a,b)==1)
        printf("a is equal to b\n");
    else
        printf("a,b not equal\n");
    
    float c = 100.2;
    float d = 200.8;
    if (compare_float(c,d)==1)
        printf("c is equal to d\n");
    else
        printf("c,d not equal\n");

    if(compare(1,&a,&b)==1)
        printf("compare():equal\n");
    else
        printf("compare():not equal\n");

    if(compare(0,&c,&d)==1)
        printf("compare():equal\n");
    else
        printf("compare():not equal\n");


    return 0;
}

