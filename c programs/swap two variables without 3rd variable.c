#include<stdio.h>

void swap(int *x, int *y)
{
    *x = *x+*y;
    *y = *x-*y;
    *x = *x-*y;
}

int main()
{
    int a = 5; 
    int b = 10;
    
    swap(&a, &b);
    
    printf("after swapping : a = %d and b = %d",a,b);
    
}