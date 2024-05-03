#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

union num
{
    uint32_t number;
    uint8_t a[4];
};

int main()
{
    union num arr;
    int number = 0x11223344;
    arr.number = number;
    
    if(arr.a[4] == 0x11)
    {
        printf("litle endian");
    }
    else
    {
        printf("big endian\n");
        printf("%x ",arr.a[4]);
    }
    
    int reverse = 0;
    
    for(int i = 0; i < 4; i++)
    {
        reverse = (reverse << 8) | arr.a[i];
    }
    
    printf("reverse number : 0x%x",reverse);
}

