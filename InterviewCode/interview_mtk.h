//2020/02/18 聯發科
#include <math.h>

struct point
{
    int x,y;
};
struct circle
{
    int r;
    struct point center;
};
void printCircle(struct circle A)
{
    int px,py;
    int dx=A.center.x;
    int dy=A.center.y;
    for(int i=0;i<=A.r;i++)
    {
        px=i;
        py=sqrt(A.r*A.r-i*i);
        printf("%d %d\n",dx+px,dy+py);
        //printf("%d %d\n",dx+px,dy-py);
        //printf("%d %d\n",dx-px,dy-py);
        //printf("%d %d\n",dx-px,dy+py);
    }
}

/*
set Number = abcde(in binary)
abcde = abc<<2 + de
      = abc*4 + de
      = abc*3 + (abc + de)
any number can be splitted by the same way
*/    
int isMult3(unsigned int n)
{
    if( n == 0 || n == 3 )    
        return 1;
    if( n < 3 ) 
        return 0;
    
  	n = (n >> 2) + (n & 3);
    
    /* Recursive call till you get n
       or a special terminate condition */
    return (isMult3(n));
}

union udata
{
    int dataI;
    char dataC[4];
};

struct queue_m
{
    int data;
    struct queue_m* next;
    struct queue_m* prev;
};
struct queue_m* head=NULL;
int total_num=0;

double get_median(int input)
{
    struct queue_m* node=(struct queue_m*)malloc(sizeof(struct queue_m));
    node->data=input;
    node->next=NULL;
    node->prev=NULL;
    total_num++;
    if(head==NULL)
    {
        head=node;
    }
    else
    {
        struct queue_m* curr=head;
        while(curr!=NULL)
        {
            printf("%d ",curr->data);
            if(curr->data >= node->data)
            {
                node->prev=curr->prev;
                node->next=curr;
                curr->prev=node;
                if(node->prev!=NULL)
                {
                    curr=node->prev;
                    curr->next=node; 
                }
                else
                {
                    head=node;
                }
                break;
            }
            else if(curr->next==NULL)
            {
                curr->next=node;
                node->prev=curr;
                break;
            }
            else
            {
                curr=curr->next;
            }
        }
    }

    struct queue_m* curr=head;
    int index=0;
    while(index<total_num/2)
    {
        curr=curr->next;
        index++;
    }
    if(total_num%2==0)
    {
        return (curr->data + (curr->prev)->data)/2.0;
    }
    else
    {
        return (curr->data)*1.0;
    }
}

#define size_estimation(x) ((void*)((&x)+1)-(void*)(&x))
struct node_size_test
{ //it shall consider packed or unpacked
    int data;
    char index1;
    char index2;
};

struct reverse_list
{
    int data;
    struct reverse_list* next;
};

struct reverse_list* reverse_head=NULL;

void reverse_linked_list()
{
    struct reverse_list* curr=reverse_head;
    struct reverse_list* prev=NULL;

    while(curr!=NULL)
    {
        struct reverse_list* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    
    reverse_head=prev;
}
