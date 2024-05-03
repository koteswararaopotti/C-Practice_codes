#include<stdio.h>
#include<stdlib.h>


int factorial(int n)
{
    // if(n == 0)
    // {
    //     return 1;
    // }
    
    // return n * factorial(n-1);
    int res = 1;
    
    for(int i = n; i>=1; i--)
    {
        res = res*i;
    }
    return res;
}

int main()
{
    int n = 5;
    printf("factorial : %d",factorial(n));
}