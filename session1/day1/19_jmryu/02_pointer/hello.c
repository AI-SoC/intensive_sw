// hello.c
#include <stdio.h>
#include <stdlib.h>

//extern int increment(int i);

int update(int* a, int* b){
    *a = 123;
    *b = 12;
}
int main() {
    int a = 10;
    int b = 20;

    int* ap = &a;

    printf("a is allocated with %ld bytes @ %p\n", sizeof(a), &a);
    printf("a is %d @ %p\n", *ap, ap);
    
    int** app = &ap;  // 얘가 시험에 나올 것.
    *app = &b;
    update(&a, &b);
    printf(" a, b is %d, %d\n", a, b);

    unsigned int mem = 0x12345678;

    unsigned int* mp = &mem;    // 첫번째만 가리킴
    unsigned char* mbp = (unsigned char*)mp; // 1byte만 가리킴
    // intel : little endian, 근데 임베디드는 보통 big endian임
    printf("%p | %2X\n", (mbp + 0), *mbp++);
    printf("%p | %2X\n", (mbp + 1), *mbp++);
    printf("%p | %2X\n", (mbp + 2), *mbp++);
    printf("%p | %2X\n", (mbp + 3), *mbp++);

    return 0;
}

