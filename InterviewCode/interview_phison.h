//2019/12/23 群聯

void Q1(int* a,int size) 
{
    printf("\nQuestion1 : \n"); 
    int* nextPtr=a; //a is an sorted array  
    for(int currentIndex=0;currentIndex<=20;currentIndex++) 
    { 
        if(currentIndex==*nextPtr){nextPtr++;} 
        else{printf("%d , ",currentIndex);} 
    }
    printf("\n"); 
}

void Q2(int* a, int size, int b) 
{ 
    printf(" \nQuestion2 : \n"); 
    int* nextPtr=a; 
    while(*nextPtr<b*100){nextPtr++;} 
    for(int currentIndex=b*100;currentIndex<(b+1)*100;currentIndex++) 
    { 
        if(currentIndex==*nextPtr){nextPtr++;} 
        else{printf("%d , ",currentIndex);} 
    } 
    printf("\n"); 
} 

#define Q3NULL 0xFFFF
#define false 0
#define true 1
struct ListStruct
{ 
    unsigned int DataH; 
    unsigned int DataL; 
    unsigned int NextIndex; 
}; 
struct ListStruct ListArray[4];
void Q3(unsigned int DATA_A,unsigned int DATA_B) 
{
    printf(" \nQuestion3 : \n");
    int isSearched=false;
    unsigned int FoundIndex=0;
    while(FoundIndex!=Q3NULL)
    {
        if(ListArray[FoundIndex].DataH==DATA_A && ListArray[FoundIndex].DataL==DATA_B)
        {
            isSearched=true;
            printf("FoundIndex = %d\n",FoundIndex);
            break;
        }
        FoundIndex=ListArray[FoundIndex].NextIndex;
    }
    if(!isSearched)
    {
        printf("no found.\n");
    }
}
