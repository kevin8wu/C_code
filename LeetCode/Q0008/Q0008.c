#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* s) 
{
    
}

/*
class Solution
{
public:
    int myAtoi(string str) 
    {
        int result=0;
        if(str.empty()){return result;}
        vector<int> temp;
        int sign=1;
        int op=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                temp.push_back((int)str[i]);
            }
            else
            {
                if(temp.empty() && op==0)
                {
                    if(str[i]==' '){continue;}
                    else if(str[i]=='-'){sign=-1;op=1;}
                    else if(str[i]=='+'){sign=1;op=1;}
                    else{break;}
                }
                else{break;}
            }
        }
        if(temp.empty()){return result;}
        int num;
        for(int i=0;i<temp.size();i++)
        {
            num=(temp[i]-48)*sign;
            if(result>INT_MAX/10 || (result==INT_MAX/10 && num>7)){return INT_MAX;}
            if(result<INT_MIN/10 || (result==INT_MIN/10 && num<-8)){return INT_MIN;}
            result=result*10+num;    
        }
        return result;
    }
};
*/

int main()
{
    

    return 0;
}