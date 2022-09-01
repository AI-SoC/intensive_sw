#include <stdio.h> 

struct foo{

    int     a ; 
    int     d ; 
    short   b ; 
    short   h ; 
    char    c ; 
    char    e ; 
    char    f ; 
    char    g ; 

}; 

int main(){

    struct foo f1 = {0x12345678, 0x12345678, 0xDDFF, 0xFBCD
    , 0xEE, 0xAB, 0xCC, 0xEE} ; 

    printf("'struct foo's size is %ld\n", sizeof(f1)) ; 

    return 0 ; 
}