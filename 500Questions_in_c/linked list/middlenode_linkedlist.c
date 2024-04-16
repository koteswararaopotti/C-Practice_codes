#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insertnode_end(struct node* head, int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    struct node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
    
    return head;
}

struct node* createlist(struct node* head, int size)
{
    for(int i = 1; i <= size; i++)
    {
        head = insertnode_end(head, i);
    }
    
    return head;
}

struct node* insertnode_aftermiddlenode(struct node* head, int newnodedata, int size)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newnodedata;
    newnode->next = NULL;

    if(head == NULL)
    {
        printf("no node created, adding node as default\n");
        head = newnode;
        return head;
    }
    
    struct node* temp = head;
    for(int i = 1; i < size/2; i++)
    {
        temp = temp->next;
    }
    
    struct node* temp1 = temp->next;
    temp->next = newnode;
    newnode->next = temp1;
    
    return head;
}

void printlist(struct node* head)
{
    if(head == NULL)
    {
        printf("No data to print\n");
        exit(0);
    }
    
    struct node* temp = head;
    
    printf("List : ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int nodesize;
    int middlenodedata;
    printf("Enter size of the node : ");
    scanf("%d", &nodesize);
    
    printf("Enter the data to be inserted after middle node : ");
    scanf("%d",&middlenodedata);
    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    
    head = createlist(head, nodesize);
    
    printlist(head);
    
    head = insertnode_aftermiddlenode(head, middlenodedata, nodesize);
    
    printf("after inserting node after middle node, ");
    
    printlist(head);
    
    
}
