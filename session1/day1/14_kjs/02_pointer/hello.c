// hello.c
#include <stdio.h>
int main() {
    int* mbp = 0;

    printf("%p | %2X\n", (mbp+1), *(mbp+1));
    printf("%p | %2X\n", (mbp+2), *(mbp+2));
    printf("%p | %2X\n", (mbp+3), *(mbp+3));

    int arr[5] = {1,2,3,4,5};
    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n", i, arr[i], &arr[i] );
    return  0; 
}
