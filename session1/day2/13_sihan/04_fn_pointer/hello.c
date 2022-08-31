// hello.c
#include <stdio.h>
// function pointer 


void detect_v1(int a,char b){
//do something
    printf("detect_v1() is activated\n");    
}


void detect_v2(int a,char b){
//do something
    printf("detect_v2() is activated\n");    
}

void (*detect) (int,char)= detect_v2; //함수를 가리키는 포인터다.


//초과 이득의 법칙

void main() {
    int k=10;
    char c=12;
    int cond=1;
    if(cond==1)
        detect=detect_v2;
    else
        detect=detect_v1;
    detect(10,12);
}

