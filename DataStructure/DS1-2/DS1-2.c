#include <stdio.h>

/***solution***/
/*
1.try and error
2.stepwise refinement: top-down/bottom-up
3.backward
4.forward
*/
/***pseudocode***/
/*
used to present sequence/decision/repetition
no strict rule to follow, easy to understand
*/
/***complexity***/
/*
time complexity: compile time + execution time
spacec complexity: memory used
*/
/***Big-Oh***/
/*
O(1):       const
O(n):       linear
O(n*n):     quadratic
O(logn):    log
O(nlogn):   log linear

O(2^n):     exponential
O(n!):      factorial

O(1)<O(log)<O(n)<O(nlog)<O(n*n)<O(2^n)<O(n!)
*/

/*iterative method*/
int factorial_iterative(int n)
{
    int result=1;
    if(n==0) return 1;
    while(n>0)
    {
        result=result*n;
        n=n-1;
    }
    return result;
}
int fibo_iterative(int n) //Fibonacci sequence
{
    int fn,fn1,fn2;
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    {
        fn2=0;fn1=1;
        for(int i=2;i<=n;i++)
        {
            fn=fn1+fn2;
            fn2=fn1;
            fn1=fn;
        }
    }
    return fn;
}
int gcd_iterative(int M,int N)
{
    int R;
    while(N>0)
    {
        R=M%N;
        M=N;
        N=R;
    }
    return M;
}
/*recursive method*/
//Recursion consists of two main parts: 
//A terminating case that indicates the end, 
//a call to itself that must make progress towards the terminating case.
int factorial_recursive(int n)
{
    if(n==0) return 1;
    else return (n*factorial_recursive(n-1));
}
int fibo_recursive(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibo_recursive(n-1)+fibo_recursive(n-2);
}
int gcd_recursive(int M,int N)
{
    if((M%N)==0) return N;
    else return gcd_recursive(N,M%N);
}
//mylti-dimention as argument
void matrix_multiply(int m,int n,int p,int A[m][n],int B[n][p])
{
    int C[m][p];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            C[i][j]=0;
            for(int k=0;k<n;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

/*polynomial*/
#define COMPARE(x,y) ((x<y)?-1:(x==y)?0:1)
#define MAX_SIZE 100
typedef struct
{
    int coef;
    int exp;
}NonZeroTerm;
typedef struct
{
    int count;
    NonZeroTerm terms[MAX_SIZE];
}Polynomial;
void PolyAttach(Polynomial *ptr,int coef,int exp)
{
    if(ptr->count>=MAX_SIZE) return;
    ptr->terms[ptr->count].coef=coef;
    ptr->terms[ptr->count].exp=exp;
    ptr->count++;
}
PolyAdd(Polynomial *pA,Polynomial *pB,Polynomial *pC)
{
    int currentA=0,currentB=0;
    pC->count=0;
    while(currentA<pA->count && currentB<pB->count)
    {
        switch(COMPARE(pA->terms[currentA].exp,pB->terms[currentB].exp))
        {
            case -1:
                PolyAttach(pC,pB->terms[currentB].coef,pB->terms[currentB].exp);
                currentB++;
                break;
            case 0:
                if((pA->terms[currentA].coef+pB->terms[currentB].coef)!=0)
                {
                    PolyAttach(pC,pA->terms[currentA].coef+pB->terms[currentB].coef,pA->terms[currentA].exp);
                    currentA++;
                    currentB++;
                    break;
                }
            case 1:
                PolyAttach(pC,pA->terms[currentA].coef,pA->terms[currentA].exp);
                currentA++;
                break;
        }
    }
    while(currentA<pA->count)
    {
        PolyAttach(pC,pA->terms[currentA].coef,pA->terms[currentA].exp);
        currentA++;
    }
    while(currentB<pB->count)
    {
        PolyAttach(pC,pB->terms[currentB].coef,pB->terms[currentB].exp);
        currentB++;
    }
}

/*sparse matrix*/
typedef struct
{
    int row,col,value;
}sparseTerm;

int main()
{
    Polynomial A,B,C;
    A.count=0;
    PolyAttach(&A,3,5);
    PolyAttach(&A,8,4);
    PolyAttach(&A,-6,2);
    PolyAttach(&A,5,0);
    B.count=0;
    PolyAttach(&B,2,6);
    PolyAttach(&B,4,2);
    PolyAttach(&B,1,0);
    PolyAdd(&A,&B,&C);
    for(int i=0;i<C.count;i++)
    {
        printf("%dx^%d+ ",C.terms[i].coef,C.terms[i].exp);
    }
    printf("\n");

    return 0;
}