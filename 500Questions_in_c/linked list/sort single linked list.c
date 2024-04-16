#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct node_s
{
    int data;
    struct node_s* next; 
}single;

int lengthlist(single* head)
{
    int len = 1;
    while(head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
 
int randomvalue(void)
{
    int upper = 100;
    int lower = 0;
    int i; 

    int num = (rand() % (upper - lower + 1)) + lower; 

    return num;
}

single* createlist_single(single* head, int num_nodes)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        head = (single*)malloc(sizeof(single));
    }
    
    head->data = randomvalue();
    head->next = NULL;
    
    single* temp = head;
    for(int i = 2; i<= num_nodes; i++)
    {
        single* newnode = (single*)malloc(sizeof(single));
        newnode->data = randomvalue();
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
    
    // single* temp = head;
    // single* prev = NULL;
    // single* current = NULL;
    
    // while(temp != NULL)
    // {
    //     current = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = current;
    // }
    // head = prev;
    
    // return head;
    
    single* current = head;
    single* prev = NULL;
    single* nextNode;

    // Traverse the list and swap data elements
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Update the head to point to the new first node
    head = prev;
}

void sortlist(single* head)
{
    int temp;
    if(head == NULL || head->next == NULL)
    {
        // return 0;
    }
    
    single* previous;
    single* current;
    
    for(previous = head;previous!= NULL; previous = previous->next)
    {
        for(current = previous->next; current != NULL; current = current->next)
        {
            if(previous->data > current->data)
            {
                temp = previous->data;
                previous->data = current->data;
                current->data = temp;
            }
        }
    }
    
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
        // printf("next addr ; %p\n",head->next);
        head = head->next;
    }
}

int main()
{
    int n = 10;
    single* head = (single*)malloc(sizeof(single));
    head = createlist_single(head, n);
    display_single(head);
    
    sortlist(head);
    printf("\nafter sorting ");
    display_single(head);
    
    
    head = reverselist_single(head);
    printf("\nafter reversing ");
    display_single(head);
    
    return 0;
}

