#include<stdio.h>


int roundoff(float num)
{
    int integernum = (int)num;
    float floatnumber = num - integernum;
    
    if(floatnumber > 0.5)
    {
        return integernum + 1;
    }
    else
    {
        return integernum;
    }
}


int main()
{
    float num = 5.51;
    
    int ret = roundoff(num);
    
    printf("return number is : %d",ret);
}