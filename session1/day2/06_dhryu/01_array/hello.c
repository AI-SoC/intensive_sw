// hello.c
#include <stdio.h>
 
void print_array(int* a, int N){
    printf("+-array listing --------\n");
    for(int i = 0;i<N;i++){
        printf("arr[%d] is %8x at %p\n", i, a[i], &a[i]);
    } 
}

void mem_inspection(unsigned char* abp, int N){
    for(int i = 0;i<N;i++){
        printf("mem[%d] is %2x at %p\n", i, *(abp+i), abp+i);
    }
}

int main() {
    //unsigned int arr[5] = {0x12345678,2,3,4,5};
    //unsigned char* abp = (unsigned char*)arr;
    //print_array(arr, 5);
    //mem_inspection(abp, 4);
    /*
    for(int i = 0;i<5;i++){
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]);
    } 

    printf("\n");

    for(int i = 0;i<5;i++){
        printf("arr[%d] is %d at %p\n", i, *(arr+i), arr+i);
    }

    int* ap = &arr[0];
    ap = arr; //arr은 시작주소를 의미
    printf("\n");

    for(int i = 0;i<5;i++){
        printf("arr[%d] is %d at %p\n", i, *(ap+i), ap+i);
    }

    printf("\n");
    unsigned char* abp = (unsigned char*)arr;
    for(int i = 0;i<20;i++){
        printf("mem[%d] is %2x at %p\n", i, *(abp+i), abp+i);
    }
    //byte 단위로 little endian, big endian해서 다 살펴보는 방법
    mem[0] is 78 at 0x7fffe49834b0
    mem[1] is 56 at 0x7fffe49834b1
    mem[2] is 34 at 0x7fffe49834b2
    mem[3] is 12 at 0x7fffe49834b3
    //라서 0x12345678 에서 0x125A5678 으로 바꾸고싶으면
    (abp+2) = 0x5A 로 해야한다. LITTLE ENDIAN?
    
    */


    unsigned int mat[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printf("%p \n", mat);
    printf("%p \n", *mat);
    printf("%p \n", (int*)mat);
    printf("%d \n", *((int*)mat+1*4+2));
    
    unsigned int* mp = (unsigned int*)mat;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            printf("%2X ", *(mp+i*4+j));
        }
        printf("\n");
    }
    //mat[1][2]를 호출   (int*)mat은 그냥 1차원 시작주소값?인느낌
    /*
    1 2 3 4
    5 6 7 8
    9 10 11 12
    */
    return 0;
}

