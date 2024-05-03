#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* stringreverse(char* str)
{
    // int len = strlen(str);
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }
    char temp;
    for(int i = 0; i< len/2; i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    
    return str;
}

int main()
{
    char str[] = "string";
    /*
    char* str = "string";// is also correct, but it is read only
    // if we try to modify str, it gives segmentation fault.
    */
    char* rev = stringreverse(str);
    
    printf("reversed string : %s",str);
}