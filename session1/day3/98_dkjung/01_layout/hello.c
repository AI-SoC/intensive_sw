// hello.c
#include <stdio.h>
#define ALIGNED
#ifdef ALIGNED
struct foo{
    int a;
    short b;
    char c;
    int d;

    char e;
    char f;
    char g; 
    short h;
};
#else
struct foo{
    int a;
    short b;
    short h;
    int d;

    char e;
    char f;
    char g; 
    char c;
};
#endif

int main() {
    #ifdef ALIGNED
    struct foo f1 = {
        0x12345678,
        0xFDCD,
        0xAB,
        0x12345678,

        0xCC,
        0xEE,
        0xEE,
        0xDDFF
    };
    #else
        struct foo f1 = {
        0x12345678,
        0xFDCD,
        0xDDFF,
        0x12345678,
        0xAB,
        0xCC,
        0xEE,
        0xEE
    };
    #endif

    printf("size of foo is %d\n",sizeof(f1));
    return 0;
}

