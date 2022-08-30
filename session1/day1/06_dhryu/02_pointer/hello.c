// hello.c
#include <stdio.h>

int update(int* a, int* b){
    *a = 123;
    *b = 12;
}

int main() {
    int a = 10;
    int b = 20;
    int* ap = &a;
    *ap = 100;
    printf("a is allocated with %ld bytes @ %p\n", sizeof(a), &a);
    printf("a is %d @ %p\n", *ap, ap);
    update(&a,&b);
    printf("(a, b) is (%d, %d)\n",a,b);
    int** app = &ap;
    *app = &b;

    //endian little, big 
    unsigned int mem = 0x12345678;
    //big endian이 주소 커질수록 12 ,34 ,56, 78
    //little endian이 주소 커질수록 78, 56, 34, 12
    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp;
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    /*
    위의 실행결과!!
    0x7fffe8be4e35 | 78
    0x7fffe8be4e36 | 56
    0x7fffe8be4e37 | 34
    0x7fffe8be4e38 | 12
    */
    return 0;
}

