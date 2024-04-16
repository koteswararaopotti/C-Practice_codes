#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*top = NULL;

int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
void push(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    if(newnode == NULL)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;

    newnode->next = top;
    top = newnode;
}
int pop(void)
{
    // if(top == -1);
    if(isEmpty())
    {
        printf("stack underflow\n");
        return 0;
    }
    
    struct node* popnode = top;
    top = top->next;
    int popped_data = popnode->data;
    // printf("Popped data = %d",popped_data);
    free(popnode);
    popnode = NULL;
    
    return popped_data;
}
int peek(void)
{
    if(isEmpty())
    {
        printf("stack underflow\n");
        return 0;
    }
    return top->data;
}
void print(void)
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("stacklist : ");
    struct node* temp = top;
    while(temp != NULL)
    {
        printf("%d -->",temp->data);
        // printf("next : %p \n",head->next);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
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
                printf((!ret) ?"stack is not empty\n":"stack is empty\n");
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