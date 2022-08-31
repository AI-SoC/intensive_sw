// hello.c
#include <stdio.h>

void detect_v1(int a, char b){
    // do something
    printf("detect_v1() is activated\n");
}

void detect_v2(int a, char b){
    // do something
    printf("detect_v2() is activated\n");
}

// 함수 콜은 기계 관점에서 함수의 시작 주소로 점프하는 거임
void (*detect)(int, char); // 함수 이름은 그 자체로 함수의 시작 주소이다. 4byte or 8byte  
// flash read write 느린 이유 : 다 지웠다가 다시 써야 돼 

void main(){
    int k = 10;
    char c = 12;
    int cond = 1;
    if (cond == 1){
        detect = detect_v2; // 칩이 계속 바뀔 수 있음
    }
    else{
        detect = detect_v1;
    }
    detect(10, 12); 
}


 