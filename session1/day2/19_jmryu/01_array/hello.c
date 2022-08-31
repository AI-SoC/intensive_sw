// hello.c
#include <stdio.h>
 
void print_array(int* arr, int N){
    printf("+-array listing ----------------------\n");
    for (int i = 0; i < N; i++){
        printf("arr[%d] is %8X at %p\n", i, arr[i], &arr[i]);   // 8 byte   
    }
}

void mem_inspection(unsigned char* abp, int N){
    for (int i = 0; i < N; i++){
        printf("mem[%d] is %2X at %p\n", i, *(abp + i), abp + i);   // %2X, 2 byte 
    }
}

int main() {
    unsigned int arr[5] = {0x12345678, 2, 3, 4, 5}; // little endian, lsb가 낮은 주소에 할당됨
    print_array(arr, 5);

    /*
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("arr[%d] is %d at %p\n", i, *(arr + i), arr + i);
    }

    int* ap = &arr[0];
    ap = arr;   // 배열의 시작주소

    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("arr[%d] is %d at %p\n", i, *(ap + i), ap + i);
    }
    */

    // 0x12345678 의 45 값 바꾸려면 little endian이기 때문에 8쪽에서부터 2번 세야 됨
    unsigned char* abp = (unsigned char*)arr;
    *(abp + 2) = 0x5A;  // 요 내용이 시험에 나올 수 있어요
    mem_inspection(abp, 4 * 5);

    /*
    printf("\n");

    for (int i = 0; i < 20; i++){
        printf("mem[%d] is %2X at %p\n", i, *(abp + i), abp + i);   // %2X, 2 byte 
    }
    */

    unsigned int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {3, 5, 1, 9}
    };

    unsigned int* mp = (unsigned int*) mat;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            //printf("%2X ", mat[i][j]);    // 방 자체에만 접근이 됨
            printf("%2X ", *(mp + i * 4 + j));  // 여러 element로 구성된 구조체일 수도 있으므로 
        }
        printf("\n");
    }

    return 0;
}

 