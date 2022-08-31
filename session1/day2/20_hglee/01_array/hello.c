// hello.c
#include <stdio.h>

void print_array(int* arr, int N){
    printf("PRINT ARRAY Func LISTING \n");
    for (int i = 0; i<N; i++){
        printf("arr [%d] is %8X at %p \n", i, *(arr+i), arr+i);
    }
    printf("-----\n");
}

void mem_inspection(unsigned char* abp, int N){
    printf("MEM Inspect Func \n");
    for (int i = 0; i<N; i++){
        printf("mem [%d] is %2X at %p \n", i, *(abp+i), abp+i);
    }
}

int main() { 
    unsigned int arr[5] = {0x12645958,2,3,4,5};
    // print_array(arr, 5);

    unsigned char* abp = (unsigned char *)arr;
    // mem_inspection(abp, 4*5);

    // 2d-array
    unsigned int mat[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,1,3,5}
        };
    unsigned int* mp = (unsigned int*)mat;

    for (int i = 0; i<3; i++){
        for (int j = 0; j < 4; j++){
            // printf("mem1 [%d][%d] is %d\n", i,j, mat[i][j]);
            printf("mem2 [%d][%d] is %d\n", i,j, *(mp+i*4+j));
        }
        printf("\n");
    }
    


    /*
    // for (int i = 0; i<5; i++){
    //     printf("arr [%d] is %d at %p \n", i, arr[i], &arr[i]);
    // }
    for (int i = 0; i<5; i++){
        printf("arr [%d] is %d at %p \n", i, *(arr+i), arr+i);
    }

    // ap == arr 결국은 arr은 배열 시작 주소를 나타내므로
    int* ap = &arr[0];  
    // ap = arr;
    for (int i = 0; i<5; i++){
        printf("ap  [%d] is %d at %p \n", i, *(ap+i), ap+i);
    }
    */

   /*
    unsigned char* abp = (unsigned char *)arr;
    for (int i = 0; i<4; i++){
        printf("abp1 [%d] is %2X at %p \n", i, *(abp+i), abp+i);
    }

    printf("\n");
    *(abp+2) = 0x5A;

    for (int i = 0; i<4; i++){
        printf("abp2 [%d] is %2X at %p \n", i, *(abp+i), abp+i);
    }
    */

    return 0;
}

