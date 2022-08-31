// hello.c
#include <stdio.h>
 
void print_array(int* arr, int N){
    printf("+-array listing ----------------------------\n");
    for(int i=0; i<N; i++)
        printf("arr[%d] is %8X at %p\n", i, arr[i], &arr[i]);
}

void mem_inspection(unsigned char* abp, int N){
    for(int i=0; i<N; i++)
        printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i);
}
int main() {
    unsigned int arr[5] = {0x12345678, 2, 3, 4, 5};
    print_array(arr, 5);
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]); //주소는 +4씩올라감
    /*for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, *(arr+i), arr+i); //주소에 +1하면 그 주소의 사이즈를 보고 더하기 1을 함. 4바이트면 +4바이트가 됨. 
    int* ap = &arr[0];
    ap=arr; //배열은 그 자체로 시작주소를 가리킨다.
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, *(ap+i), ap+i);*/
    unsigned char* abp=(unsigned char*)arr; //1byte만 가리키게 바꿈 원래는 int지만
    for(int i=0; i<20; i++)
        printf("mem[%d] is %2X at %p\n", i, *(abp+i), abp+i); //mem=memory //byte로 접근했다는 것은 메모리의 바이트 단위에서 직접 수정할 수 있음. 아니면은 
        //bit단위로 쪼개서 했어야 했음
        
    *(abp+2)=0x5A;
    mem_inspection(abp, 4*5);

    unsigned int mat[3][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8},
        {3, 5, 1, 9}
    };
    unsigned int* mp=(unsigned int*)mat;

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++){
          //  printf("%2X ", mat[i][j]);
          printf("%2X", *(mp+i*4+j));
        }
        printf("\n");
    }

    return 0;
}

