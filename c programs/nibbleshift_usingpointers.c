#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int number = 0x12345678;
    char* ptr = (char*)&number;
    
    char* start = ptr;
    char* end = ptr + sizeof(int) -1;
    
    while(start < end)
    {
        *start = ((((*start) & 0x0f) << 4) | (((*start) & 0xf0) >> 4));
        *end = ((((*end) & 0x0f) << 4) | (((*end) & 0xf0) >> 4));
        char temp = *start;
        *start = *end;
        *end = temp;
        *start++;
        *end--;
    }
    
    printf("%x",number);
}
