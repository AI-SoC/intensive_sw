// hello.c
#include <stdio.h>
 
void print_array(int* arr, int N){
    printf("array listing-------------\n");
    for(int i=0; i<N; i++)
        printf("arr[%d] = %8X at %p\n", i, arr[i], &arr[i]);
    printf("array listing-------------\n\n");

}

void mem_inspection(unsigned char* abp, int N){
    printf("memory inspection-------------\n");
    for(int i=0; i<N; i++)
        printf("mem[%d] = %2X at %p\n", i, *(abp+i), abp+i);
    printf("memory inspection-------------\n\n");
}

int main() {
    unsigned int arr[5] = {0x12345678,2,3,4,5};
    print_array(arr, 5);

    for(int i=0; i<5; i++)
        printf("arr[%d] = %d at %p\n", i, arr[i], &arr[i]);

    printf("==========\n");

    for(int i=0; i<5; i++)
        printf("arr[%d] = %d at %p\n", i, *(arr+i), arr+i);
    printf("==========\n");

    int* ap = &arr[0];
    ap = arr;

    for(int i=0; i<5; i++)
        printf("ap[%d] = %d at %p\n", i, *(ap+i), ap+i);
    printf("==========\n");

    unsigned char* abp = (unsigned char*) arr;
    
    for(int i=0; i<20; i++)
    printf("mem[%d] = %2X at %p\n", i, *(abp+i), abp+i);
    printf("==========\n");

    *(abp+2) = 0x5A;
    mem_inspection(abp, 4*5);

    unsigned int mat[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {3,5,1,9}
    };
    unsigned int* mp = (unsigned int*)mat;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            //printf("%2X ", mat[i][j]);
            printf("%2X", *(mp+i*4+j));
        }
        printf("\n");
    }

    return 0;

}

