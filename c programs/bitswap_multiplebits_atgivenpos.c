#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number = 0x1234;
    
    int a = ((number >> 2) & 0x7);//after bit pos 2
    int b = ((number >> 8) & 0x7);// after bit pos 8
    
    number = number & ~(0x7 << 2);//clearing bit after 2 pos (clearing 3 pos) 
    number = number & ~(0x7 << 8);
    
    printf("number : %x\n",number);
    
    number = number | (a << 8);
    number = number | (b << 2);
    
    printf("number : %x",number);
}
