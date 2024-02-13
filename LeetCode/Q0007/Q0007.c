#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x)
{

}

/*
class Solution 
{
public:
    int reverse(int x)
    {
        int rev=0,pop;
        if(x==0){return 0;}
        while(x!=0)
        {
            pop=x%10;
            x=x/10;
            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && pop>7)){return 0;}
            if(rev<INT_MIN/10 || (rev==INT_MIN/10 && pop<-8)){return 0;}
            rev=rev*10+pop;
        }
        return rev;
    }
};
*/

int main()
{


    return 0;
}