#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head;

int choice = 0;

struct dnode
{
    struct dnode* prev;
    int data;
    struct dnode* next;
}*dhead;


void createlist(int number)
{
    if(choice == 1)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = 1;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        
        struct node* temp = head;
        
        for(int i = 2; i <= number; i++)
        {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = i;
            newnode->next = NULL;
            
            temp->next = newnode;
            temp = temp->next;
        }
    }
    
    if(choice == 2)
    {
        struct dnode* dnewnode = (struct dnode*)malloc(sizeof(struct dnode));
        dnewnode->prev = NULL;
        dnewnode->data = 1;
        dnewnode->next = NULL;
        if(dhead == NULL)
        {
            dhead = dnewnode;
        }
        
        struct dnode* temp = dhead;
        
        for(int i = 2; i <= number; i++)
        {
            struct dnode* dnewnode = (struct dnode*)malloc(sizeof(struct dnode));
            dnewnode->prev = temp;
            dnewnode->data = i;
            dnewnode->next = NULL;
            
            temp->next = dnewnode;
            temp = temp->next;
        }
    }
}
void reverselist(void)
{
    if(choice == 1)
    {
        if(head == NULL)
        {
            printf("no data to reverse\n");
            exit(0);
        }
    
        struct node* temp = head;
        struct node* prev = NULL;
        struct node* curr = NULL;
    
        while(temp!= NULL)
        {
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
    
        temp = prev;
        
        head = temp;
    }
    
    if(choice == 2)
    {
        if(dhead == NULL)
        {
            printf("no data to reverse\n");
            exit(0);
        }
        
        struct dnode* temp = dhead;
        struct dnode* current = NULL;
        while(temp != NULL)
        {
            current = temp->prev;
            temp->prev = temp->next;
            temp->next = current;
            temp = temp->prev;
        }
        
        dhead = current->prev;
    }
}

void printlist(void)
{
    if(choice == 1)
    {
        if(head == NULL)
        {
            printf("singly : no data to print\n");
            exit(0);
        }
    
        struct node* temp = head;
    
        printf("list: \n");
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            printf("next : %p\n",temp->next);
            temp = temp->next;
        }
        printf("\n");
    }
    
    if(choice == 2)
    {
        if(dhead == NULL)
        {
            printf("no data to print\n");
            exit(0);
        }
    
        struct dnode* temp = dhead;
    
        printf("list: \n");
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            printf("prev : %p\t next : %p\n",temp->prev, temp->next);
            temp = temp->next;
        }
        printf("\n");
        
    }

}


void deletelist(void)
{
    if(choice == 1)
    {
        struct node* temp = head;
        
        while(temp != NULL)
        {
            head = head->next;
            free(temp);
            temp = head;
        }
        temp = NULL;
    }
    
    if(choice == 2)
    {
        struct dnode* dtemp = dhead;
        
        while(dtemp != NULL)
        {
            dhead = dhead->next;
            free(dtemp);
            dtemp = dhead;
        }
        dtemp = NULL;
    }
}

int main(int argc, char** argv)
{
    // struct node* head = (struct node*)malloc(sizeof(struct node));
    // struct dnode* dhead = (struct dnode*)malloc(sizeof(struct dnode));
    // head = NULL;
    // dhead = NULL;
    
    int number = 10;
    
    while(1)
    {
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                createlist(number);
                reverselist();
                printlist();
                choice = 0;
                break;
            case 2:
                createlist(number);
                reverselist();
                printlist();
                choice = 0;
                break;
            case 3:
                deletelist();
                head = NULL;
                dhead = NULL;
                printf("List deleted\n");
                choice = 0;
                break;
            default:
                printf("Enter either 1 or 2\n");
                choice = 0;
                break;
        }
    }
}
