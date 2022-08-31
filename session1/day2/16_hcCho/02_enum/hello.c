// hello.c
#include <stdio.h>
 
enum ADC_STATUS{ EOC = 0, CON = 1 } ;
enum TIMER_MODE{ 
    TIMER_EN = (1<<7),  
    TIMER_ST = (1<<2)
} ;  
int adc_status(){

    return EOC ; 
}

int main() {

    unsigned int TMODE ; 

    if(adc_status() == CON)
        { printf("still conversion...\n") ; }
    else{ printf("end of conversion...\n") ;   } 
    
    // #define TMODE *((unsigned char*) 0xFFFF0000)
    TMODE  = TIMER_EN ; 
    TMODE |= TIMER_ST ; 
    printf("TIMER MODE: %2X\n", TMODE) ; 

    return 0;

}

