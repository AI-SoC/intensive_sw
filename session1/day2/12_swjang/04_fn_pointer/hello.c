// hello.c
#include <stdio.h>

/*
int compare_int(int a, int b) {
    return (a==b);
}

int compare_float(float a, float b) {
    return (a==b);
}

int compare(int type, void* ap, void* bp) {
    if(type == 0) {
        int* a = (int*)ap;
        int* b = (int*)bp;
        return *a == *b;
    }
    else if(type == 1) {
        float* a = (float*)ap;
        float* b = (float*)bp;
        return *a == *b;
    }
}*/

void detect_v1(int a, char b) {
    printf("dectect_v1() is activated\n");
}

void detect_v2(int a, char b) {
    printf("dectect_v2() is activated\n");
}

void (*detect)(int, char) = detect_v1; 

int main() {
    int k = 10;
    char c = 12;
    int cond = 1;
    if(cond == 1)
        detect = detect_v2;
    else
        detect = detect_v1;

    return 0;
}

