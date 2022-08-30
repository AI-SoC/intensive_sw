// hello.c
#include <stdio.h>
 
int update(int a, int b)
{
    a = 100;
    b = 123;
    return 0;
}

int main() {
    int a = 10;
    int* ap = &a;
    
    //printf("a is allocated with %ld bytes\n@ %p\n", sizeof(a), &a);
    //printf("a is %d @ %p\n", *ap, ap);

    unsigned int mem = 0x12345678;
    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp;
    printf("%p | %2X\n", mbp, *(mbp+0));
    printf("%p | %2X\n", mbp, *(mbp+1));
    printf("%p | %2X\n", mbp, *(mbp+2));
    printf("%p | %2X\n", mbp, *(mbp+3));

    return 0;
}





