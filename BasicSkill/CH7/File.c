#include <stdio.h> //contain file handling function
#include <stdlib.h> //contain exit command
#include <math.h>
//#include <errno.h> //for errno
extern int errno; //declare if not include errno.h

int main()
{
    /*fopen(filename,mode);*/
        //r  open for reading if file exists
        //w  open for writing
        //a  open for append
        //r+ open for reading and writing from beginning
        //w+ open for reading and writing, overwriting file
        //a+ open for reading and writing, appending to file 
    /*fclose(fptr);*/
    FILE * fptr; //declare the file pointer
    #if 1
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\myfile.txt","w"); //notice filename contain "\\"
    if(fptr==NULL) //if opening fail, return NULL
    {
        printf("Error in opening file");
        return -1; //force to stop
    }
    fclose(fptr); //return 0 if close successful, return EOF if close error
    #endif
    
    /******************************************/

    /*fputc(char,fptr);*/
        //write char to file
    /*fputs(str,fptr);*/
        //write string to file
    /*fprintf(fptr,str,vars);*/
        //print str and vars to file
    /*'\n' must be added explicitly when writing to file*/
    #if 1
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\myfile.txt","w");
    fprintf(fptr,"Inventory\n");
    fprintf(fptr,"%d %s  %f\n",100,"Widget",0.29);
    fputs("End of List",fptr);
    fputc('s',fptr);
    fclose(fptr);
    #endif

    /******************************************/

    /*fgetc(fptr);*/ 
        //return next char 
        //return EOF(-1) if reach the end of file
    /*fgets(buff,n,fptr);*/ 
        //read n-1 chars, append \0 behind and store in buff 
        //stop reading when encountering \n or the end of file
    /*fscanf(fptr,conversion_specifier,varptr);*/
        //read char and assign to variable pointer by specifier
        //stop reading when encountering space or \n
    #if 1
    int c, stock;
    char buffer[200],item[10];
    float price;
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\myfile.txt","r");
    fgets(buffer,20,fptr); //read a line within \n automatically
    printf("%s",buffer);
    fscanf(fptr,"%d %s %f",&stock,item,&price); //read data only
    printf("%d %s %f\n",stock,item,price);
    while((c=fgetc(fptr))!=EOF) //read a char by ASCII
    {
        /*10 for LF; 13 for CR*/
        if(c==10 || c==13){printf("final %d\n",c);}
        else{printf("final %c\n",c);} 
    } 
    fclose(fptr);
    #endif

    /******************************************/

    /*binary file*/
        //rb  open for reading if file exists
        //wb  open for writing
        //ab  open for append
        //rb+ open for reading and writing from beginning
        //wb+ open for reading and writing, overwriting file
        //ab+ open for reading and writing, appending to file
    /*fwrite(ptr,item_size,num_items,fptr);*/
        //write num_items items in size item_size from ptr to file
    /*fread(ptr,item_size,num_items,fptr);*/
        //read num_items items in size item_size from file to ptr
    /*.bin for binary data; .csv for comma separated value; .dat for data file*/
    int arr[10];
    int x[10];
    for(int i=0;i<10;i++){arr[i]=i;}
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\datafile.bin","wb");
    fwrite(arr,sizeof(arr[0]),sizeof(arr)/sizeof(arr[0]),fptr);
    fclose(fptr);
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\datafile.bin","rb");
    fread(x,sizeof(arr[0]),sizeof(arr)/sizeof(arr[0]),fptr);
    fclose(fptr);
    for(int i=0;i<10;i++){printf("%d",x[i]);}printf("\n");

    /******************************************/

    /*file pointer*/
        //indicate the position in file
    /*ftell(fptr);*/
        //return N bytes for file pointer position from the start of file
    /*fseek(fptr,num_bytes,from_pos);*/
        //move file pointer position by num_bytes relative to from_pos
        //SEEK_SET the start of file(0)
        //SEEK_CUR the current position of file(1)
        //SEEK_END the end of file(2)
    typedef struct
    {
        int id;
        char name[20];
    }items;
    items first,second,secondf;
    first.id=10276;
    strcpy(first.name,"Widget");
    second.id=11786;
    strcpy(second.name,"Gadget");
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\info.dat","wb");
    fwrite(&first,sizeof(first),1,fptr);
    fwrite(&second,sizeof(second),1,fptr);
    fclose(fptr);
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\info.dat","rb");
    fseek(fptr,1*sizeof(items),SEEK_SET);
    fread(&secondf,sizeof(items),1,fptr);
    printf("%d %s\n",secondf.id,secondf.name);
    fclose(fptr);

    /******************************************/

    /*exit command*/
        //EXIT_FAILURE(1)
        //EXIT_SUCCESS(0)
    #if 1
    int varx=10;
    int vary=2;
    if(vary!=0){printf("x/y=%d\n",varx/vary);}
    else
    {
        printf("Divisor is 0. Program exit\n");
        exit(EXIT_FAILURE);
    }
    #endif

    /******************************************/

    /*error code*/
        //usually set in global variable
    /*errno*/
        //store error information for error code
        //EDOM 33: error when domain is out of range
        //ERANGE 34: error when range is out of memory
    /*stderr*/
        //file stream "standard error output" for error code
    /*strerror*/
        //get more message for error code by string.h
    /*perror*/
        //get more message for error code
    #if 0
    errno=0; //set 0 before calling lib func
    fptr=fopen("C:\\Users\\Kevin\\Desktop\\nonexit.txt","r");
    if(fptr==NULL)
    {
        fprintf(stderr,"Error opening file. Error code: %d\n",errno);
        fprintf(stderr,"%s\n",strerror(errno));
        perror("Error");
        exit(EXIT_FAILURE);
    }
    fclose(fptr);
   
    float result;
    errno=0;
    result=sqrt(-5.0);
    if(errno==0){printf("%f",result);}
    if(errno==EDOM){fprintf(stderr,"%s\n",strerror(errno));}
    errno=0;
    result=exp(1000.0);
    if(errno==0){printf("%f",result);}
    if(errno==ERANGE){fprintf(stderr,"%s\n",strerror(errno));}
    #endif
    /*feof(fptr)*/
        //return nonzero value if reaching the end of file, 0 for others
    /*ferror(fptr)*/
        //return nonzero value if error, 0 for no error
    if(feof(fptr)){printf("End of file");}
    if(ferror(fptr))
    {
        printf("I/O error");
        exit(EXIT_FAILURE);
    }

    /******************************************/

    return 0;
}