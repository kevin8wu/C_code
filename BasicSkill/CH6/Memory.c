#include <stdio.h> 
#include <stdlib.h> //memory management function

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
    *(ptr+30)=75;printf("%d\n",*(ptr+30));
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
    strSmall=malloc((strlen(strBig)+1)*sizeof(char)); //only assign the needed space by strlen 
    strcpy(strSmall,strBig);
    printf("%s\n",strSmall);
    dyn_array arrdyn;
    arrdyn.size=0;
    arrdyn.elements=calloc(1,sizeof(*arrdyn.elements)); 
    arrdyn.cap=1;
    arrdyn.elements=realloc(arrdyn.elements,(5+arrdyn.cap)*sizeof(*arrdyn.elements)); 
    if(arrdyn.elements!=NULL){arrdyn.cap+=5;}
    if(arrdyn.size<arrdyn.cap)
    {
        arrdyn.elements[arrdyn.size]=50;
        printf("%d\n",arrdyn.elements[arrdyn.size]);
        arrdyn.size++;
    }

    /******************************************/
    /*the free does not delete the pointer variable itself, 
    it simply releases the data that it points to.*/
    
    return 0;
}

/*
int nrows = 2;
int ncols = 5;

char **pvowels = (char **) malloc(nrows * sizeof(char *));
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
*/