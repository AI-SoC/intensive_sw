// hello.c
#include <stdio.h>
void detect_v1(int a){
    printf("detect_v1() is avtivated\n");
}
void detect_v2(int a){
    printf("detect_v2() is avtivated\n");
}
void(*detect)(int, char);

void main(){
   int k = 10;
   char c =12;
   detect = detect_v1;
   detect(10,12);
}