#include<stdio.h>
#include<stdint.h>

int main()
{
    int number = 8;
    
    if((number & (number - 1)) == 0)
    {
        int i = 0;
        int temp = number;
        while(temp > 1) // while((temp & 1) == 0)
        {
            int zero = temp & (temp << 1); // int zero = temp & (temp - 1)
            if(!zero)
                i++;
            temp = temp >> 1;
        }
        if (i % 2 == 0)
        {
            printf("Power of 4\n");
        }
        else
        {
            printf("not power of 4\n");
        }
    }
}
