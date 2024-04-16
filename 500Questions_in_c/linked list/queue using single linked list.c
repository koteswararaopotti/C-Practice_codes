#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*rear, *front = NULL;

int isEmpty(void)
{
    if(front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(newnode));
    newnode->data = data;
    newnode->next = NULL;
    
    if(isEmpty())
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue(void)
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        return 0;
    }
    
    int data = front->data;
    struct node* temp = front;
    front = front->next;
    free(temp);
    temp = NULL;
    
    return data;
}

int peek()
{
    return front->data;
}

void printqueue()
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        return;
    }
    
    struct node* temp = front;
    printf("queue : ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("queue using linked list, please enter below operations for different queue operations\n");
    int choice, data;
    while(1)
    {
        printf("\n0. exit\n1. is queue empty\n2. add data to queue(enqueue).\n3. remove data from queue(dequeue)\n4. peek\n5. print queue data\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("exiting\n");
                exit(2);
            case 1:
                int ret = isEmpty();
                printf((ret) ?"queue is empty\n":"queue is not empty\n");
                break;
            case 2:
                printf("enter the data to be pushed into queue : ");
                scanf("%d",&data);
                enqueue(data);
                printf("data pushed\n");
                break;
            case 3:
                int value = dequeue();
                if(value != 0)
                    printf("Popped data = %d",value);
                break;
            case 4:
                printf("topmost element in queue is : %d\n",peek());
                break;
            case 5:
                printqueue();
                break;
            default : 
                printf("wrong option\n");
                break;
        }
    }
}