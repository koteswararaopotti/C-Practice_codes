#include<stdio.h>

// int main()
// {
//     int number = 0x12345678;
//     char* ptr = (char*)&number;
    
//     char* start = ptr;
//     char* end = ptr +sizeof(number)-1;
    
//     while(start < end)
//     {
//         char temp = *start;
//         *start = *end;
//         *end = temp;
//         *start++;
//         *end--;
//     }
    
//     printf("%x",number);
// }

// union number 
// {
//     int a;
//     char arr[4];
// };

// int main()
// {
//     union number num;
//     num.a = 0x12345678;
//     int len = sizeof(num.a);
//     for(int i = 0; i < len/2; i++)
//     {
//         char temp = num.arr[i];
//         num.arr[i] = num.arr[len - i -1];
//         num.arr[len - i - 1] = temp;
//     }
    
//     printf("%x",num.a);
// }

int main()
{
    int number = 0x12345678;
    number = ((number & 0xFF000000) >> 24) | ((number & 0x00ff0000) >> 8) | ((number & 0x0000ff00) << 8) | ((number & 0x000000ff) << 24);
    
    printf("%x",number);
}#include<stdio.h>

// int main()
// {
//     int number = 0x12345678;
//     char* ptr = (char*)&number;
    
//     char* start = ptr;
//     char* end = ptr +sizeof(number)-1;
    
//     while(start < end)
//     {
//         char temp = *start;
//         *start = *end;
//         *end = temp;
//         *start++;
//         *end--;
//     }
    
//     printf("%x",number);
// }

// union number 
// {
//     int a;
//     char arr[4];
// };

// int main()
// {
//     union number num;
//     num.a = 0x12345678;
//     int len = sizeof(num.a);
//     for(int i = 0; i < len/2; i++)
//     {
//         char temp = num.arr[i];
//         num.arr[i] = num.arr[len - i -1];
//         num.arr[len - i - 1] = temp;
//     }
    
//     printf("%x",num.a);
// }

int main()
{
    int number = 0x12345678;
    number = ((number & 0xFF000000) >> 24) | ((number & 0x00ff0000) >> 8) | ((number & 0x0000ff00) << 8) | ((number & 0x000000ff) << 24);
    
    printf("%x",number);
}
