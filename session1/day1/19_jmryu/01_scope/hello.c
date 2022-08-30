// hello.c
#include <stdio.h>
 #define KK 200 // compile하기전에 대체하는 매크로일 뿐이다.

 int g1 = 20;
 static int s1 = 14;    // 변수가 파일 안으로 제한이 된다
const int c1 = 100; // linking할 때 c1을 바꾸는 코드가 들어갈 수가 있기 때문에 이를 방지하기 위해 const를 붙인다
int k1 = KK;
extern int increment(int i);

int main() {
    c1 = 12;
    int i = g1 + c1; //명령어에 해당되는 값을 encoding한다..?
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));

    return 0;
}

