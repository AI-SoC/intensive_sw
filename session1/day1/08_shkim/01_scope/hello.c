// hello.c
#include <stdio.h>
#define KK 200 // #: pre-processing -> 컴파일이 아니라 그냥 KK를 200으로 대체

int g1 = 20; // 전역변수는 모든 파일과 모든 함수로 퍼져 나간다
static int s1 = 14; // static: 이 전역변수는 이 파일 내에서만 사용 가능
const int c1 = 100; // 명령어의 value를 encoding -> 속도 향상
int k1 = KK;
extern int increment(int i); // extern: 다른 어딘가에 이 함수가 있다고 알려주기

int main() {
    int i = g1 + c1;
    printf("Hello, world! %d\n", increment(i));
    printf("Hello, world! %d\n", increment(i));
    return 0;
}

