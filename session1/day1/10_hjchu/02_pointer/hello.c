// hello.c
#include <stdio.h>
#include <stdlib.h>
 
int update(int* a, int* b){
    *a = 123;
    *b = 12;
}

int main() {
    int a = 10;
    int b = 20;
    int * ap = &a;
    int** app = &ap;
    
    update(&a, &b);
    printf("a, b is %d, %d\n", a, b);
    printf("a is alllocated with %lu bytes @ %p\n", sizeof(a), &a);
    printf("a is %d @ %p\n", *ap, ap);
    
    unsigned int mem = 0x12345678;
    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp;
    printf("%p | %2x\n", mbp, *mbp++);
    printf("%p | %2x\n", mbp, *mbp++);
    printf("%p | %2x\n", mbp, *mbp++);
    printf("%p | %2x\n", mbp, *mbp++);

    
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
    {
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]);
    }


    return 0;
}

