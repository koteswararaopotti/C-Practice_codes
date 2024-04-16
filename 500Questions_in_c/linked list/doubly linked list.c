#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

int count;

int randomnumber()
{
    int upper = 100;
    int lower = 0;
    int i; 

    int num = (rand() % (upper - lower + 1)) + lower; 

    return num;
}

struct node* createlist(struct node* head)
{
    if(head == NULL)
    {
        printf("memory not allocated\n");
        head = (struct node*)malloc(sizeof(struct node));
        printf("...\n");
        printf("memory allocated\n");
    }
    
    head->prev = NULL;
    head->data = 1;
    // head->data = randomnumber();
    head->next = NULL;
    
    struct node* temp = head;
    for(int i = 2; i <= 10; i++)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->prev = temp;
        newnode->data = i;
        // head->data = randomnumber();
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

struct node* insertnode_beg(struct node* head)
{
    struct node* temp = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = 11;
    newnode->next = temp;
    
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    
    temp->prev = newnode;
    
    head = newnode;
    
    return head;
}

struct node* insertnode_end(struct node* head, int data)
{
    struct node* temp = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    
    if(head == NULL)
    {
        head = newnode;
        return head;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->prev = temp;    
    
    return head;
}

struct node* insertnode_atpos(struct node* head, int pos, int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL)
    {
        printf("mem not allocated");
        exit(0);
    }
    if(pos == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return head;
    }
    
    struct node*temp = head;
    
    for(int i = 2; i<pos; i++)
    {
        temp = temp->next;
    }
    struct node* nextnode = temp->next;
    newnode->next = nextnode;
    temp->next = newnode;
    newnode->prev = temp;
    nextnode->prev = newnode;
    
    return head;
    
}

struct node* deletenode_beg(struct node* head)
{
    if(head == NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    
    struct node* temp = head;
    
    head = head->next;
    
    if(head != NULL)
        head->prev = NULL;
    free(temp);
    temp = NULL;
    return head;
}

struct node* deletenode_end(struct node* head)
{
    if(head == NULL)
    {
        printf("mem not allocated");
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    
    struct node* temp = head;
    struct node* del;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    del = temp->prev;
    del->next = NULL;
    
    free(temp);
    
    return head;
}

struct node* delnode_atpos(struct node* head, int pos)
{
    struct node* delnode;
    if(head == NULL)
    {
        printf("mem not allocated");
        exit(0);
    }
    if(pos == 1)
    {
        delnode = head;
        head = head->next;
        head->prev = NULL;
        free(delnode);
        delnode = NULL;
        return head;
    }
    
    struct node*temp = head;
    
    for(int i = 2; i<pos; i++)
    {
        temp = temp->next;
    }
    struct node* nextnodeafter = temp->next->next;
    delnode = temp->next;
    temp->next = nextnodeafter;
    nextnodeafter->prev = temp;
    free(delnode);
    delnode = NULL;
    
    return head;
}
struct node* deletelist(struct node* head)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        exit(0);
    }
    
    struct node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
    free(head);
    head = NULL;
    temp = NULL;
    return head;
}

struct node* reverselist(struct node* head)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        exit(0);
    }
    
    struct node* temp = head;
    struct node* current = NULL;
    
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

void sortlist(struct node* head)
{
    if(head == NULL || head->next == NULL)
    {
        exit(1);
    }
    
    int temp;
    struct node* current;
    struct node* currentnext;
    
    for(current = head; current!= NULL; current = current->next)
    {
        for(currentnext = current->next; currentnext!= NULL; currentnext = currentnext->next)
        {
            if(current->data < currentnext->data)
            {
                temp = current->data;
                current->data = currentnext->data;
                currentnext->data = temp;
            }
        }
    }
}

int nthnode_fromend(struct node* head, int nodeindex, int count_start)
{
    int indexfromstart = count_start - nodeindex;
    
    for(int i = 1; i <= indexfromstart; i++)
    {
        head = head->next;
    }
    
    return head->data;
    
}

void display(struct node* head)
{
    if(head == NULL)
    {
        printf("mem not allocated\n");
        exit(0);
    }
    printf("/*****************************************************/\n");
    while(head != NULL)
    {
        printf("%d ",head->data);
        // printf("prev : %p and next : %p\n",head->prev, head->next);
        head = head->next;
    }
    printf("\n");
    printf("/*****************************************************/\n");
}

struct node* appendlist(struct node* head)
{
    int nodes;
    printf("enter number of nodes : ");
    scanf("%d",&nodes);
    
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode = NULL;
    
    for(int i = 1; i<=nodes; i++)
    {
        newnode = insertnode_end(newnode);
    }
    
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
    
    printf("appended nodes ");
    display(newnode);
    
    return head;
}

int main(int argc, char* argv[])
{
    int delpos = 3;
    int pos = 9;
    int data = 21;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = createlist(head);
    printf("list : \n");
    display(head);
    
    head = insertnode_beg(head);
    printf("after insertion at beg, list : \n");
    display(head);
    
    head = insertnode_end(head,12);
    printf("after insertion at end, list : \n");
    display(head);
    
    head = deletelist(head);
    printf("After deleting list, List : \n");
    // display(head);
    if(head == NULL)
    {
         printf("/*****************************************************/\n"); 
        printf("list deleted\n");
        printf("/*****************************************************/\n");
    }
    
    head = createlist(head);
    printf("list : \n");
    display(head);
    
    head = reverselist(head);
    printf("after reversing list, list : \n");
    display(head);
    
    for(int i = 2; i <=10; i++)
    {
        head = insertnode_end(head,i);
        // head = insertnode_end(head,randomnumber());
    }
    printf("after entering newnodes at end, List : \n");
    display(head);
    
    head = deletenode_beg(head);
    printf("after deleting beginning node, List : \n");
    display(head);
    
    sortlist(head);
    printf("after sorting, List : \n");
    display(head);
    head = deletenode_end(head);
    printf("after deleting node at end, list : \n");
    display(head);
    head = insertnode_atpos(head, pos, data);
    printf("after inserting node at pos - [%d], list : \n",pos);
    display(head);
    head = delnode_atpos(head, delpos);
    printf("after delete node at pos - [%d],List : \n",delpos);
    display(head);
    
    /*
        		int n = 20;
    		int nodeindex = 5;
    
    		int nthnode_end = nthnode_fromend(head, nodeindex,count);
    
    		printf("%d index from end in linked list has [%d] \n",nodeindex, nthnode_end);
 	*/
    return 0;
}
