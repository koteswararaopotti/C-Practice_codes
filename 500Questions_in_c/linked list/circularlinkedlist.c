#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist* next;
}node;

node* createlist(node* head, int number)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = 1;
    newnode->next = NULL;
    
    if(head == NULL)
    {
        head = newnode;
    }
    
    node* temp = head;
    node* first = head;
    int i = 2;
    while(i <= 10)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = i;
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
        i++;
    }
    temp->next = head;
    temp = temp->next;
    
    return head;
    
}


void printlist(node* head, int len)
{
    node* temp = head;
    
    printf("List : \n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d  and its address : %p",temp->data, &(temp->data));
        printf("\t next : %p \n", temp->next);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    
    int number = 10;
    
    head = createlist(head, number);
    
    printlist(head, number);
}
