#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void isPalindrome(char str[])
{
    int len = strlen(str);
    int temp;
    char arr[len];
    if(len == 1 || len == 2)
    {
        printf("[%s] is palindrome \n",str);
        return;
    }

    strcpy(arr, str);
    for(int i = 0; i < len/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = temp;
    }
    // printf("%s, %d\n",arr, strlen(arr));
    // printf("%s, %d\n",str,strlen(str));
    if(strcmp(str, arr) == 0)
    {
        printf("[%s] is palindrome\n", str);
    }
    else
    {
        printf("[%s] is not palindrome \n",str);
    }
}


int main()
{
    isPalindrome("avon sees nova"); 
    isPalindrome("a"); 
    isPalindrome("avon sies nova"); 
    isPalindrome("aa"); 
    isPalindrome("abc"); 
    isPalindrome("aba"); 
    isPalindrome("3a2");
}