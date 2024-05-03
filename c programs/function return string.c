#include<stdio.h>
#include<stdint.h>


char *strfunc(char * input)
{
    char* str = malloc(sizeof(char));
    strcat(str, "sample ");
    strcat(str, input);
    return str;
}

int main()
{
    char *str = "hello world";
    char *res = strfunc(str);
    
    printf("%s",res);
}

#if 0

#include<stdio.h>

char* funcstr(char* str)
{
    printf("Enter string : ");
    scanf("%s",str);
    return str;
}

int main()
{
    char* str = malloc(100* sizeof(char));
    str = funcstr(str);
    printf("str : %s",str);
}

#endif