// hello.c
#include <stdio.h>
int compare_int(int a, int b){
    return(a==b);
}
int main(){
   int a = 100;
   int b = 200;
    if ( compare_int(a,b) == 1)
        printf("a is equal to b\n");
    else
        printf("a is not equal to b\n");
    return 0;
}