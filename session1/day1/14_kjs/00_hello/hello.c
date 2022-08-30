// hello.c
#include <stdio.h>
 
int increment(int i){
        return i+1;
}
int main() {
    int i=10;
    printf("Hello, world! %d\n", increment(i) );
    return 0;
}

