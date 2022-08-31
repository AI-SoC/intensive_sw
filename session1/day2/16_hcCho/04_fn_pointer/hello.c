// hello.c
#include <stdio.h>
 
void detect_ver1(int a, char b){
    printf("detecct function.ver1 is activated\n") ; 
    printf("num: %d, char : %c\n", a, b) ; 
}

void detect_ver2(int a, char b){
    printf("detecct function.ver2 is activated\n") ; 
    printf("num: %d, char : %c\n", a, b) ; 
}
// 함수 이름은 함수 명령어의 시작 주소를 의마함 
// 함수 포인터 "pDetect"는 함수 "detect_ver1"의 주소를 저장함 
void(*pDetect)(int, char) = detect_ver1 ; 

int main() {

    int num = 10 ; 
    char ch = 65 ; 

    pDetect(10, ch) ; 

    pDetect = detect_ver2 ; 

    pDetect(10, ch) ; 

    return 0;

}

