// hello.c
#include <stdio.h>
#include <stdlib.h>


int update(int* a, int* b){
    *a=125;
    *b=12;
}
int main() {
    int a=10;
    int b=20;
    int* ap=&a;
    printf("a is allocated with %d bytes @%p\n", sizeof(a), &a);
    printf("a is %d  @%p\n", *ap, ap);

    int** app=&ap;
    update(&a,&b);
    printf("a, b is %d, %d\n", a, b);

    unsigned int mem=0x12345678; ///32bit data
    unsigned int* mp=&mem; //4byte임. 전체 주소. 
    unsigned char* mbp=mp; //1byte만 가리킴. 그래서 주소 중에 맨 첫번째 부분의 한바이트만 나옴. 
    *(mbp+2)=0x5A;
    printf("%p | %2X\n", (mbp+0), *(mbp+0));
    printf("%p | %2X\n", (mbp+1), *(mbp+1));
    printf("%p | %2X\n", (mbp+2), *(mbp+2));
    printf("%p | %2X\n", (mbp+3), *(mbp+3));
    

    /*
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i=0; i<5; i++)
        printf("arr[%d} is %d at %p\n", i, arr[i], arr[i]);
    */
    return 0;
}

//포인터를 쓰면 return값을 두개로 받을 수 있는 효과가 있음. 원래는 한개밖에 반환못함. 