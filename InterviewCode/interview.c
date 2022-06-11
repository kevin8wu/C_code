#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interview_ASRock.h"

#include "interview_phison.h"

#include "interview_ilitek.h"

//2020/01/07 松翰

//2020/02/07 瑞昱

#include "interview_mtk.h"

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
    printf("%d\n",(UIN8)*(p+8));
    printf("%d\n",(UIN8)*p);
    printf("%d\n",(UIN16)*p);
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

#if 0 //2020/02/18 聯發科
    struct circle A={5,{1,1}};
    printCircle(A);
#endif

    return 0;
}



