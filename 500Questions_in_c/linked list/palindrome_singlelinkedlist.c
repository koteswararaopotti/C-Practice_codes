#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node *next;
};

struct node* createnode(struct node* head, char* str)
{
    if(head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = *str;//str[0];
    newnode->next = NULL;
    head = newnode;
    
    struct node* temp = head;
    for(int i = 1; i < strlen(str); i++)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = *(str+i);//str[i];
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

int compare(struct node* head, struct node* rhead)
{
    struct node* temp = head;
    struct node* rtemp = rhead;
    
    while(temp!= NULL)
    {
        if(temp->data != rtemp->data)
        {
            return 0;
        }
        printf("%c and %c\n",temp->data, rtemp->data);
        temp = temp->next;
        rtemp = rtemp->next;
    }
    
    return 1;
}

struct node* reverselist(struct node* head)
{
    struct node* temp = head;
    struct node* prev = NULL;
    struct node* curr = NULL;
    
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

void printlist(struct node* head)
{
    struct node* temp = head;
    while(temp!= NULL)
    {
        printf("%c",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    struct node* head = NULL;
    struct node* rhead = (struct node*)malloc(sizeof(struct node));
    char* str = "12321";
    head = createnode(head, str);
    printlist(head);
    rhead = reverselist(head);
    int res = compare(head, rhead);
    
    printlist(rhead);
    
    if(res == 0)
    {
        printf("string is not palindrome");
    }
    else
    {
        printf("string is palindrome");
    }
}
