// hello.c
#include <stdio.h>
void update(int* a, int* b){

    *a=123;
    *b=12;
}

int main() {

    int a=10;
    int b=20;
    int* ap;
    ap=&a;
    
    printf("a is allocated with %d bytes @ %p\n",sizeof(a),&a);
    printf("a is %d @ %p\n",*ap,ap);

    int** app;
    app=&ap;
    update(&a,&b);
    printf(" a, b is %d, %d\n",a,b);

    // endian big, little
    
    unsigned int mem=0x12345678; 
    unsigned int* mp=&mem;
    unsigned char* mbp=(unsigned char*)mp;

    // printf("%p | %2X\n",mbp,*mbp++);
    // printf("%p | %2X\n",mbp,*mbp++);
    // printf("%p | %2X\n",mbp,*mbp++);
    // printf("%p | %2X\n",mbp,*mbp++);
    
    printf("%p | %2X\n",(mbp+0),*(mbp+0));
    printf("%p | %2X\n",(mbp+1),*(mbp+1));
    printf("%p | %2X\n",(mbp+2),*(mbp+2));
    printf("%p | %2X\n",(mbp+3),*(mbp+3));
    // 0x78563412 LSB first Little endian  
    // little endian - intel 
    // embeded 보통 bigendian
    

    int arr[5]={1,2,3,4,5};

    for(int i=0; i<5; i++)
        printf("arr[%d] is %d at %p\n",i,arr[i],&arr[i]);
    return 0;

    
    
}

