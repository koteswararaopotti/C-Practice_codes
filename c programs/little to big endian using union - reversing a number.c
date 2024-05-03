#include<stdio.h>


union endian
{
    int number;
    char numarr[4];
};

int main(int argc, char** argv)
{
    int number = 0x11223344;
    
    union endian end;
    end.number = number;
    
    int temp;
    
    temp = end.numarr[0];
    end.numarr[0] = end.numarr[3];
    end.numarr[3] = temp;
    
        temp = end.numarr[1];
    end.numarr[1] = end.numarr[2];
    end.numarr[2] = temp;
    
    printf("reversed number : 0x%8x",end.number);
}