#include <stdio.h>
//#define ALEGNED 
#ifdef ALLIGNED

struct foo{
    int     a;
    short   b;
    char    c;
    int     d;
    char    e;
    char    f;
    char    g;
    short   h;
};
#else
    struct foo{
        int     a;
        short   b;
        char    c;
        int     d;
        char    e;
        char    f;
        char    g;
        short   h;
    };
#endif

int main() {

#ifdef
    struct foo f1 = {
        0x12345678,
        0xFBCD,
        0XDDFF,
        0X12345678,
        0XAB,
        0XCC,
        0XEE,
        0XEE,

    };
#else
    struct foo f1 = {
        0x12345678,
        0xFBCD,
        0XDDFF,
        0X12345678,
        0XAB,
        0XCC,
        0XEE,
        0XEE,

    };
#endif
    printf("struct foo's size is %ld\n", sizeof(f1));
    return 0;
}