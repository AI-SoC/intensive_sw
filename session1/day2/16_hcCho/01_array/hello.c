// hello.c
#include <stdio.h>
 
int main() {
    printf("Hello, world!\n");

    unsigned int mat[3][4] = { 
        { 1,  2,  3,  4}, 
        { 5,  6,  7,  8}, 
        { 9, 10, 11, 12} 
    }; 

    for(unsigned int i = 0 ; i < 3 ; i ++){
        for(unsigned int j = 0 ; j < 4 ; j++){
            printf("%u\t", mat[i][j]) ;
        }
        printf("\n") ; 
    }

    unsigned int *pMat = (unsigned int*)mat ; 

    for(unsigned int i = 0 ; i < 3 ; i ++){
        for(unsigned int j = 0 ; j < 4 ; j++){
            printf("%u\t", *(pMat + i + 4 * j)) ; 
        }
        printf("\n") ; 
    }

    return 0;

}

