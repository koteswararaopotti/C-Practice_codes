#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define MAX     100

int top = -1;

int stack[MAX];

int isEmpty()
{
    if(top == -1)
    {
        return -1;
    }
}

void push(int data)
{
    if(top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top] = data;
    
    //stack[++top] = data;
}

int pop(void)
{
    if(top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    
    return stack[top--]; 
    
    // int value = stack[0];
    // for(int i = 1; i<= top; i++)
    // {
    //     stack[i-1] = stack[i];
    // }
    // top--;
    
    // return value;
}

int peek(void)
{
    if(isEmpty())
    {
        printf("stack is empty\n");
        return -1;
    }

    //return stack[0];
    
    return stack[top];// returning last element in stack
}


void print(void)
{
    printf("stack list : ");
    for(int i = 0; i<= top; i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\ncurrent stack size : %d\n",top);
}

int main(int argc, char** argv)
{
    printf("stack using linked list, please enter below operations for stack operations\n");
    int choice, data;
    while(1)
    {
        printf("\n0. exit\n1. is stack empty\n2. push data to stack\n3. pop data from stack\n4. peek\n5. print stack data\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("exiting\n");
                exit(2);
            case 1:
                int ret = isEmpty();
                printf((ret > 0) ?"stack is not empty\n":"stack is empty\n");
                break;
            case 2:
                printf("enter the data to be pushed into stack : ");
                scanf("%d",&data);
                push(data);
                printf("data pushed\n");
                break;
            case 3:
                int value = pop();
                if(value != 0)
                    printf("Popped data = %d",value);
                break;
            case 4:
                printf("topmost element in stack is : %d\n",peek());
                break;
            case 5:
                print();
                break;
            default : 
                printf("wrong option\n");
                break;
        }
    }
}
