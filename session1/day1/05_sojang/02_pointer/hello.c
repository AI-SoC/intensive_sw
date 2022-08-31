// hello.c
#include <stdio.h>
#include <stdlib.h>

int update(int* a, int* b){
    *a = 123;
    *b= 12;
}

int main() {
    int a = 10;
    int b = 20;
    int* ap = &a;

    printf("a is allocated with %d bytes @ %p\n", sizeof(a), &a);
    printf("a is %d @ %p\n", *ap, ap);

    //(int*)* app = &ap;
    int** app = &ap;
    update(&a,&b);
    printf(" a, b is %d, %d\n",a,b);

    unsigned int mem = 0x12345678;
    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp; // 한 바이트만 확인
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);

    return 0;
}

