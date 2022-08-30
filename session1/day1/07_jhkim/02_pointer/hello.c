// hello.c
#include <stdio.h>

int update(int* a, int* b)
{
    *a=123;
    *b=12;
}

int main() {
    int a=10;
    int b=20;
    int* ap = &a;
    
    printf("a is allocated with %d bytes @ %p \n", sizeof(a), &a);
    printf("a is %d @ %p \n", *ap, ap);
  
    int** app=&ap;
    update(&a,&b);

    printf("%d, %d\n", a,b);

    unsigned int mem = 0x12345678;

    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp;
    printf("%p | %2x\n", mbp, *mbp++);
    printf("%p | %2x\n", mbp, *mbp++);
    printf("%p | %2x\n", mbp, *mbp++);
    printf("%p | %2x\n", mbp, *mbp++);

    return 0;
}