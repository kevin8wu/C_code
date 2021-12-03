#include <stdio.h>

#define pi 3.1415926

/* self-defined boolean
#define BOOL char
#define FALSE 0
#define TRUE 1
*/

int main()
{
    //gcc HelloWorld.c -o HelloWorld
    //.\HelloWorld

    /******************************************/ 
    //data type
    
    printf("Hello World!\n");
    printf("\"Hey\" 100%%\n"); //escape char

    printf("boolean is not supported!\n");
    printf("int: %d\n",sizeof(int));
    printf("float: %d\n",sizeof(float));
    printf("double: %d\n",sizeof(double));
    printf("char: %d\n",sizeof(char));

    int a=8;
    float b=52.11;
    double c=15.32;
    char d='A';
    printf("%d\n",22); 
    printf("%d\n",a);
    printf("%f\n",b);
    printf("%f\n",c);
    printf("%c\n",d);
    printf("%d\n",d); //change to the ASCII
    printf("%s\n","apple"); //directly assign a string

    const double PI=3.14;
    printf("%f\n",PI);
    printf("%f\n",pi); //define by preproccessor
    
    float avg;
    int total=23,count=4;
    avg=total/count;
    printf("%f\n",avg);
    avg=(float)total/count; //type casting
    printf("%f\n",avg);

    //typedef for fundamental data type
    typedef int km_per_hour;    //typedef BaseType NewType
    km_per_hour current_speed;  //"km_per_hour" is synonymous with "int"

    //typedef for array data type
    typedef char arrType[6];    //typedef BaseType NewType [arrSize]
    arrType arr={1,2,3,4,5,6};  //same as: char arr[6]={1,2,3,4,5,6}
    arrType *pArr;              //same as: char (*pArr)[6]

    //typedef for pointer data type
    typedef int *intptr;        //typdef BaseType* NewType
    intptr ptr;                 //same as: int *ptr

    /******************************************/
    //input & output

    //if exits data in buffer, catch next matching data
    
    /*
    printf("plz enter a char >\n");
    char aa=getchar(); //get a single char
    printf("You entered: %c\n",aa);
    
    printf("plz enter a string >\n");
    char bb[10];
    gets(bb); //get string, a sequence of char
    printf("You entered: %s\n",bb);
    
    printf("plz enter a char >\n");
    char aaa=getchar();
    printf("You entered: ");
    putchar(aaa); //only print char
    printf("\n");
    
    printf("plz enter a string >\n");
    char bbb[10];
    gets(bbb);
    printf("You entered: ");
    puts(bbb); //only print string
    printf("\n");
    */

    printf("plz enter a int >\n");
    int intnum;
    scanf("%d",&intnum); //scan matching input & store in addr
    printf("You entered: %d\n",intnum);
    
    printf("plz enter two int >\n");
    int int1,int2;
    scanf("%d %d",&int1,&int2); //stop reading if encounter space or mark
    printf("Sum: %d\n",int1+int2); //calculate in arg ; operator % for remainder of int division
    
    printf("plz enter a float, a char, and a string >\n");
    float num;
    char word;
    char text[10];
    scanf("%f %c %s",&num,&word,text); //the name of string represent the addr
    printf("You entered: %f %c %s\n",num,word,text);

    printf("plz enter a int-2d, a int-d, a float-*f, and a string-5s >\n");
    int x,y;
    char texts[10];
    scanf("%2d %d %*f %5s",&x,&y,texts); //%[*][-][max_width].[precision]type ; * for ignored ; - for left align
    printf("%d %d %s",x,y,texts); //%e for scientific notation ; %x for hex

    /******************************************/
    

    return 0;
}