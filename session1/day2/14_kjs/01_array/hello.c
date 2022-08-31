// hello.c
#include <stdio.h>
 void print_array(int arr[5]){
    printf("+-array listing ---------\n");
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]);
 }

 void mem_inspection(unsigned char* abp, int N){
    for(int i=0;i<N;i++)
    printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i);
 }
int main() {
    int arr[5] = {0x12345678,2,3,4,5};
    for(int i=0; i<5; i++)
    printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]);
    /*for(int i=0; i<5; i++)
    printf("arr[%d] is %d at %p\n", i, *(arr+i), arr+i);
    int* ap = &arr[0];
    ap = arr;
    for(int i=0; i<5; i++)
    printf("arr[%d] is %d at %p\n", i, *(ap+i), ap+i);*/
    unsigned char* abp = (unsigned char*)arr;
    for(int i=0; i<5; i++)
        printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i);

    *(abp+2) = 0x5A;
    for(int i=0; i<4; i++)
        printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i);
    return 0;
}