#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "practice_string.h"
//-----------------------------------------------------------
#include "practice_sort.h"
//-----------------------------------------------------------
#include "practice_container.h"
//-----------------------------------------------------------

#define ONE (1)
void plusOne(int * a,int len);

//-----------------------------------------------------------

int main()
{
    unsigned int a = -2;
    if(a>=0){printf("YES\n");} //YES
    printf("%d\n",a); //-2
    /*
        unsigned int only support 0~4294967295(2^32-1)
        Although unsigned int assigned to negative, it still be tell as positive forever
    */
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            if(j<(6-i)){printf("%c",' ');}
            else{printf("%c",'*');}
        }
        printf("\n");
    }
    char cc[5]="abcd";
    char * p=strrevs(cc);
    printf("%s\n",cc);
    printf("%s\n",p);
    strrevs(cc);
    printf("%s\n",cc);
    int price[3]={1,4,7};
    int * pp=price;
    printf("%d\t",price[1]); //4
    printf("%d\t",*pp); //1
    printf("%d\t",*pp++); //1, same as *(pp++), but plus after dereference
    printf("%d\t",*pp); //4, move forward and dereference
    printf("%d\t",*pp++); //4
    printf("%d\t",*pp); //7
    printf("%d\t",price[0]); //1
    char prices[4]={'A','0','a','\0'};
    char *ppp=prices;
    printf("%s\t",prices);
    printf("%s\t",ppp);
    printf("%c\t",prices[0]);
    printf("%c\t",*ppp++); //A
    printf("%c\t",*ppp++); //0
    printf("%c\t",*ppp); //a
    printf("%c\n",prices[0]);
    char s[]="012345";
    char * ps=s;
    printf("%c ",*ps++); //0
    printf("%c ",*ps); //1
    printf("%c ",*(ps++)); //1
    printf("%c ",*ps); //2
    printf("%c ",(*ps)++); //2, plus after printf
    printf("%c ",*ps); //3, plus and printf
    printf("%c ",*++ps); //3
    printf("%c ",*ps); //3
    printf("%c ",*(++ps)); //4
    printf("%c ",*ps); //4
    printf("%c ",++*ps); //5=4+1
    printf("%c ",*ps); //5=4+1
    printf("%c ",++(*ps)); //6=(4+1)+1
    printf("%s\n",s); //013365
    for(int i=0;i<10;i++)
    {
        if(i>7)break;
        else if(i==2)continue;
        else if(i%3==0)continue;
        else printf("%d\n",i);
    }
    printf("%d\t%d\t%d\n",31/2,31%4,31*8); //15  3  248
    printf("%d\t%d\t%d\n",31>>1,31&3,31<<3); //15  3  248
    int len=4,center=2;
    int start,end;
    start=center-(len-1)/2;
    end=center+len/2;
    printf("%d %d\n",(len-1)/2,len/2); //1 2
    printf("%d %d\n",start,end); //1 4
//-----------------------------------------------------------
    typedef union 
    {
        unsigned long l;
        unsigned char c[4];
    } EndianTest;
    EndianTest et;
    et.l = 0x12345678;
    printf("byte order in system : ");
    if(et.c[0] == 0x78 && et.c[1] == 0x56 && et.c[2] == 0x34 && et.c[3] == 0x12)
    {
        printf("Little Endian\n");
    } 
    else if(et.c[0] == 0x12 && et.c[1] == 0x34 && et.c[2] == 0x56 && et.c[3] == 0x78)
    {
        printf("Big Endian\n");
    }
    else
    {
        printf("Unknown Endian\n");
    }
    printf("0x%lX the stored order in memory : \n", et.l);
    for(int i = 0; i < 4; i++)
    {
        printf("%p : 0x%02X\n", &et.c[i], et.c[i]);
    }
//-----------------------------------------------------------
    int arr1[SIZE]={95,54,33,47,12}; 
    bubble_sort(arr1,SIZE); 
    printarr(arr1,SIZE); 
    int arr2[SIZE]={95,54,33,47,12}; 
    selection_sort(arr2,SIZE); 
    printarr(arr2,SIZE); 
    int arr3[SIZE]={95,54,33,47,12}; 
    insertion_sort(arr3,SIZE); 
    printarr(arr3,SIZE); 
    int arr4[SIZE]={95,54,33,47,12}; 
    //merge_sort(arr4,SIZE); 
    merge_sort_recursive(arr4,SIZE);
    printarr(arr4,SIZE); 
    int arr5[SIZE]={95,54,33,47,12};
    //quick_sort(arr5,SIZE);
    quick_sort_recursive(arr5,0,SIZE-1);
    printarr(arr5,SIZE); 
//-----------------------------------------------------------
    printf("please input data : \n");
    for(int i=0;i<10;i=i+2)
    {
        push_stack(i);
    }
    printf("====================\n"); 
    while(!stack_isEmpty()) 
    { 
        printf("pop stack : %d\n",pop_stack());
    }
//----------------------------------------------------------- 
    createqueue();
    showqueue();
    enqueue(5);
    enqueue(6);
    enqueue(7);
    showqueue();
    showfront();
    showback();
    dequeue();
    dequeue();
    showqueue();
    showfront();
    showback();
    dequeue();
    showqueue(); 
    /*
    int input,select,round;
    round=5;
    while(round)  
    { 
        printf("\n\n請輸入選項(-1結束)："); 
        printf("\n(1)插入值至儲列"); 
        printf("\n(2)顯示儲列前端"); 
        printf("\n(3)刪除前端值"); 
        printf("\n(4)顯示所有內容"); 
        printf("\n(5)顯示儲列後端");
        printf("\n >"); 
        scanf("%d", &select); 
        if(select==-1) 
            break; 
        switch(select)
        { 
            case 1: 
                printf("\n 輸入值："); 
                scanf("%d", &input); 
                enqueue(input); 
                break; 
            case 2: 
                showfront(); 
                break; 
            case 3: 
                dequeue(); 
                break; 
            case 4: 
                showqueue(); 
                break; 
            case 5:
                showback();
                break;
            default: 
                printf("\n 選項錯誤！"); 
        } 
        round--;
    } 
    */
    printf("\n"); 
//-----------------------------------------------------------

    int av[]={9,9,9};
    plusOne(av,sizeof(av)/sizeof(av[0]));

//-----------------------------------------------------------

    return 0;
}

void plusOne(int* a,int len)
{
    if(a!=NULL && len>0)
    {
        int carry = ONE;
        struct Node* head=NULL;
        struct Node* tail=NULL;
        for(int i=0;i<len;i++)
        {
            int temp = a[len-1-i] + carry;
            struct Node* new=(struct Node*)malloc(sizeof(struct Node));
            new->data = temp%10;
            new->next = NULL;
            carry = temp/10;
            if(head==NULL && tail==NULL)
            {
                head=new;
                tail=new;
            }
            else
            {
                tail->next = new;
                tail = new;
            }
        }
        if(carry!=0)
        {
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            new->data = carry;
            new->next = NULL;
            tail->next = new;
            tail = new;
        }

        int k=1;
        int result=0;
        struct Node* ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            result+=(ptr->data)*k;
            k*=10;
            ptr=ptr->next;
        }
        printf("\n%d\n",result);
    }
}
