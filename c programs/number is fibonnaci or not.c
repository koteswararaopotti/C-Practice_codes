#include<stdio.h>


int fibonnaci(int number)
{
    int prev = 1; 
    int prev1 = 0;
    
    if(number == prev)
    {
        return prev;
    }
    if(number == prev1)
    {
        return prev1;
    }
    int fib;
    
    for(int i = 1; i<= 100; i++)
    {
        fib =  prev1 + prev;
        prev1 = prev;
        prev = fib;
        if(number == fib)
        {
            return fib;
        }
    }
    
    return -1;
}

int main()
{
    int number = 55;
    int ret = fibonnaci(number);
    if(ret == -1)
    {
        printf("%d is not fibonacci number\n",number);
    }
    
    if(ret >= 0)
    {
        printf("%d is fibonacci number\n",number);
    }
}