// hello.c
#include <stdio.h>

void print_array(int* arr, int n) {
    printf("----- array listing -----\n");
    for(int i = 0; i < n; i++)
        printf("arr[%d] is %8X at %p\n", i, arr[i], &arr[i]);
    printf("\n");
}

void mem_inspection(unsigned char* abp, int n) {
    printf("----- memory inspection -----\n");
    for(int i = 0; i < n; i++)
        printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i);
    printf("\n");
}

int main() {

    unsigned int arr[5] = {0x12345678, 3, 5, 7, 9};
    print_array(arr, sizeof(arr) / sizeof(int));
    
    /*
    for(int i = 0; i < 5; i++)
        printf("arr[%d] is %d at %p\n", i, *(arr+i), arr+i);
    printf("\n");    

    int* ap = &arr[0];
    ap = arr;
    for(int i = 0; i < 5; i++)
        printf("arr[%d] is %d at %p\n", i, *(ap+i), ap+i);
    printf("\n");
    */

    unsigned char* abp = (unsigned char*)arr;
    mem_inspection(abp, sizeof(arr) / sizeof(char));
    *(abp+2) = 0x5A;
    mem_inspection(abp, sizeof(arr) / sizeof(char));

    /*
    for(int i = 0; i < 20; i++)
        printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i);
    printf("\n"); 
    */


    unsigned int mat[3][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {3, 5, 1, 9}
    };
    
    unsigned int* mp = (unsigned int*)mat;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            //printf("%2X ", mat[i][j]);
            printf("%2X", *(mp+i*4+j));
        }
        printf("\n");
    }


    return 0;
}