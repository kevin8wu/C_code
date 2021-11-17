#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int size;
    char * infor;
}record;

char * convert(char * s, int numRows)
{
    //determine for special conditions
    if(s==NULL){return s;}
    if(numRows<=1 || numRows>=strlen(s)){return s;}

    //init a container to record each row
    record *records;
    records=calloc(numRows,sizeof(record));
    for(int i=0; i<numRows; i++)
    {
        records[i].size=1;
        records[i].infor=malloc(sizeof(char));
        memset(records[i].infor, 0, records[i].size);
    }

    for(int i=0,num=0,dir=-1;i<strlen(s);i++)
    {
        //determine if memory size is full
        if(records[num].infor[records[num].size-1] != 0)
        {
            records[num].infor=realloc(records[num].infor,records[num].size+1);
            if(records[num].infor != NULL)
            {
                records[num].size += 1;
            }       
        }

        //assign dedicated char data
        records[num].infor[records[num].size-1]=s[i];

        //determine if need to change the direction
        if(num==0 || num==numRows-1)
        {
            if(dir==1){dir=-1;}
            else{dir=1;}
        }
        num+=dir;
    }

    //init a container to record final result
    int result_size=0;
    char * result=(char *)malloc(strlen(s));
    memset(result,0,strlen(s)); 

    for(int i=0;i<numRows;i++)
    {
        //strcat(result,records[i].infor);
        memcpy(result+result_size, records[i].infor, records[i].size);
        result_size+=records[i].size;
    }

    free(records);

    return result;
}

/*
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows<=1 || numRows>=s.size()){return s;}
        if(s.empty()){return "";}
        vector<string> rows(numRows);
        for(int i=0,num=0,dir=-1;i<s.size();i++)
        {
            rows[num]+=s[i];
            if(num==0 || num==numRows-1)
            {
                if(dir==1){dir=-1;}
                else{dir=1;}
            }
            num=num+dir;
        }
        string result;
        for(int i=0;i<numRows;i++)
        {
            result.insert(result.size(),rows[i]);
        }
        return result;
    }
};
*/

int main()
{
    char * input="PAYPALISHIRING";

    printf("%s\n",convert(input,3));
    
    return 0;
}