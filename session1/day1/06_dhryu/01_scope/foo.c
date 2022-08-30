#include <stdio.h>

extern int g1;
//임베디드에서는 글로벌 변수 사용 (메모리를 적게 사용하기 때문에)
//hello.c에 있는 g1은 글로벌 변수라서 되는데 이 밑에 increment 함수에서 g1이라는 거를 extern을 이용하여서 가능하게 해줌
//extern int s1; static으로 선언되어 호출 불가
int s1 = 45; 
//이렇게 선언하면 main(hello.c)의 s1과 다른 변수로 선언된다!
// main에서 static으로 선언해서

int increment(int i){
    static int status = 0;
    status++;
    //이 status 변수는 내장함수라서 함수 끝나면 사라짐
    printf("g1 is %d %d\n", g1, status);
    return i+1;
}