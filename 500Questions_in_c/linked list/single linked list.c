#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

//structure to define node for single linked list
struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL; //for stack 
struct node* front = NULL;// for queue
struct node* rear = NULL;//for queue

int count; // for finding nthnode from end

//random number generator from 10 to 200 numbers.
int randomnumber()
{
    int upper = 200;
    int lower = 10;
    int number;
    number = (rand() % (upper - lower + 1)) + lower;
    return number;
}

/*******************single linked list****************/

void displaylist(struct node* head)
{
    if(head == NULL)
    {
        printf("Head node is empty, nothing to display\n");
        exit(0);
    }
    printf("List : ");
    while(head != NULL)
    {
        printf("%d -->",head->data);
        // printf("next : %p \n",head->next);
        head = head->next;
    }
    printf("NULL");
    printf("\n");
}

struct node* createlist(struct node* head, int n)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = /*1;*/randomnumber();
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        count++;
    }
    
    struct node* temp = head;
    
    for(int i = 2; i<= n; i++)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = /*i;*/randomnumber();
        newnode->next = NULL;
        
        temp->next = newnode;
        temp = temp->next;
        count++;
    }
    
    return head;
}

struct node* insertnode_start(struct node* head)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = randomnumber();
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    
    struct node* temp = head;
    
    newnode->next = temp;
    head = newnode;
    
    return head;
}

struct node* insertnode_end(struct node* head)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = randomnumber();
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    
    struct node* temp = head;
    
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    
    return head;
    
    return head;
}

struct node* insertnode_atpos(struct node* head)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = randomnumber();
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    int pos;
    printf("Enter at which position node to be added: ");
    scanf("%d",&pos);
    
    struct node* temp = head;
    struct node* nextnode;
    if(pos == 1)
    {
        newnode->next = temp;
        return newnode;
    }
    for(int i = 1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    nextnode  = temp->next;
    temp->next = newnode;
    newnode->next = nextnode;
    
    return head;
}

struct node* deletenode_start(struct node* head)
{
    if(head == NULL)
    {
        printf("Head node is empty, nothing to delete\n");
        exit(0);
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    
    struct node* temp = head;
    struct node* delnode = temp;
    
    temp = temp->next;
    free(delnode);
    delnode = NULL;
    
    head = temp;
    return head;
}

struct node* deletenode_end(struct node* head)
{
    if(head == NULL)
    {
        printf("Head node is empty, nothing to delete\n");
        exit(0);
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    struct node* temp = head;
    struct node* previous = NULL;
    struct node* delnode = NULL;
    while(temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    
    previous->next = NULL;
    delnode = temp;
    free(temp);
    temp = NULL;
    
    return head;
}

struct node* deletenode_atpos(struct node* head)
{
    if(head == NULL)
    {
        printf("Head node is empty, nothing to delete\n");
        exit(0);
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    
    int pos;
    printf("Enter at which position node to be deleted: ");
    scanf("%d",&pos);
    
    struct node* temp = head;
    struct node* delnode;
    if(pos == 1)
    {
        delnode = temp;
        temp = temp->next;
        free(delnode);
        delnode = NULL;
        return temp;
    }
    struct node* prevnode;
    for(int i = 1; i<pos; i++)
    {
        prevnode = temp;
        temp = temp->next;
    }
    delnode = temp;
    prevnode->next = temp->next;
    free(delnode);
    delnode = NULL;
      
    return head; 
}

struct node* deletelist(struct node* head)
{
    if(head == NULL)
    {
        printf("list already deleted or memory not allocated\n");
        exit(0);
    }
    
    struct node* temp = head;
    
    while(head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    temp = NULL;
    
    return head;
}

struct node* reverselist(struct node* head)
{
    if(head == NULL)
    {
        printf("Head node is empty, no data to reverse\n");
        exit(0);
    }
    
    struct node* temp = head;
    struct node* prev = NULL;
    struct node* current = NULL;
    
    while(temp != NULL)
    {
        current = temp->next;
        temp->next = prev;
        prev = temp;
        temp = current;
    }
    temp = prev;
    
    return temp;
}

void sortlist(struct node* head)
{
    if(head == NULL)
    {
        printf("Head node is empty, no data to sort\n");
        exit(0);
    }
    
    struct node* current;
    struct node* nextnode;
    int temp;
    
    for(current = head; current != NULL; current = current->next)
    {
        for(nextnode = current->next; nextnode != NULL; nextnode = nextnode->next)
        {
            if(current->data > nextnode->data)
            {
                temp = current->data;
                current->data = nextnode->data;
                nextnode->data = temp;
            }
        }
    }
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
    	printf("Head node is empty, head will point to new data\n");
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
    displaylist(newnode);
    
    return head;
}

struct node* copylist(struct node* head, struct node* newhead)
{
    if(head == NULL)
    {
        printf("Head node is empty, no data to be copied");
        exit(0);
    }
    
    struct node* tail = NULL;
    
    while(head != NULL)
    {
        if(newhead == NULL)
        {
            newhead = head;
            tail = head;
        }
        else
        {
            tail = tail->next;
            tail->data = head->data;
        }
        head = head->next;
    }
    
    return newhead;
}


int nthnode_fromend(struct node* head, int nodeindex, int count_start)
{
    if(head == NULL)
    {
    	printf("Head node is empty\n");
    	exit(0);
    }
    
    int indexfromstart = count_start - nodeindex;
    
    for(int i = 1; i <= indexfromstart; i++)
    {
        head = head->next;
    }
    
    return head->data;
    
}

void middlenode(struct node* head)
{
    struct node* fast = head;
    struct node* slow = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    printf("middle node : %d\n",slow->data);
}

/*****************Stack using linked list****************/

int isStackEmpty()
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
    if(isStackEmpty())
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
int peekStack(void)
{
    if(isStackEmpty())
    {
        printf("stack underflow\n");
        return 0;
    }
    return top->data;
}
void printStack(void)
{
    if(isStackEmpty())
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

void stack_linkedlist(void)
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
                exit(2);
            case 1:
                int ret = isStackEmpty();
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
                printf("topmost element in stack is : %d\n",peekStack());
                break;
            case 5:
                printStack();
                break;
            default : 
                printf("wrong option\n");
                break;
        }
    }
}

/*************************queue linked list*****************/
int isqueueEmpty(void)
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
    
    if(isqueueEmpty())
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
    if(isqueueEmpty())
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

int peekqueue()
{
    return front->data;
}

void printqueue()
{
    if(isqueueEmpty())
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

int queue_linkedlist()
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
                int ret = isqueueEmpty();
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
                printf("topmost element in queue is : %d\n",peekqueue());
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

static inline void Enterchoice(void)
{
	printf("Enter 1 through 11 to select one linked list operation\n1. create linked list\n2. insert node at start of linked list\n3. insert node at end of linked list\n4. insert node at given position of linked list\n5. delete node at start of linked list\n6. delete node at end of linked list\n7. delete node at given position of linked list\n8. delete entire linked list\n9. reverse entire list\n10. sort linked list (ascending order)\n11. display entire list\n12. append list to current list\n13. create stack using linked list\n14. create queue using linked list\n15. copy entire linked list\n16. find given node from end of linked list\n17. find middle node in linked list\n");
    
}

int main(int argc, char* argv[])
{
    int serial;
    int run = 1;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    struct node* newhead = (struct node*)malloc(sizeof(struct node));
    newhead = NULL;
    
    Enterchoice();
    
    while(run)
    {
        printf("\nenter number : ");
        scanf("%d",&serial);
        switch(serial)
        {
            case 1:
                int number;
                printf("Enter number of elements to be entered : ");
                scanf("%d",&number);
                head = createlist(head, number);
                printf("List created\n");
                break;
            case 2:
                head = insertnode_start(head);
                printf("node inserted at start\n");
                break;
            case 3:
                head = insertnode_end(head);
                printf("node inserted at end\n");
                break;
            case 4:
                head = insertnode_atpos(head);
                printf("node inserted at given position\n");
                break;
            case 5:
                head = deletenode_start(head);
                printf("node deleted at start\n");
                break;
            case 6:
                head = deletenode_end(head);
                printf("node deleted at end\n");
                break;
            case 7:
                head = deletenode_atpos(head);
                printf("node deleted at given position\n");
                break;
            case 8:
                head = deletelist(head);
                printf("List deleted\n");
                break;
            case 9:
                head = reverselist(head);
                printf("List reversed\n");
                break;
            case 10:
                sortlist(head);
                printf("List sorted\n");
                break;
            case 11:
                displaylist(head);
                break;
            case 12:
                head = appendlist(head);
                printf("List appended\n");
                break;
            case 13:
                stack_linkedlist();
                break;
            case 14: 
                queue_linkedlist();
                break;
            case 15:
                newhead = copylist(head, newhead);
                printf("new list copied : ");
                displaylist(newhead);
                break;
            case 16:
    		    int n = 20;
    		    int nodeindex;
    		    printf("enter the index of the node from end you want to enter:");
    		    scanf("%d",&nodeindex);
    
    		    int nthnode_end = nthnode_fromend(head, nodeindex,count);
    
    		    printf("%d index from end in linked list has [%d] \n",nodeindex, nthnode_end);
    		case 17:
    		    middlenode(head);
    		    break;
            default:
                printf("please enter between 1 to 17\n");
                run = 0;
                break;
        }    
    }
    
    return 0;
}
