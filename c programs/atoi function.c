#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int my_atoi(char* str)
{
    int value = 0;
    for(int i = 0; i <= strlen(str); i++)
    {
        if(str[i] == '\n' || str[i] == '\t'|| str[i] == '\0')
        {
            break;
        }
        if((str[i] >='0')&& (str[i] <='9'))
        {
            value = value* 10;
            value = value+ (str[i] - '0');
        }
        else
        {
            break;
        }
    }
    return value;
}

int main()
{
    char* str = malloc(1024*sizeof(char));
    printf("Enter string : ");
    scanf("%s",str);
    
    int ret = my_atoi(str);
    
    printf("Value is : %d\n",ret);
}