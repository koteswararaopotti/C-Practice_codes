#include<stdio.h>
#include<stdlib.h>


int main()
{
    int rows, columns, i,j, number = 1;
    printf("Enter rows and columns : ");
    scanf("%d %d",&rows, &columns);
    
    int** arr;
    arr = (int** )malloc(rows * sizeof(int*));
    
    for( i = 0; i < rows; i++)
    {
        *(arr+i) = (int*)malloc(columns*sizeof(int));
    }
    
    for(i = 0; i < rows;i++)
    {
        for(j = 0; j < columns; j++,number++)
        {
            *(*(arr+i)+j) = number;
        }
    }
    
    printf("2d array is : \n");
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("%d\t",*(*(arr+i)+j));
        }
        printf("\n");
    }
    
}
