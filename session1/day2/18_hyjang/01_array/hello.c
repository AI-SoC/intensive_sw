// hello.c
#include <stdio.h>
 
int main() {
    int arr[5] = {1,2,3,4,5};
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p \n", i, arr[i], &arr[i]);
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p \n", i, *(arr+i), arr+i);

    int* ap = &arr[0];
    ap = arr;
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p \n", i, *(ap+i), ap+i);

    char* abp = (char*)arr;
    for(int i=0; i<20; i++)
        printf("mem[%d] is %2X at %p \n", i, *(abp+i), abp+i);
    return 0;
}

