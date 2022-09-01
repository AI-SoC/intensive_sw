#include <stdio.h>
#define ALIGNED 1
#ifdef ALIGNED
struct foo{
    int     a; 
    short   b;
    short   h;
    int     d;
    char    c;
    char    e;
    char    f;
    char    g;
};

struct foo f1 = {
        0x1234567,
        0xFBCD,
        0xDDFF,
        0x1234567,
        0xEE,
        0xAB,
        0xCC,
        0xEE
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
struct foo f1 = {
        0x1234567,
        0xFBCD,
        0xEE,
        0x1234567,
        0xEE,
        0xAB,
        0xCC,
        0xDDFF
    };
#endif

int main(){
    

    printf("Struct foo's size is %ld\n", sizeof(f1));
    return 0;
}