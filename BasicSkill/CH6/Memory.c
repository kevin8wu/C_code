#include <stdio.h> 
#include <stdlib.h> //memory management function
#include <string.h>

typedef struct
{
    int num;
    char *info;
}record;

typedef struct
{
    int *elements;
    int size,cap;
}dyn_array;

int main()
{
    /*
    C automatically allocates space for the variable in memory called "stack"
    Dynamic memory allocation is managed with pointer in area called "heap"
    */
    //an array is allocated contiguous blocks of memory
    int arr[10];
    printf("%d\n",sizeof(arr)); //4*10 bytes

    //malloc(bytes) //return a pointer to blocks of memory for variable
    //calloc(num_items,item_size) //return a pointer to blocks of memory for arrays
    //realloc(ptr,bytes) //resize the memory and return to a pointer
    //free(ptr) //release the block of memory pointed by ptr
    int *ptr;
    ptr=malloc(10*sizeof(*ptr)); //initialize by zero
    if(ptr!=NULL){*(ptr+2)=50;printf("%d\n",*(ptr+2));}
    ptr=realloc(ptr,100*sizeof(*ptr)); //leave the origin data in memory
    *(ptr+30)=75;printf("%d %d\n",*(ptr+2),*(ptr+30));
    free(ptr); //freeing the memory
    record *recs;
    int num_recs=2;
    char str[]="This is information";
    recs=calloc(num_recs,sizeof(record)); //initialize by zero
    if(recs!=NULL)
    {
        for(int k=0;k<num_recs;k++)
        {
            (recs+k)->num=k;
            (recs+k)->info=malloc(sizeof(str)); //like method "new" in C++
            strcpy((recs+k)->info,str);
            printf("%d element : %d\t%s\n",k,(recs+k)->num,(recs+k)->info);
        }
    }

    char strBig[20];
    char *strSmall=NULL;
    strcpy(strBig,"1234");
    printf("%d\n",strlen(strBig)); //only count meaningful length
    strSmall=malloc((strlen(strBig)+1)*sizeof(char)); //only assign the needed space by strlen 
    strcpy(strSmall,strBig);
    printf("%s\n",strSmall);

    dyn_array arrdyn;
    arrdyn.size=0;
    arrdyn.elements=calloc(1,sizeof(*arrdyn.elements)); 
    arrdyn.cap=1;
    arrdyn.elements=realloc(arrdyn.elements,(5+arrdyn.cap)*sizeof(*arrdyn.elements)); 
    if(arrdyn.elements!=NULL){arrdyn.cap+=5;}
    while(arrdyn.size<arrdyn.cap)
    {
        arrdyn.elements[arrdyn.size]=50;
        printf("%d %d\n",arrdyn.size, arrdyn.elements[arrdyn.size]);
        arrdyn.size++;
    }

    /******************************************/
    /*the free does not delete the pointer variable itself, 
    it simply releases the data that it points to.*/
    /******************************************/

    int nrows = 2;
    int ncols = 5;
    char **pvowels = (char **) malloc(nrows * sizeof(char*)); //muti-dimention array with malloc
    pvowels[0] = (char *) malloc(ncols * sizeof(char));
    pvowels[1] = (char *) malloc(ncols * sizeof(char));
    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';
    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';
    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncols; j++) 
        {
            printf("%c ", pvowels[i][j]);
        }
        printf("\n");
    }
    free(pvowels[0]);
    free(pvowels[1]);
    free(pvowels);


    int* data1=(int*)malloc(6*sizeof(int)); //not initialize for all elements
    printf("%d %d %d %d %d %d\n",data1[0],data1[1],data1[2],data1[3],data1[4],data1[5]);
    *data1=1; //initialize for partial elements
    printf("%d %d %d %d %d %d\n",data1[0],data1[1],data1[2],data1[3],data1[4],data1[5]);

    /*void * memset(void *dest, int val, size_t n); set first n bytes of data in dest by val.*/
    memset(data1,0,6*sizeof(int)); //only initialize with 0 by memset
    printf("%d %d %d %d %d %d\n",data1[0],data1[1],data1[2],data1[3],data1[4],data1[5]);

    int* data2=(int*)malloc(6*sizeof(int));
    *data2=1;*(data2+1)=2;*(data2+2)=3;*(data2+3)=4;*(data2+4)=5;*(data2+5)=6;
    /*void * memcpy(void *dest, const void *src, size_t n);*/
    memcpy(data1,data2,6*sizeof(int));
    printf("%d %d %d %d %d %d\n",data1[0],data1[1],data1[2],data1[3],data1[4],data1[5]);
    memcpy(data1+2,data1,4*sizeof(int)); //overwrite without dealing with overlap area
    printf("%d %d %d %d %d %d\n",data1[0],data1[1],data1[2],data1[3],data1[4],data1[5]);

    memcpy(data1,data2,6*sizeof(int));
    /*void * memmove(void *dest, const void *src, size_t n);*/
    memmove(data1+2,data1,4*sizeof(int)); //overwrite with dealing with overlap area
    printf("%d %d %d %d %d %d\n",data1[0],data1[1],data1[2],data1[3],data1[4],data1[5]);

    return 0;
}

#if 0
typedef unsigned char   BOOLEAN;
typedef unsigned char   UINT8;
typedef unsigned char   UCHAR;
typedef signed char      INT8;
typedef signed char      CHAR;

typedef unsigned short  UINT16;
typedef signed short     INT16;

typedef unsigned int    UINT32;
typedef signed int       INT32;

typedef unsigned long long  UINT64;
typedef long long           INT64;

void* memset(void *buf, int val, size_t size)
{
    UINT8 c = (UINT8)val;
    UINT32 dstp = (UINT32) buf;

    /* 
       If copied length is not long, it has higher efficiency 
       to use byte copied directly 
    */

    if (size >= 8)
    {
        UINT32 cccc = c;
        if (c != 0)
        {
            cccc |= cccc << 8;
            cccc |= cccc << 16;
        }

        while (dstp & 0x03)
        {
            *(UINT8 *) dstp = c;
            dstp++;
            size--;
        }

        while (size > 3)
        {
            *(UINT32 *) dstp = cccc;
            dstp += 4;
            size -= 4;
        }
    }

    /* Write the last few bytes. */
    while (size > 0)
    {
        *(UINT8 *) dstp = c;
        dstp++;
        size--;
    }

    return buf;
}

void* memcpy(void * restrict dest, const void * restrict source, size_t size)
{
    UINT32 dstp = (UINT32) dest;
    UINT32 srcp = (UINT32) source;

    /* 
       If copied length is not long, it has higher efficiency 
       to use byte copied directly 
    */

    if (size >= 8)
    {
        if ((dstp & 0x03) == (srcp & 0x03))
        {
            /* 
               case 1: destination address and source address is offset
               alignment after 4-byte aligned boundary 
            */

            while (dstp & 0x03)
            {
                *(UINT8 *) dstp = *(UINT8 *)srcp;
                dstp++;
                srcp++;
                size--;
            }

            while (size > 3)
            {
                *(UINT32 *) dstp = *(UINT32 *)srcp;
                dstp += 4;
                srcp += 4;
                size -= 4;
            }
        }
        else if (!(dstp & 0x01) && !(srcp & 0x01))
        {
            /* 
               case 2: destination address and source address are 2-byte align-
               ment but their offsets after 4-byte aligned boundary are not the
               same 
            */

            while (size > 1)
            {
                *(UINT16 *) dstp = *(UINT16 *) srcp;
                dstp += 2;
                srcp += 2;
                size -= 2;
            }
        }
    }

    /* Write the last few bytes.  */
    while (size > 0)
    {
        *(UINT8 *) dstp = *(UINT8 *)srcp;
        dstp++;
        srcp++;
        size--;
    }

    return dest;
}

void* memmove(void *dest, const void *source, size_t size)
{
    UINT32 dstp = (UINT32) dest;
    UINT32 srcp = (UINT32) source;

    if (srcp > dstp) /* Forward copy */
    {
        if (size >= 8)
        {
            if ((dstp & 0x03) == (srcp & 0x03))
            {
                /* 
                   case 1: destination address and source address is offset
                   alignment after 4-byte aligned boundary 
                */

                while (dstp & 0x03)
                {
                    *(UINT8 *) dstp = *(UINT8 *) srcp;
                    dstp++;
                    srcp++;
                    size--;
                }

                while (size > 3)
                {
                    *(UINT32 *) dstp = *(UINT32 *) srcp;
                    dstp += 4;
                    srcp += 4;
                    size -= 4;
                }
            }
            else if (!(dstp & 0x01) && !(srcp & 0x01))
            {
                /* 
                  case 2: destination address and source address are 2-byte align-
                   ment but their offsets after 4-byte aligned boundary are not the
                   same 
                */

                while (size > 1)
                {
                    *(UINT16 *) dstp = *(UINT16 *) srcp;
                    dstp += 2;
                    srcp += 2;
                    size -= 2;
                }
            }
        }

        /* Write the last few bytes.  */
        while (size > 0)
        {
            *(UINT8 *) dstp = *(UINT8 *) srcp;
            dstp++;
            srcp++;
            size--;
        }
    }
    else /* Backward copy */
    {
        // to avoid the overlap issue
        dstp += size;
        srcp += size;

        if (size >= 8)
        {
            if ((dstp & 0x03) == (srcp & 0x03))
            {
                /* 
                   case 1: destination address and source address is offset
                   alignment after 4-byte aligned boundary 
                */

                while (dstp & 0x03)
                {
                    dstp--;
                    srcp--;
                    *(UINT8 *) dstp = *(UINT8 *) srcp;
                    size--;
                }

                while (size > 3)
                {
                    dstp -= 4;
                    srcp -= 4;
                    *(UINT32 *) dstp = *(UINT32 *) srcp;
                    size -= 4;
                }
            }
            else if (!(dstp & 0x01) && !(srcp & 0x01))
            {
                /* 
                  case 2: destination address and source address are 2-byte align-
                   ment but their offsets after 4-byte aligned boundary are not the
                   same 
                */

                while (size > 1)
                {
                    dstp -= 2;
                    srcp -= 2;
                    *(UINT16 *) dstp = *(UINT16 *) srcp;
                    size -= 2;
                }
            }
        }

        /* Write the last few bytes.  */
        while (size > 0)
        {
            dstp--;
            srcp--;
            *(UINT8 *) dstp = *(UINT8 *) srcp;
            size--;
        }
    }

    return dest;
}
#endif