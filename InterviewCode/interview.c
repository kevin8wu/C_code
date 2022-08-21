#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interview_ASRock.h"

#include "interview_phison.h"

#include "interview_ilitek.h"

//2020/01/07 松翰

#include "interview_realtek.h"

#include "interview_mtk.h"

#include "interview_infineon.h"

int main()
{
#if 0 //2019/12/18 永擎
    int data=6;
    printf("HEY\n");
    printf("%d\n",enableA(data));
    printf("%d\n",disableA(data));

    char aa=128;
    char bb=2;
    printf("%d\n",aa); //-128
    printf("%d\n",aa+bb); //-126
    /*
    char only support -128~127 (127 for 0x7F;-128 for 0x80;-1 for 0xFF)
    if max 127 overflow, it will jump to min -128 and move back to -1
    */

    typedef unsigned int UIN8;
    typedef unsigned short UIN16;
    char aaa[10]={0,1,2,3,4,5,6,7,8,9};
    char *p;
    p=aaa;
    printf("%d\n",(UIN8)*(p+8)); //8
    printf("%d\n",(UIN8)*p); //0
    printf("%d\n",(UIN16)*p); //0
    int Array[5]={-1,2,3,-4,5};
    reverseArray(Array);
    printArray(Array);
    reverseArrayss(Array);
    int* Brray=reverseArrays1(Array);
    printArray(Brray);
    int* Crray=reverseArrays2(Array);
    printArray(Crray);
#endif    

#if 0 //2019/12/23 群聯
    int q1a[5]={2,3,4,6,7};
    Q1(q1a,5);
    int q2a[5]={2,3,4,6,97};
    int b=0;
    Q2(q2a,5,b);
    ListArray[0]=(struct ListStruct){.DataH=0,.DataL=0,.NextIndex=1};
    ListArray[1]=(struct ListStruct){.DataH=1,.DataL=0,.NextIndex=2};
    ListArray[2]=(struct ListStruct){.DataH=1,.DataL=1,.NextIndex=3};
    ListArray[3]=(struct ListStruct){.DataH=1,.DataL=2,.NextIndex=0xFFFF};
    Q3(1,2);
#endif
   
    //2020/01/07 松翰

#if 0 //2020/01/09 奕力
    char s[]="0113256";
    char* ps=s;
    printf("%c ",*ps++); //like *(ps++), 0
    printf("%c ",*(ps++)); //1
    printf("%c ",(*ps)++); //1
    printf("%c ",*++ps); //like *(++ps), 3
    printf("%c ",*(++ps)); //2
    printf("%c ",++*ps); //2+1
    printf("%c ",++(*ps)); //(2+1)+1
    printf("%s\n",s); //0123456
    for(int i=0;i<10;i++)
    {
        if(i>7)break;
        else if(i==2)continue;
        else if(i%3==0)continue;
        else printf("%d\t",i);
    }
    printf("\n");
    int xa[5]={95,33,54,47,12};
    printf("%d\n",find_second_max(xa,5));
    printf("%d\t%d\t%d\n",31/2,31%4,31*8);
    printf("%d\t%d\t%d\n",31>>1,31&3,31<<3);
    int swapA=1,swapB=2;
    swap(&swapA,&swapB);
    printf("%d %d\n",swapA,swapB);
    int AA,BB;
    AA=31;BB=3;
    AA=AA|BB;
    printf("%d ",AA);
    AA=31;BB=3;
    AA=AA&(~BB);
    printf("%d ",AA);
    AA=31;BB=3;
    AA=AA^BB;
    printf("%d\n",AA);
    //system stack heap bss text data
    //big endian; little endian
    //static volatile
#endif

    //2020/02/07 瑞昱
#if 0
    struct RQ1* RQ1_head=NULL;
    struct RQ1* RQ1_curr=RQ1_head;
    int inputRQ1[4]={1,5,2,7};
    for(int i=0;i<4;i++)
    {
        struct RQ1* input_node=malloc(sizeof(struct RQ1));
        input_node->data=inputRQ1[i];
        input_node->next=NULL;
        if(RQ1_curr==NULL)
        {
            RQ1_curr=input_node;
            RQ1_head=RQ1_curr;
        }
        else
        {
            RQ1_curr->next=input_node;
            RQ1_curr=input_node;
        }
    }
    insert_before_max(&RQ1_head, 3);
    RQ1_curr=RQ1_head;
    while(RQ1_curr!=NULL)
    {
        printf("%d ", RQ1_curr->data);
        RQ1_curr=RQ1_curr->next;
    }
    printf("\n");
#endif

#if 0 //2020/02/18 聯發科
    struct circle A={5,{1,1}};
    printCircle(A);

    if(isMult3(7))
    {
        printf("multiple of 3\n");
    }
    else
    {
        printf("not multiple of 3\n");
    }

    union udata udata1;
    udata1.dataI=3406;
    printf("%d\n",udata1.dataC[0]);

    int input_arr[10]={2,3,3,3,3,7,5,1,2,7};
    for(int i=0;i<10;i++)
    {
        printf("input %d median %f\n",input_arr[i],get_median(input_arr[i]));
        struct queue_m* curr=head;
        while(curr!=NULL)
        {
            printf("%d ",curr->data);
            curr=curr->next;
        }
        printf("\n");
    }

    struct node_size_test N;
    printf("%d %d %d\n",sizeof(int),sizeof(char),sizeof(struct node_size_test)); //4 1 8
    printf("%d\n",sizeof(N)); //using sizeof to estimate size
    printf("%x %x\n", &N, &N+1); //0x61fdc8 0x61fdd0
    printf("%d\n",size_estimation(N)); //using address to estimate size

    struct reverse_list* rev_curr=NULL;
    for(int i=0;i<3;i++)
    {
        if(rev_curr==NULL)
        {
            rev_curr=(struct reverse_list*)malloc(sizeof(struct reverse_list));
            rev_curr->data=i+1;
            rev_curr->next=NULL;
            reverse_head=rev_curr;
        }
        else
        {
            struct reverse_list* new=malloc(sizeof(struct reverse_list));
            new->data=i+1;
            new->next=NULL;
            rev_curr->next=new;
            rev_curr=new;
        }
    }
    rev_curr=reverse_head;
    while(rev_curr!=NULL)
    {
        printf("%d ",rev_curr->data);
        rev_curr=rev_curr->next;
    }
    printf("\n");
    reverse_linked_list(); //modify next ptr for reversing
    rev_curr=reverse_head;
    while(rev_curr!=NULL)
    {
        printf("%d ",rev_curr->data);
        rev_curr=rev_curr->next;
    }
    printf("\n");

    int mtk_arr[]={1,2,3};
    printf("%x %d %x %d\n",mtk_arr, *mtk_arr, mtk_arr+1, *(mtk_arr+1));
    //&arr+1 indicate the next address of array in size of array!!!
    printf("%x %x\n",&mtk_arr, &mtk_arr+1);
    int* mtk_ptr=mtk_arr;
    //&ptr indicate the prev address of array in size of array!!!
    printf("%x %x %x\n",mtk_ptr, *mtk_ptr, &mtk_ptr);
#endif

#if 1 //2022/8/5 英飛凌
/*
- heap allocation and memory relationship
- linked list expression for timer
- linked list dequeue for timer
- n step + 2*m step = 50 step
- strstr to find out the repeated string
- display the value from 4 different data type when increasing 32
- find the longest sub-array in order for specific array
*/
    steps_method(50);

    add32();

    int arr[]={1,5,3,2,6,7,9};
    int* result=longestSubArray(arr, 7);
#endif

    return 0;
}

//mediatek MM camera software
//ynn.wu@mediatek.com

//infineon CCSITB CSS ICW SW3
//0927-772-139
//ray.yu@infineon.com

