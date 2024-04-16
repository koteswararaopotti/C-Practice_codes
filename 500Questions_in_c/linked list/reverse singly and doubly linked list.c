#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};


struct node* createsinglelist(struct node* head)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 1;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    
    struct node* temp = head;
    
    for(int i = 2; i<=10; i++)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
    }
    
    return head;
}

struct node* reversesinglelist(struct node* head)
{
    if(head == NULL)
    {
        printf("no data to reverse\n");
        exit(0);
    }
    
    struct node* temp = head;
    struct node* prev = NULL;
    struct node* curr = head;
    
    while(temp != NULL)
    {
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    
    temp = prev;
    
    return temp;
}

void printsinglelist(struct node* head)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        return;
    }
    
    struct node* temp = head;
    printf("list : ");
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        // printf("next : %p\n",temp->next);
        temp = temp->next;
    }
    printf("\n");
}

void singlelinkedlist(void)
{
    int single;
    printf("\n1. print singly linked list\n2. create singly linked list\n3.reverse singly linked list\n4. exit\n"); 
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    while(1)
    {
        printf("\nenter choice\n");
        scanf("%d",&single);
        switch(single)
        {
            case 1:
                printsinglelist(head);
                break;
            case 2:
                head = createsinglelist(head);
                printf("list created\n");
                break;
            case 3:
                head = reversesinglelist(head);
                printf("after reversing\n");
                printsinglelist(head);
                break;
            case 4:
                return;
            default:
                printf("entered choice is wrong");
        }
    }
}


struct Node* createdoublylist(struct Node* head)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = 1;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    if(head == NULL)
    {
        head = newnode;
    }
    
    struct Node* temp = head;
    
    for(int i = 2; i<=10; i++)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;
        newnode->prev = NULL;
        
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
    
    return head;
}

struct Node* reversedoublylist(struct Node* head)
{
    if(head == NULL)
    {
        printf("no data to reverse\n");
        exit(0);
    }
    
    struct Node* temp = head;
    struct Node* curr = head;
    
    while(temp != NULL)
    {
        curr = temp->prev;
        temp->prev = temp->next;
        temp->next = curr;
        temp = temp->prev;
    }
    
    head = curr->prev;

    return head;
}

void printdoublylist(struct Node* head)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        return;
    }
    
    struct Node* temp = head;
    printf("list : ");
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        // printf("prev : %p and next : %p\n",temp->prev, temp->next);
        temp = temp->next;
    }
    printf("\n");
}

void doublylinkedlist()
{
    int doubly;
    printf("\n1. print doubly linked list\n2. create doubly linked list\n3. reverse doubly linked list\n4. exit\n"); 
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    while(1)
    {
        printf("\nenter choice\n");
        scanf("%d",&doubly);
        switch(doubly)
        {
            case 1:
                printdoublylist(head);
                break;
            case 2:
                head = createdoublylist(head);
                printf("list created\n");
                break;
            case 3:
                head = reversedoublylist(head);
                printf("after reversing\n");
                printdoublylist(head);
                break;
            case 4:
                return;
            default:
                printf("entered choice is wrong");
        }
    }
}

int main()
{
    int number;
    
    while(1)
    {
        printf("\nenter number for \n1. singly linked list reverse\n2. doubly linked list reverse\n3. exit \n");
        scanf("%d",&number);
    
        switch(number)
        {
            case 1:
                singlelinkedlist();
                break;
            case 2:
                doublylinkedlist();
                break;
            case 3:
                exit(0);
            default:
                printf("enter either 1 or 2\n");
                break;
        }
    }
}