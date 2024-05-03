#include<stdio.h>
#include<stdint.h>

#define max(x,y)        (x>y) ? x:y
#define max3(x,y,z)     (x>y && x>z) ? x : (y>z) ? y : z
#define max4(x,y,z,q)   max((max(x,y)), (max(z,q)))

int main()
{
    int a = 84;
    int b = 154;
    int c = 53;
    int d = 215;
    
    printf("max of a,b : %d\n",max(a,b));
    printf("max of a,b,c : %d\n",max3(a,b,c));
    printf("max of a,b,c,d : %d\n",max4(a,b,c,d));
    
    return 0;
}