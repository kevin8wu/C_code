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
    int result_num;
    avg=total/count; //5.00
    printf("%f\n",avg); 
    avg=(float)total/count; //type casting, 5.75
    printf("%f\n",avg);
    total=-23;
    avg=total/count; //-5.00
    printf("%f\n",avg); 
    avg=(float)total/count; //type casting, -5.75
    printf("%f\n",avg);
    avg=12.45;
    result_num=avg; //type casting, 12
    printf("%d\n", result_num);
    avg=-12.45;
    result_num=avg; //type casting, -12
    printf("%d\n", result_num);

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

    /*
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
    */

    /******************************************/
    

    return 0;
}

#if 0
# gcc options

gcc [option] filename

>option
-E : output .i file; preprocess only; no compile, assemble, link; 
-S : output .s file; compile only; no assemble, link;
-c : output .o file; compile and assemble only; no link;
-g : compile and assembly with error infor by GDB
-o [filename] : place output into [filename]
-ansi : program by ansi c standard
-shared : create a shared library
-D[macro] : enable defined macro
-D[marco=defn] : make defined macro as "defn"
-U[macro] : disable defined macro
-fsanitize=address : a fast memory error detector from google
-fsanitize=thread -pthread : data race detector from google 
-fsanitize=undefined : a fast undefined behavior detector from google 
-fsanitize=leak : memory leak detector from google 

-Wp,option : pass options to preprocessor
-Wa,option : pass options to assembler
-Wl,option : pass options to linker
-I : 追加include檔案的搜尋路徑
-L : 追加library檔案的搜尋路徑
-l : 指定動態連結的函式庫
-Wall : display all warnning infor
-w : disable all warnning infor
-O0 : no any optimization
-O1 : initial optimization
-O2 : advanced optimization

build-M1:
$ gcc HelloWorld.c -o HelloWorld
build-M2:
$ gcc -E hello.c -o hello.i //preprocess
$ gcc -S hello.i -o hello.s //compile
$ gcc –c hello.s –o hello.o //compile & assemble
$ gcc hello.o -o hello.out  //compile & assemble & link   

shared-build:
$ gcc -c -Wall -Werror -fPIC Cshared.c  
$ gcc -shared -o libCshared.so Cshared.o 
$ gcc -l Cshared -o Crunner.out Crunner.c 
$ ldd Crunner.out //show the shared object that program uses
$ man dlopen //check another way to link shared library
$ man dlsym //check another way to get specific symbol in shared library


# the relationship of files

file.c   // c file that has been edited from IDE (source code)
file.i   // i file that has been preprocessed from c file
file.s   // s file that has been compiled from i file (assembly code)
file.o   // o file that has been assembled from s file
file.a   // a file that has been archived from o file
file.out // out file that has been linked from a file


# common standard output format (ELF)

relocatable:    .a   (linux); .a   (embeded); .lib (windows)
shared library: .so  (linux); .bin (embeded); .dll (windows)
executable:     .out (linux); .axf (embeded); .exe (windows)

    ## .bin is kind of .hex as image file to execute or burn into memory 
	## .axf is kind of executable file like .bin, but including debug infor
    ## .elf have different ABI (application binary interface)
        like data type, size, calling convention, endian, o32(MIPS)/eabi(ARM)
#endif