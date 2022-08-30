// hello.c

// static variable은 global변수이나 함수 내에서만 접근 가능함 
// static variable로 변수를 선언할 경우 여러 함수에서 동일한 이름으로 변수 선언 가능 


#include <stdio.h>

int g1          = 10 ; 
const int c1    = 1000 ; 
        // constant를 사용하는 이유 1) 값 변경 방지 2) 해당 변수 사용 시 명령어에 해당하는 값을 인코딩함  
        // int c2 = g1 + c1 
        // --> LD  r1 [sp + 12]
        // --> LD  r2 [sp + 16]  
        // --> ADD r3, r1, r2
        // 대신에 아래와 같이 인코딩
static int s1   = 15 ; 
extern int increment(int i) ; 

int main() {



    printf("Hello, world!\n");
    
    printf("Number1 : %d\n", increment1(g1)) ;
    printf("Number3 : %d\n", increment2(g1)) ;

    printf("Number2 : %d\n", increment1(g1)) ;
    printf("Number4 : %d\n", increment2(g1)) ;
    return 0;
}

