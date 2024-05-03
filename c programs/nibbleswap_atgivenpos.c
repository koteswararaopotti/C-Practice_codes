#include<stdio.h>

int main()
{
    int n = 0x1111;
    
    int a = (n & 0x000f0000) >> 16;
    int b = (n & 0x0000f000) >> 12;
    
    n = (n & ~(0xf << 12)) | (a << 12);  
    n = (n & ~(0xf << 16)) | (b << 16);
    
    
    printf("%x",n);
}
