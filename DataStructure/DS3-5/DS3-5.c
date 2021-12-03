#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}list_node;
typedef list_node * list_pointer;
list_pointer head,current,previous;
void initialize()
{
    head=(list_pointer)malloc(sizeof(list_node));
    head->next=NULL;
}
void traverse()
{
    if(head->next==NULL){printf("empty\n");}
    else
    {
        current=head->next;
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current=current->next;
        }
        printf("\n");
    }
}
void insert(int value)
{
    list_pointer ptr;
    ptr=(list_pointer)malloc(sizeof(list_node));
    ptr->data=value;
    previous=head;
    current=head->next;
    while((current!=NULL) && (current->data<ptr->data))
    { //sort from small to big
        previous=current;
        current=current->next;
    }
    previous->next=ptr; //insert between two nodes
    ptr->next=current;
}
void delete(int value)
{
    if(head->next==NULL){printf("empty\n");}
    else
    {
        previous=head;
        current=head->next;
        while((current!=NULL) && (current->data!=value))
        { //find out the corresponding value
            previous=current;
            current=current->next;
        }
        if(current!=NULL)
        {
            previous->next=current->next;
            free(current); //delete target node
        }
        else{printf("can't find out this value\n");}
    }
}
int list_length()
{
    int length=0;
    current=head->next;
    while(current!=NULL)
    {
        length++;
        current=current->next;
    }
    return length;
}
void invert()
{
    if(head->next==NULL){printf("empty\n");}
    else
    {
        list_pointer tmp;
        previous=NULL;
        current=NULL;
        tmp=head->next;
        while(tmp!=NULL)
        {
            previous=current;
            current=tmp;
            tmp=tmp->next;
            current->next=previous;
        }
        head->next=current;
    }
}
void concate(list_pointer A, list_pointer B)
{
    list_pointer ptr=A;
    while(ptr->next!=NULL){ptr=ptr->next;}
    ptr->next=B->next;
    free(B);
}

//-------------------------------------------------------------------------

typedef struct dnode
{
    int data;
    struct dnode * Llink;
    struct dnode * Rlink;
}dlist_node;
typedef struct dnode * dlist_pointer;
dlist_pointer dhead,dcurrent;
void dinitialize()
{
    dhead=(dlist_pointer)malloc(sizeof(dlist_node));
    dhead->Llink=dhead; //cycled list
    dhead->Rlink=dhead;
}
void dtraverse()
{
    if(dhead->Rlink==dhead){printf("empty\n");}
    else
    {
        dcurrent=dhead->Rlink;
        while(dcurrent!=dhead)
        {
            printf("%d ",dcurrent->data);
            dcurrent=dcurrent->Rlink;
        }
        printf("\n");
    }
}
void dinsert(int value)
{
    dlist_pointer ptr;
    ptr=(dlist_pointer)malloc(sizeof(dlist_node));
    ptr->data=value;
    dcurrent=dhead->Rlink;
    while((dcurrent!=dhead) && (dcurrent->data<ptr->data))
    {dcurrent=dcurrent->Rlink;}
    ptr->Llink=dcurrent->Llink;
    ptr->Rlink=dcurrent;
    dcurrent->Llink=ptr;
    ptr->Llink->Rlink=ptr;
}
void ddelete(int value)
{
    if(dhead->Rlink==dhead){printf("empty");}
    else
    {
        dcurrent=dhead->Rlink;
        while((dcurrent!=dhead) && (dcurrent->data!=value))
        {dcurrent=dcurrent->Rlink;}
        if(dcurrent!=dhead)
        {
            dcurrent->Llink->Rlink=dcurrent->Rlink;
            dcurrent->Rlink->Llink=dcurrent->Llink;
            free(dcurrent);
        }
        else{printf("can't find out the value\n");}
    }
}

//-------------------------------------------------------------------------

typedef struct stk
{
    char data[5];
    int top;
}stack;
int isFull(stack *S)
{
    if(S->top==4) return 1;
    else return 0;
}
int isEmpty(stack *S)
{
    if(S->top==-1) return 1;
    else return 0;
}
void push(stack *S,char value)
{
    if(isFull(S)) printf("stack is full.\n");
    else S->data[++S->top]=value;
}
void pop(stack *S)
{
    if(isEmpty(S)) printf("stack is empty.\n");
    else printf("%c \n",S->data[S->top--]);
}

list_pointer shead,scurrent;
void sinitialize()
{
    shead=(list_pointer)malloc(sizeof(list_node));
    shead->next=NULL;
}
void spush(int value)
{
    list_pointer ptr;
    ptr=(list_pointer)malloc(sizeof(list_node));
    if(ptr==NULL){printf("memory setting fail\n");}
    else
    {
        ptr->data=value;
        ptr->next=shead->next;
        shead->next=ptr;
    }
}
void spop()
{
    scurrent=shead->next;
    if(scurrent==NULL){printf("empty\n");}
    else
    {
        printf("%d \n",scurrent->data);
        shead->next=scurrent->next;
        free(scurrent);
    }
}

/*
infix(a+b), prefix(+ab), postfix(ab+);infix method is not efficient
*/
/*
data parsing, reversing, backtracking(enter/exit system)
*/
/*
system stack is a structure of process for function call.
it includes return address, pointer, local variable.
if no other function call, there is only main func in system stack.
if there are other function call, they would be stacked on top.
*/
/*
belong to LIFO(last in first out)
*/

//-------------------------------------------------------------------------

/*
queue has front and back
enqueue from the back of queue
dequeue from the front of queue
belong to FIFO(first in first out)
using in job scheduling
*/
typedef struct que
{
    char data[6];
    int front;
    int back;
}queue;
queue Q;
Q.front=-1;
Q.back=-1;
void enqueue(queue * Q, char value)
{
    if(Q->back==5){printf("is full\n");}
    else{Q->data[++Q->back]=value;}
}
void dequeue(queue * Q)
{
    if(Q->front==Q->back){printf("is empty\n");}
    else{printf("%c\n",Q->data[++Q->front]);}
}

//-------------------------------------------------------------------------

int main()
{
    initialize();
    traverse();
    insert(30);
    insert(20);
    insert(80);
    insert(50);
    traverse();
    delete(25);
    delete(50);
    traverse();
    printf("the list have %d nodes\n",list_length());
    invert();
    traverse();

    dinitialize();
    dtraverse();
    dinsert(27);
    dinsert(57);
    dinsert(37);
    dtraverse();
    ddelete(17);
    ddelete(27);
    dtraverse();

    return 0;
}