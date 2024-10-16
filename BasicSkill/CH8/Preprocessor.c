#include <stdio.h>
#include <string.h>
//#include <time.h> //date/time utility
/*user-defined header file need "mylib.h" to mark*/

#define PI 3.14
#define AREA(r) (PI*(r)*(r))
#define very_long_const_to_next_line \
        23.678

/*
storage |=  (1<<n); //set bit
storage &= ~(1<<n); //clear bit
storage ^=  (1<<n); //flip bit
*/

int main()
{
    /*
    #define #undef
    #ifdef  #ifndef
    #if #elif #else #endif
    #pragma
    #error //output error message and halt compilation
    #warning //output warning message
    */
    float radius=2;
    printf("%3.2f\n",PI);
    printf("Area is %5.2f\n",AREA(radius));

    /******************************************/

    /*standard predefined macros*/
    //__DATE__  the current date as string in mm dd yyyy
    //__TIME__  the current time as string in hh:mm:ss
    //__FILE__  the current filename as string
    //__LINE__  the current line number as int 
    //__STDC__  define 1 if file is standard C program
    //__cplusplus   define 1 if file use C++ compiler
    //__OBJC__      define 1 if file use Object-C compiler
    //__ASSEMBLER__ define 1 if file use preprocess assembly
    //__VERSION__   return version of compiler
    //__FUNCTION__ the current function name as string
    char curr_date[12];
    char curr_time[10];
    int std_c;
    strcpy(curr_date,__DATE__);
    strcpy(curr_time,__TIME__);
    printf("%s %s\n",curr_time,curr_date);
    printf("This is line %d\n",__LINE__);
    std_c=__STDC__;
    printf("STDC is %d\n",std_c);
    printf("Version: %s\n",__VERSION__);

    /******************************************/

    /*the # operator in definition*/
        //it called stringification or stringizing operator
        //convert a parameter to string constant
        //ignore white space on both sides
        //recognize escape chars
    /*the ## operator in definition*/
        //it called token pasting operator
        //it append(past) token together as name of variable
    #define TO_STR(x) #x
    printf("convert to string %s\n",TO_STR(123\\12)); //convert to string 123\12
    #define VAR(name,num) name##num
    int x1=125,x2=250,x3=500;
    printf("pasting together to display value %d\n",VAR(x,1)); 
    printf("pasting together to display value %d\n",VAR(x,2)); 
    printf("pasting together to display value %d\n",VAR(x,3)); 

    /******************************************/

    return 0;
}