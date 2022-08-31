// hello.c
#include <stdio.h>

void detect_v1(int a, char b){
    // do something
    printf("detect_v1() is activated\n\n");
}
void detect_v2(int a, char b){
    // do something
    printf("detect_v2() is activated\n");
}

// 함수 포인터
void (*detect)(int, char) = detect_v1;    // 주소값을 담기 위한 변수 --> detect
// -> void: 리턴형

int main() {
    int k=10;
    char c=12;
    int cond = 1;
    if(cond==1)
        detect = detect_v2;
    else
        detect = detect_v1;

    detect(10,12);
    
    return 0;
}