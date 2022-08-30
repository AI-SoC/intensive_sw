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

    // printf("a is allocated with %d bytes @ %p \n", sizeof(a), &a);
    // printf("a is %d @ %p \n", *ap, ap);

    int** app = &ap;

    // update(&a,&b);
    // printf("a,b is %d, %d\n", a,b);

    unsigned int mem = 0x12345678;

    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp;
    printf("%p | %2X\n",(mbp+0), *(mbp+0));
    printf("%p | %2X\n",(mbp+1), *(mbp+1));
    printf("%p | %2X\n",(mbp+2), *(mbp+2));
    printf("%p | %2X\n",(mbp+3), *(mbp+3));


    return 0;
}

