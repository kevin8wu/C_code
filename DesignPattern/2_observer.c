#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBS 5
typedef void (* Update) (void);
typedef void (* Attach) (Update);
typedef void (* SetData) (char *); 
typedef void (* Notify) (void);

struct Subject
{    
    int size; 
    Update obs[MAX_OBS];
    Attach attach;
    char *data;  
    SetData setData;             
    Notify notify;        
}; 

//declare a global variable
struct Subject subject;

void subjectAttach(Update upd)
{ 
    if(subject.size < MAX_OBS)
    {
        subject.obs[subject.size++] = upd; 
        printf("succeed to attach obs\n");
    }
    else
    {
        printf("fail to attach obs\n");
    }
}

void subjectSetData(char *str)
{
    subject.data = str; 
    subject.notify();
}

void subjectNotify(void)
{
    for(int i=0; i<subject.size; i++) 
    {
        subject.obs[i](); 
    }
}

void subjectInit(void)
{
    subject.size = 0;
    for(int i=0; i<MAX_OBS; i++){ subject.obs[i] = NULL; }
    subject.attach = subjectAttach;  

    subject.data = "This is a subject data ver.1\n"; 
    subject.setData = subjectSetData;          
    subject.notify = subjectNotify;
}

//---

void viewUpdate1(void)
{ 
    printf("I am an observer1, I got notification\n%s", subject.data); 
}

void viewUpdate2(void)
{ 
    printf("I am an observer2, I got notification\n%s", subject.data); 
}

int main()
{
    subjectInit();
    
    subject.attach(viewUpdate1);    
    subject.setData("This is a subject data ver.2\n");  
    subject.attach(viewUpdate2);    
    subject.setData("This is a subject data ver.3\n"); 

    return 0;
}