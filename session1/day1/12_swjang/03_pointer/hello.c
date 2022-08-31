// hello.c
#include <stdio.h>

int update(int* a, int* b) {
    *a = 123;
    *b = 12;

    return 1;
}

int main() {
    int a = 10;
    int b = 20;
    int* ap = &a;
    *ap = 100;
    printf("a is allocated with %d bytes @ %p\n", (int)sizeof(a), &a);
    printf("a is %d @ %p\n", *ap, ap);

    int** app = &ap;
    *app = &b;

    printf("app is %d\n", **app);

    update(&a, &b);
    printf("a, b is %d, %d\n", a, b);


    // endian
    unsigned int mem = 0x12345678;
    unsigned int* mp = &mem;
    unsigned char* mbp = (unsigned char*)mp;

    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);
    printf("%p | %2X\n", mbp, *mbp++);

    int arr[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i]);
    }

    return 0;
}
