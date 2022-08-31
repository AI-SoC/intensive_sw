// hello.c
#include <stdio.h>
int compare_int(int a, int b){
    return(a==b);
}
int compare_float(float a, float b){
    return(a==b);
}

int compare(int type, void* ap, void* bp){
        if(type == 0){
            int* a = (int*)ap;
            int* b = (int*)bp;
        }
}

int main(){
   int a = 100;
   int b = 200;
    if ( compare_int(a,b) == 1)
        printf("a is equal to b\n");
    else
        printf("a is not equal to b\n");
    int c = 100.2;
    int d = 200.8;
    if ( compare_float(c,d) == 1)
        printf("c is equal to d\n");
    else
        printf("c is not equal to d\n");

    if(compare(1,a,b) ==1)
        printf("compare(): equal\n");
    else
        printf("compare(): not equal\n");
    return 0;
}