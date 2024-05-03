#include<stdio.h>
#include<stdlib.h>

int main()
{
#if 0 // array of pointers
    int a = 10; 
    int b = 20; 
    int c = 30;
    int arr[5] = {1,2,3,4,5};
    int *ptr[5] = {&a, &b, &c, &arr[0], &arr[2]};
    
    for(int i = 0; i < 5; i++)
    {
        printf("%d ",*ptr[i]);
    }
#endif

#if 1 // pointer to array
    int arr[5] = {1,2,3,4,5};
    int (*ptr)[5] = &arr;
    
    printf("%p\n",&arr);
    
    for(int i = 0; i < 5; i++)
    {
        printf("%d ",(*ptr)[i]);
    }
    
#endif
}
