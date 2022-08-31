// hello.c
#include <stdio.h>
 
void print_array(int arr[5])
{
    printf("+-array listing-----------\n");
    for(int i=0; i<5; i++)
    {
        printf("arr[%d] is %8X at %p\n", i, arr[i], &arr[i]);
    }

}

void mem_inspection(unsigned char* abp, int N)
{
    printf("----------mem_inspection-----------\n");
    for(int i=0; i<N; i++)
    {
        printf("mem[%d] is %2X at %p\n", i, abp[i], &abp[i]);
    }
}

int main() {
    printf("Hello, world!\n");

    int arr[5] = {1,2,3,4,5};
    unsigned int uarr[5] = {0x12345678, 2,3,4,5};
    int* ap = uarr;   
    char* abp = (char*)uarr;

    print_array(uarr);
    mem_inspection(abp, 20);

    /*
    for(int i=0; i<5; i++)
    {
        printf("arr[%d] is %d at %p\n", i ,arr[i], &arr[i]);    
    }
    for(int i=0; i<5; i++)
    {
        printf("arr[%d] is %d at %p\n", i ,*(arr+i), arr+i);    
    }

    
    for(int i=0; i<5; i++)
    {
        printf("arr[%d] is %d at %p\n", i , *(ap+i), ap+i);    
    }
    
    for(int i=0; i<20; i++)
    {
        printf("mem[%d] is %2X at %p\n", i , *(abp+i), abp+i);    
    }*/

    unsigned int mat[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {3,5,1,9}
    };
    unsigned int* mp = mat;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            //printf("%2X ", mat[i][j]);
            printf("%2X ", *(mp+i*4+j));
        }
        printf("\n");        
    }

    return 0;
}

