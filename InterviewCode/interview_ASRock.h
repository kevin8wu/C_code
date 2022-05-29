//2019/12/18 永擎
#define _BV(x) (1<<(x))

int enableA(int data)
{
    return data|=_BV(3);
}

int disableA(int data)
{
    return data&=~_BV(3);
}

void printArray(int *A)
{
    for(int i=0;i<5;i++)
    {
        printf("%d\t",*(A+i));
    }
    printf("\n");
}

void reverseArray(int *A)
{
    int *rev=malloc(5*sizeof(int));
    for(int i=0;i<5;i++){rev[i]=A[4-i];}
    for(int i=0;i<5;i++){A[i]=rev[i];}
    free(rev);
}

void reverseArrayss(int *A)
{
    int *rev=malloc(5*sizeof(int));
    for(int i=0;i<5;i++){rev[i]=A[4-i];}
    printArray(rev);
    free(rev);
}

int* reverseArrays1(int *A)
{
    static int rev[5];
    for(int i=0;i<5;i++){rev[i]=A[4-i];}
    return rev;
} 

int* reverseArrays2(int *A)
{
    int *rev=malloc(5*sizeof(int));
    for(int i=0;i<5;i++){rev[i]=A[4-i];}
    return rev;
} 