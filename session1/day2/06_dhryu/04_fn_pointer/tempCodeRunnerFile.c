   printf("\n");
    unsigned char* abp = (unsigned char*)arr;
    for(int i = 0;i<20;i++){
        printf("mem[%d] is %2x at %p\n", i, *(abp+i), abp+i);
    }