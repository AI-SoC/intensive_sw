#include <stdio.h> 

struct BITS8{
    unsigned int b0 : 1 ; 
    unsigned int b1 : 1 ; 
    unsigned int b2 : 1 ; 
    unsigned int b3 : 1 ; 
    unsigned int b4 : 1 ; 
    unsigned int b5 : 1 ; 
    unsigned int b6 : 1 ; 
    unsigned int b7 : 1 ; 
} ; 

union PORT0{
    unsigned char U ; 
    struct BITS8  B ; 
}; 

int main(){

    union PORT0 port0 ; 

    /*

        unsigned char P0 = 0x95 ;  
        printf("P0 : 0x%02X\n", P0) ; 
        P0 = P0 & ~(1 << 4) ; 

        printf("P0 : 0x%02X\n", P0) ; 
        P0 = P0 & ~(1 << 7) ;  // P0 = P0 & ~(0x80)

        printf("P0 : 0x%02X\n", P0) ; 
        
    */

        port0.U = 0xFF ;
        printf("port0 : 0x%02X\n", port0.U) ;  
        port0.B.b7 = 0 ; 
        printf("port0 : 0x%02X\n", port0.U) ; 


    
    
    return 0; 

}