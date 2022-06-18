
struct RQ1
{
    int data;
    struct RQ1* next;
};

struct RQ1* RQ1_head=NULL;

void insert_before_max(struct RQ1* list_node, int value)
{
    if(list_node==NULL)
    {
        struct RQ1* node=malloc(sizeof(struct RQ1));
        node->data=value;
        node->next=NULL;
        list_node=node;
    }
    else
    {
        struct RQ1* curr=list_node;
        struct RQ1* prev=NULL;
        struct RQ1* before_max_node=NULL;
        int max_data=list_node->data;

        while(list_node!=NULL)
        {
            if(curr->data>max_data)
            {
                max_data=curr->data;
                before_max_node=prev;
            }

            prev=curr;
            curr=curr->next;
        }

        if(before_max_node!=NULL)
        {
            struct RQ1* node=malloc(sizeof(struct RQ1));
            node->data=value;
            node->next=before_max_node->next;
            before_max_node->next=node;
        }
        else
        {
            struct RQ1* node=malloc(sizeof(struct RQ1));
            node->data=value;
            node->next=list_node;
            list_node=node;
        }
    }
}