// hello.c
#include <stdio.h>
 
int main() {
    printf("Hello, world!\n");

    int arr[2][2] = {{1,2},{3,4}};
    int (*p)[2] = arr; 
    printf("%p",p++);
    printf("%p",p++);
    return 0;
}

