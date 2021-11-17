#include <stdio.h>

int my_square(int num){return num*num;} //single arg
int sum_up(int x, int y){return x+y;} //double arg
void say_hello()
{
    static int num_calls=1; //static var in func ; always exist in function
    printf("Hello number %d\n",num_calls);
    num_calls++;
}
int factorial(int num)
{
    if(num==1){return 1;} //prevent inf loop
    else{return num*factorial(num-1);} //recursion by "stacking" until the base appear
}

/******************************************/

void test_address(int k)
{
    printf("the address of k is %x\n",&k);
}
void swap(int *num1,int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}
float add_up(float *a,int num_elements)
{
    float total=0;
    for(int k=0;k<num_elements;k++){total+=a[k];}
    return total;
}
int * get_evens()
{
    static int nums[5]; //using static to pass out address
    int even=0;
    for(int k=0;k<5;k++)
    {
        //even+=2;nums[k]=even;
        nums[k]=even+=2;
    }
    return nums;
}

/******************************************/

int main()
{
    int x, y, result;
    x=5;
    result=my_square(x);
    printf("%d squared is %d\n",x,result);

    x=3;
    y=12;
    result=sum_up(x,y);
    printf("%d + %d = %d\n",x,y,result);

    for(int i=0; i<5; i++){say_hello();}

    printf("The factorial of %d is %d\n",5,factorial(5));

    /******************************************/

    int test_score[5]; //array can't change size after definition
    float prices[5]={3.2,6.55}; //partially initalize array ;  missing value is set to 0
    printf("the origin second element is %f\n",prices[1]);
    prices[1]=5.2; //modify directly
    printf("the modified second element is %f\n",prices[1]);
    printf("length of array %d\n",sizeof(prices)/sizeof(prices[0]));

    int a[2][3]={{3,2,6},{4,5,20}}; //2d array
    printf("Element 3 in row 2 is %d\n",a[1][2]);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    /******************************************/

    printf("the address of x is %x\n",&x); //get the address
    test_address(x); //get different address in func by value arg
    int *p=NULL; //pointer declare
    p=&x; //pointer assign
    printf("p contains address %x\n",p);
    printf("p is pointing to the value %d\n",*p);
    int **ptr=&p; //pointer of pointer
    (**ptr)++; //(**ptr)=(**ptr)+1
    printf("ptr contains address %x\n",ptr);
    printf("ptr is pointing to the value %x\n",*ptr);
    printf("ptr is pointing to the value of value %d\n",**ptr);
    float *pf=prices; //pointer assign to array    
    for(int i=0;i<5;i++){printf("%f ",*(pf+i));}printf("\n"); 
    //pointer allow using ==, >, < to compare address

    printf("x is %d, y is %d\n",x,y);
    swap(&x,&y); //pointer arg
    printf("x is %d, y is %d\n",x,y);
    printf("total prices is %f\n",add_up(prices,5));

    int *pg;
    pg=get_evens(); //func return pointer
    for(int i=0;i<5;i++){printf("%d\n",pg[i]);}

    /******************************************/

    return 0;
}