#include<stdio.h>

long int power(int base, int expo)
{
    if(expo == 0)
    {
        return 1;
    }

    return base* power(base,expo-1);

    // int res = 1;
    // // for(int i = 1; i<=expo; i++)   
    // for(int i = expo; i>=1; i--)
    // {
    //     res = res* base;
    // }
    
    // return res;
}

int main()
{
    int base = 2;
    int expo = 10;
    
    printf("200 to power of 10 is : %ld",power(base, expo));
}

