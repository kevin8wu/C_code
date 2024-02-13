#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define METHOD1

#if defined(METHOD1)
struct node
{
    char data;
    struct node* next;
};

struct list
{
    struct node* node_head;
    struct node* node_tail;
    struct list* next;
    struct list* prev;
};

char* convert(char* s, int numRows)
{
    //determine for special conditions
    if(s==NULL){return s;}
    if(numRows<=1 || numRows>=strlen(s)){return s;}

    //init a container to record each row
    struct list* result = NULL;
    for(int i=0; i<numRows; i++)
    {
        struct list* new_list = malloc(sizeof(struct list));
        new_list->node_head = NULL;
        new_list->node_tail = NULL;
        new_list->next = NULL;
        new_list->prev = NULL;

        if(result == NULL)
        {
            result = new_list;
        }
        else
        {
            struct list* curr_list = result;
            while(curr_list->next != NULL)
            {
                curr_list = curr_list->next;
            }
            curr_list->next = new_list;
            new_list->prev = curr_list;
        }
    }

    //start to put char in each row
    struct list* update_list = result;
    for(int i=0, dir=1; i<strlen(s); i++)
    {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->data = s[i];
        new_node->next = NULL;

        if(update_list->node_head != NULL)
        {
            update_list->node_tail->next = new_node;
            update_list->node_tail = new_node;
        }
        else
        {
            update_list->node_head = new_node;
            update_list->node_tail = new_node;
        }

        if(update_list->next == NULL)
        {
            update_list = update_list->prev;
            dir = 0;
        }
        else if(update_list->prev == NULL)
        {
            update_list = update_list->next;
            dir = 1;
        }
        else
        {
            if(dir == 1)
            {
                update_list = update_list->next;
            }
            else
            {
                update_list = update_list->prev;
            }
        }
    }

    //resort result
    char* result_string=(char*)malloc(sizeof(char)*(strlen(s)+1));
    memset(result_string,0,(strlen(s)+1));
    unsigned int index = 0;
    struct list* input_list = result;
    while(input_list != NULL)
    {
        struct node* input_node = input_list->node_head;
        while(input_node != NULL)
        {
            result_string[index] = input_node->data;
            index++;

            struct node* tmpNode = input_node;
            input_node = input_node->next;
            free(tmpNode);
        }

        struct list* tmpList = input_list;
        input_list = input_list->next;
        free(tmpList);
    }
    result_string[index] = '\0';

    for(int i = 0; i<strlen(s); i++)
    {
        printf("%c ", result_string[i]);
    }
    printf("\n");

    return result_string;
}
#else
char* convert(char* s, int numRows)
{
    if(strlen(s) == 1 || numRows == 1)
        return s;
    int step = (numRows-1)*2, rIndex = 0,strl = strlen(s);
    char *r = (char *)malloc((strl+1)*sizeof(char));
    r[strl] = '\0';
    for(int i = 0;i<numRows;i++){
        int jump = 0;
        while(jump<strl){
            if(jump+i<strl && i!=(numRows-1)){
                r[rIndex] = s[jump+i];
                rIndex++;
            }
            jump+=step;
            if(jump-i<strl && i!=0){
                r[rIndex] = s[jump-i];
                rIndex++;
            }
        }
    }
    
    return r;
}
#endif

/*
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows<=1 || numRows>=s.size()){return s;}
        if(s.empty()){return "";}
        vector<string> rows(numRows);
        for(int i=0,num=0,dir=-1;i<s.size();i++)
        {
            rows[num]+=s[i];
            if(num==0 || num==numRows-1)
            {
                if(dir==1){dir=-1;}
                else{dir=1;}
            }
            num=num+dir;
        }
        string result;
        for(int i=0;i<numRows;i++)
        {
            result.insert(result.size(),rows[i]);
        }
        return result;
    }
};
*/

int main()
{
    char* input = "PAYPALISHIRING";
    printf("%s\n",convert(input, 3));

    printf("%s\n",convert(input, 4));

    input = "A";
    printf("%s\n",convert(input, 1));

    return 0;
}