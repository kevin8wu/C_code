#include <stdio.h> 
#include <stdlib.h> //for some sorting algorithm
#include <string.h> //for standard string lib

void say_hello(int num_times)
{
    int k;
    for(k=0;k<num_times;k++){printf("Hello\n");}
}

int add(int num1,int num2){return (num1+num2);}

int subtract(int num1,int num2){return (num1-num2);}

int multiply(int num1,int num2){return (num1*num2);}

int divide(int num1,int num2)
{
    if(num2!=0){return (num1/num2);}
    else{return 0;}
}

int choosing(float arg1, int arg2)
{
    return arg2;
}

int call_a_func(int (*call_this)(float, int))
{
    int output = call_this(5.5, 7);
    return output;
}

typedef int (*ChoosingFunc)(float, int);

int call_a_func_by_typedef(ChoosingFunc call_this)
{
    int output = call_this(5.5, 7);
    return output;
}

void * square(const void *num) //void type pointer as argument
{
    int result;
    result=(*(int *)num)*(*(int *)num);
    return result;
}

int compare(const void *elem1,const void *elem2)
{
    if((*(int *)elem1)==(*(int *)elem2)){return 0;}
    else if((*(int *)elem1)<(*(int *)elem2)){return -1;}
    else{return 1;}
}

/******************************************/

int main()
{
    char str1[6]="hello"; //double quotation for string
    char str2[]={'w','o','r','l','d','\0'}; //single quotation and \0 for string
    char *str="stuff"; //string pointer

    /*scanf() stop reading when reaching a space, gets() stop when reaching newline*/
    char full_name[50];
    printf("Enter your full name : ");
    fgets(full_name,50,stdin); //stdin means to read from standard input
    fputs(full_name,stdout); //stdout refers to the standard output

    char info[100];
    char dept[]="HR";
    int emp=75;
    sprintf(info,"The %s dept has %d employees.",dept,emp); //a formatted string is created
    printf("%s\n",info);
    char infor[]="Snoqualmie WA 13190";
    char city[50];
    char state[50];
    int population;
    sscanf(infor,"%s %s %d",city,state,&population); //separate from a formatted string
    printf("%d people live in %s, %s.\n",population,city,state);

    char input[10]="10hey";
    int num;
    num=atoi(input); //convert str to int value, return 0 if the first is not
    printf("%d\n",num); 
    /*
    atof(str); //convert str to double value
    atol(str); //convert str to long int value
    */

    char s1[]="The grey fox";
    char s2[]=" jumped";
    char c='c';
    printf("strlen is %d\n",strlen(s1)); //get length of a string, not including NULL
    strcat(s1,s2); //merge s2 to the end of s1 and return pointer to s1
    printf("%s\n",s1);
    strcpy(s1,s2); //copy s2 to s1
    printf("%s\n",s1);
    printf("%d\n",strcmp(s1,s2)); // compare two strings, return 0 when s1 equal s2
    printf("0X %x\n",strchr(s1,c)); //return char pointer to the first occurrence of c in s1 or NULL if not
    printf("0X %x\n",strstr(s1,s2)); //return char pointer to the first occurrence of s2 in s1 or NULL if not 
    /*
    strlwr(); //convert string to lower case
    strupr(); //convert string to upper case
    strrev(); //reverse string 
    */

    char trip[3][15]= //multi-dimension of string
    {
        "suitcase",
        "passport",
        "ticket"
    };
    printf("%c\n",trip[2][3]);
    char *trips[]= //multi-dimension of pointer for string, needed []
    {
        "suitcase",
        "passport",
        "ticket"
    };
    for(int i=0;i<3;i++){printf("%s\n",trips[i]);}


    void (*funptr) (int); //function pointer declare
    funptr=say_hello; //function pointer assign
    funptr(3); //function pointer call
    
    int (*op[4]) (int,int); //array of function pointer declare
    op[0]=add;
    op[1]=subtract;
    op[2]=multiply;
    op[3]=divide;
    printf("%d\n",op[0](10,2));
    printf("%d\n",op[1](10,2));
    printf("%d\n",op[2](10,2));
    printf("%d\n",op[3](10,2));

    int final_result1 = call_a_func(choosing);
    int final_result2 = call_a_func_by_typedef(choosing); //typedef of function pointer for arg
    printf("%d %d\n", final_result1, final_result2);

    void *ptr; //void type pointer can refer to any address
    int x=33;
    float y=12.3;
    char z='z';
    ptr=&x;
    printf("%d\n",*((int *)ptr));
    ptr=&y;
    printf("%f\n",*((float *)ptr));
    ptr=&z;
    printf("%c\n",*((char *)ptr));
    printf("x squared is %d\n",square(&x)); //accept any type of data returned

    int arr[5]={52,23,56,19,4};
    int nums,width;
    nums=sizeof(arr)/sizeof(arr[0]); //get the number of elements
    width=sizeof(arr[0]);
    qsort((void *)arr,nums,width,compare); //quick sort use function pointer as argument
    for(int i=0;i<5;i++){printf("sorted data %d\n",arr[i]);}

    return 0;
}