// hello.c
#include <stdio.h>

void print_array(int* arr) {
    printf("+-array listing -----\n");
    for(int i=0; i<5; i++)
        printf("arr[%d] is %8x at %p\n", i, arr[i], &arr[i]);
}

void mem_inspection(unsigned char* abp, int N) {
    for(int i=0; i<N; i++)
        printf("mem[%d] is %2x at %p\n", i, *(abp+i), abp+i);
}


int main() {
    printf("Hello, world!\n");
    unsigned int arr[5] = {0X12345678,2,3,4,5};
    print_array(arr);
    
    /*
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]);
    

    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, *(arr+i), arr+i);

    int* ap = &arr[0];
    ap = arr;
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, *(ap+i), ap+i);
    */
    
    char* abp = (char*)arr;
    for(int i=0; i<20; i++)
        printf("mem[%d] is %2x at %p\n", i, *(abp+i), abp+i);
    
    *(abp+2)=0x5A;
    mem_inspection(abp, 4*5);


    unsigned int mat[3][4] ={
        {1,2,3,4},
        {5,6,7,8},
        {3,5,1,9}
    };

    unsigned int* mp = (unsigned int*)mat;

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++) {
            //printf("%2x ", mat[i][j]);
            printf("%2x ", *(mp+i*4+j));    
        }
        printf("\n");
    }


    return 0;
}

