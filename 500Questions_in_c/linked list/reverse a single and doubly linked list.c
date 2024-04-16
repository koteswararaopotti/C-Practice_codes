#include<stdio.h>
#include<stdlib.h>

typedef struct node_s
{
    int data;
    struct node_s* next; 
}single;

typedef struct node_d
{
    struct node_d* prev;
    int data;
    struct node_d* next;
}doubly;

/*
**********************************singly linked list********************************
*/

single* createlist_single(single* head, int num_nodes)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        head = (single*)malloc(sizeof(single));
    }
    
    head->data = 1;
    head->next = NULL;
    
    single* temp = head;
    for(int i = 2; i<= num_nodes; i++)
    {
        single* newnode = (single*)malloc(sizeof(single));
        newnode->data = i;
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
    }
    
    return head;
}

single* reverselist_single(single* head)
{
    if(head == NULL)
    {
        printf("mem not allocated, no data to reverse");
        exit(0);
    }
    
    single* temp = head;
    single* prev = NULL;
    single* current = NULL;
    
    while(temp != NULL)
    {
        current = temp->next;
        temp->next = prev;
        prev = temp;
        temp = current;
    }
    head = prev;
    
    return head;
}

void display_single(single* head)
{
    if(head == NULL)
    {
        printf("mem not allocated, no data to print");
        exit(1);
    }
    
    printf("list : ");
    
    while(head != NULL)
    {
        printf("%d ",head->data);
        printf("next addr ; %p\n",head->next);
        head = head->next;
    }
}

void singlylinkedlist(void)
{
    int n = 10;
    single* head = (single*)malloc(sizeof(single));
    head = createlist_single(head, n);
    display_single(head);
    
    head = reverselist_single(head);
    printf("\nafter reversing ");
    display_single(head);
}

/*
**********************************doubly linked list********************************
*/

doubly* createlist_double(doubly* head,int num_nodes)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        head =(doubly*)malloc(sizeof(doubly));
    }
    
    head->prev = NULL;
    head->data = 1;
    head->next = NULL;
    
    doubly* temp = head;
    
    for(int i = 2; i<=num_nodes; i++)
    {
        doubly* newnode = (doubly*)malloc(sizeof(doubly));
        newnode->prev = temp;
        newnode->data = i;
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
    }
    
    return head;
}

doubly* reverselist_double(doubly* head)
{
    if(head == NULL)
    {
        printf("mem not allocated, no data to reverse");
        exit(0);
    }
    
    doubly* temp = head;
    doubly* current = NULL;
    
    while(temp != NULL)
    {
        current = temp->prev;
        temp->prev = temp->next;
        temp->next = current;
        temp = temp->prev;
    }
    head = current->prev;
    
    return head;
}

void display_double(doubly* head)
{
    if(head == NULL)
    {
        printf("mem not allocated, no data to print");
        exit(0);
    }
    printf("List : \n");
    while(head != NULL)
    {
        printf("%d ",head->data);
        printf("prev : %p and next : %p\n",head->prev, head->next);
        head = head->next;
    }
    printf("\n");
}

void doublylinkedlist(void)
{
    int n = 10;
    doubly* head = (doubly*)malloc(sizeof(single));
    head = createlist_double(head, n);
    display_double(head);
    
    head = reverselist_double(head);
    printf("\nafter reversing ");
    display_double(head);

}

int main(int argc, char* argv[])
{
    int n;
    printf("enter 1: singly linked list\n\t2: doubly linked list\n");
    scanf("%d",&n);
    
    switch(n)
    {
        case 1:
            singlylinkedlist();
            break;
        case 2:
            doublylinkedlist();
            break;
        default:
            printf("enter either 1 or 2\n");
            break;
    }
    
    return 0;
}