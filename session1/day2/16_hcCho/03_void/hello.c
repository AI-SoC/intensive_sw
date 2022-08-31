// hello.c
#include <stdio.h>
 
int cmp_int(int num1, int num2){

    if(num1 == num2){return 1; } 
    else            {return 0; }
        
}

int cmp_flt(float num1, float num2){

    if(num1 == num2){return 1; } 
    else            {return 0; }
        
}

int cmp(int type, void* pNum1, void *pNum2){
    if(type == 0){
        int num1 = *((int*) pNum1) ; 
        int num2 = *((int*) pNum2) ;
        return num1 == num2 ;  
    }
    else{
        float num1 = *((float*) pNum1) ; 
        float num2 = *((float*) pNum2) ;
        return num1 == num2 ;
    }
}
int main() {

    int num1 = 100 ; 
    int num2 = 200 ; 

    float flt1 = 2.1 ; 
    float flt2 = 2.2 ; 

    /*----------------------------------------
        || compare integer type number || 
    ----------------------------------------*/
    if(cmp_int(num1, num2) == 1)
        printf("cmp_int():num1 and num2 are equal\n") ; 
    else
        printf("cmp_int(): num1 and num2 are differ\n") ; 

    /*----------------------------------------
         || compare float type number || 
    ----------------------------------------*/
    if(cmp_flt(flt1, flt2) == 1)
        printf("cmp_flt(): float num1 and float num2 are equal\n") ; 
    else
        printf("cmp_flt(): float num1 and float num2 are differ\n") ; 

    /*----------------------------------------
    ||  compare integer/float type number   || 
    ----------------------------------------*/
    if(cmp(1, &num1, &num2) == 1)
        printf("cmp(): integer num1 and integer num2 are equal\n") ; 
    else
        printf("cmp(): integer num1 and integer num2 are differ\n") ; 

    if(cmp(2, &flt1, &flt2) == 1)
        printf("cmp(): float num1 and float num2 are equal\n") ; 
    else
        printf("cmp(): float num1 and float num2 are differ\n") ; 

    return 0;

}

