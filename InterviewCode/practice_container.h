struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
struct Node * top=NULL; 
struct Node * tail=NULL; 
struct Node * head=NULL; 
int stack_isEmpty() 
{ 
    if(top==NULL){return 1;} 
    else{return 0;} 
}
void push_stack(int data) 
{ 
    struct Node * new_add_node; //setup node in heap memory
    new_add_node=(struct Node*)malloc(sizeof(struct Node)); 
    new_add_node->data=data;
    new_add_node->next=top; //point to the older node for stack  
    top=new_add_node;
}
int pop_stack() 
{ 
    struct Node * ptr; 
    int temp; 
    if(stack_isEmpty()) 
    { 
        printf("堆疊為空\n"); 
        return -1; 
    } 
    else
    { 
        ptr=top; //retrieve node in heap memory
        temp=top->data;
        top=top->next; //point to the older node for stack 
        free(ptr);
        return temp; 
    } 
} 
//-----------------------------------------------------------
struct Node * front;
struct Node * back;
void createqueue()
{ 
    front = back = (struct Node *)malloc(sizeof(struct Node)); 
    front->next = back->next = NULL; 
}  
void showfront()
{ 
    if(front->next == NULL) 
        printf("\n queue is empty"); 
    else 
        printf("\n data from front:%d", front->next->data); 
} 
void showback()
{
    if(front->next == NULL) 
        printf("\n queue is empty"); 
    else 
        printf("\n data from back:%d", back->data); 
}
void enqueue(int data)
{ 
    struct Node * newnode; 
    newnode=(struct Node*)malloc(sizeof(struct Node)); 
    if(front->next == NULL)  
        front->next=newnode; 
    newnode->data=data; 
    newnode->next=NULL; 
    back->next=newnode; 
    back=newnode; 
}  
void dequeue()
{ 
    struct Node * tmpnode; 
    if(front->next == NULL) 
    { 
        printf("\n queue is empty!"); 
        return; 
    } 
    tmpnode=front->next; 
    front->next=tmpnode->next; 
    free(tmpnode);    
}  
void showqueue()
{ 
    struct Node * tmpnode; 
    tmpnode=front->next; 
    if(front->next == NULL) 
    { 
        printf("\n queue is empty!"); 
        return; 
    }
    printf("\n content in queue:"); 
    while(tmpnode != NULL) 
    { 
        printf("%d ", tmpnode->data); 
        tmpnode=tmpnode->next; 
    }
    free(tmpnode); 
}  
//-----------------------------------------------------------