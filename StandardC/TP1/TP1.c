#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> //wide char; wchar_t
#include <stdbool.h> //boolean
#include <stdint.h> //signed or unsigned int
#include <float.h> //FLT_EVAL_METHOD FLT_MIN FLT_MAX FLT_DIG
#include <uchar.h> //unicode; unsigned char
#include <limits.h> //INT_MIN CHAR_MIN
#include <complex.h> //complex number csin ctan __STDC_NO_COMPLEX__ _Complex
#include <time.h>

double circularArea(double r)
{
    const double pi=3.1415926; 
    return pi*r*r;
}

int test_func(char *s)
{
    if(s==NULL)
    {
        fprintf(stderr,"%s: received null pointer argument\n",__func__);
        return -1;
    }
}

struct Node
{
    int value;
    struct Node *next;
};
void printNode(const struct Node *ptrNode)
{
    printf("%d\t",ptrNode->value);
}
int printList(struct Node *first)
{
    struct Node * ptr=first;
    while(ptr!=NULL)
    {
        printNode(ptr);
        ptr=ptr->next;
    }
}

enum {off,on,stop=0,go=1,closed=0,open=1};
enum color
{
    //using comma
    //0 1 2 3 4 7 8
    black,red,green,yellow,blue,white=7,gray
}; //need column comma
enum color bgColor=blue,fgColor=yellow;
void setFgColor(enum color fgc);
void setBgColor(enum color bgc);

int main()
{
    double radius=1.0,area=0.0;
    printf("radius\tArea\n");
    area=circularArea(radius);
    printf("%5.1f\t%5.4f\n",radius,area);
    printf("------------------------\n");

    /*wide char can be divided into big-endian and little-endian*/

    wchar_t wc=0x03B1; //wchar_t wc='\x3b1'; symbol alpha
    printf("%c %d\n",wc,wc);
    wc=';';
    printf("%c %d\n",wc,wc);
    char16_t w16;//='\uFFFF'; //__STDC_UTF_16__
    char32_t w32;//='\U0000FFFF'; //__STDC_UTF_32__
    printf("%d\t%d\t%d\n",sizeof(wc),sizeof(w16),sizeof(w32));

    wchar_t w=L'a'; //_t indicate type
    char mbStr[5]="";
    int nBytes=0;
    printf("%c %d\n",w,w);
    nBytes=wctomb(mbStr,w); //c16rtomb() for char16_t; c32rtomb() for char32_t
    printf("%d\n",nBytes);
    printf("%c %d\n",w,w);
    printf("%s %d\n",mbStr,mbStr[0]);

    bool flag; //_Bool
    flag=true;

    /*int short long char float double*/
    /*unsigned char signed char*/

    /*UINT_MAX UCHAR_MAX*/

    printf("the type char is %s.\n",CHAR_MIN<0?"signed":"unsigned");
    printf("char\t%8zu\t%20d\t%20d.\n",sizeof(char),CHAR_MIN,CHAR_MAX);
    printf("int\t%8zu\t%20d\t%20d.\n",sizeof(int),INT_MIN,INT_MAX);

    printf("storage size %d \nmin %e \nmax %e \nprecision %d digits \n",
        sizeof(float),FLT_MIN,FLT_MAX,FLT_DIG);
    
    //float complex
    //float _Complex
    //double _Complex
    double complex z=1.0+2.0*I; //CMPLX(1.0,2.0)
    z*=I;
    //float imaginary
    //double imaginary

    printf("%d\t%d\n",stop,go);

    int randN[3];
    srand((unsigned)time(NULL)); //initialize random generator
    for(int i=0;i<3;i++) 
    {
        randN[i]=rand()%10000; //store random number
        printf("%d\t",randN[i]);
    } 
    

    return 0;
}