// hello.c
#include <stdio.h>
#include <stdlib.h> 

void update(int _a, int _b){
    _a = 123 ; 
    _b = 12 ; 
}
void update_Ptr(int* _a, int* _b){
    *_a = 123 ; 
    *_b = 12 ; 
}
int main() {

    int     A   = 10  ; 
    int     B   = 20  ; 
    int*    pA  = &A  ;
    int**  ppA  = &pA ; 

    unsigned int     mem_UINT = 0x12345678; // 32bit data 
    unsigned int*    Pmem_UINT = &mem_UINT ; 
    unsigned char*   Pmem_CHAR = (unsigned char*)Pmem_UINT ; 

    printf("variable'A' is allocated with %ld bytes @ (%p/%p)\n", sizeof(A), &A, pA) ; 
    printf("A, B are %d, %d\n", A, B) ; 
    update(A, B) ; 
    printf("(after call-by-value)     A, B are %03d, %03d\n", A, B) ;
    update_Ptr(&A, &B) ; 
    printf("(after call-by-reference) A, B are %03d, %03d\n", A, B) ;
    
    printf("---------------------------------\n") ; 
    printf("Check little endian vs big endian\n") ; 
    printf("---------------------------------\n") ; 
    printf("%p | %2X\n", Pmem_CHAR, *Pmem_CHAR++) ; 
    printf("%p | %2X\n", Pmem_CHAR, *Pmem_CHAR++) ; 
    printf("%p | %2X\n", Pmem_CHAR, *Pmem_CHAR++) ; 
    printf("%p | %2X\n", Pmem_CHAR, *Pmem_CHAR++) ; 

    return 0;
}

