#include<stdio.h>

int main()
{
    int number = 0x1234; // 0x0001 0010 0011 0100
    int pos = 5;
    
    number = number >>pos;
    
    number = (number & 0x0f);
    
    printf("%x",number);
}
