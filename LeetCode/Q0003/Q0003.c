#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int lengthOfLongestSubstring(char * s)
{
    int result=0;
    for(int left=0,right=0;right<strlen(s);right++)
    {
        char * temp=(char *)calloc(right-left+1,sizeof(char));
        for(int k=0,i=left;i<=right;i++,k++){temp[k]=s[i];}
        int pos=strchr(temp,s[right])-temp;
        if(pos<(right-left)){left=left+pos+1;} //if(pos<(strlen(temp)-1)){left=left+pos+1;}
        if(result<(right-left+1)){result=right-left+1;}
    }
    return result;
}
*/

struct node
{
    char s;
    struct node * next;
};
struct node * front;
struct node * back;
void init()
{
    front=back=(struct node *)malloc(sizeof(struct node));
    front->next=back->next=NULL;
}
void enque(char v)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->s=v;
    new->next=NULL;
    if(front->next==NULL){front->next=new;}
    back->next=new;
    back=new;
}
void deque(int n)
{
    for(int i=0;i<n;i++)
    {
        if(front->next==NULL){return;}
        struct node * tmp;
        tmp=front->next;
        front->next=tmp->next;
        free(tmp);
    }
}
int count()
{
    if(front->next==NULL){return 0;}
    struct node * curr=front->next;
    int result=0;
    while(curr!=NULL)
    {
        curr=curr->next;
        result++;
    }
    free(curr);
    return result;
}
int find(char v)
{
    if(front->next==NULL){return -1;}
    struct node * curr=front->next;
    int pos=-1;
    int result=-1;
    while(curr!=NULL)
    {
        pos++; 
        if(v==curr->s && curr->next!=NULL)
        {
            if(result==-1){result=pos;/*printf("%d ",result);*/}
        }
        curr=curr->next;
    }
    free(curr);
    return result;
}
int lengthOfLongestSubstring(char * s)
{
    int result=0;
    init();
    while(*s!='\0')
    {
        enque(*s); 
        if(find(*s)!=-1){deque(find(*s)+1);}
        if(result<count()){result=count();/*printf("R %d\n",result);*/}
        s++;
    }
    return result;
}

/*
class Solution 
{
private:
    string temp;
    int pos;
    int result;    
public:
    int lengthOfLongestSubstring(string s) 
    {
        for(int left=0,right=0;right<s.size();right++)
        {
            temp=s.substr(left,right-left+1);
            pos=temp.find(s.substr(right,1));
            if(pos < temp.size()-1) //find repeated item
            {
                left=left+pos+1;
            } 
            if(result<(right-left+1)){result=right-left+1;}
        }
        return result;
    }
};
*/

int main()
{
    printf("%d\n",lengthOfLongestSubstring("pwwkew"));

    return 0;
}