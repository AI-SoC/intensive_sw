#include <stdio.h>


extern int g1 ; 
int s1 = 45 ; 

int increment1(int i){ 

    static int status = 0 ; 
    status++ ; 

    printf("status is : %d\n", status);
    printf("g1 is : %d\n", g1) ;
    printf("s1 is : %d\n", s1) ; 
    return i + 1 ; 
}


int increment2(int i){ 

    static int status = 0 ; 
    status++ ; 

    printf("status is : %d\n", status);
    printf("g1 is : %d\n", g1) ;
    printf("s1 is : %d\n", s1) ; 
    return i + 1 ; 
}
