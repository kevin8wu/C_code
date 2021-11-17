
int Palin(int L,int R,char * s)
{
    int len=0;
    while(L>=0 && R<strlen(s))
    {
        if(s[L]==s[R])
        {
            len=R-L+1;
            L--;
            R++;
        }
        else{break;}
    }
    return len;
}
char * longestPalindrome(char * s)
{
    if(*s==NULL){return "";}
    int start=0,end=0;
    for(int center=0;center<strlen(s)-1;center++)
    {
        int len1=Palin(center, center, s);
        int len2=Palin(center, center+1, s); 
        int len;
        if(len1>=len2){len=len1;}
        else{len=len2;}
        if(len>(end-start+1))
        {
            start=center-(len-1)/2; 
            end=center+len/2; 
        }
    }
    char * result=(char *)calloc(end-start+2,sizeof(char)); 
    for(int j=0,i=start;i<=end;i++,j++){result[j]=s[i];} 
    return result;
}

/*
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if(s.empty() || s.size()<1){return "";}
        int start=0,end=0;
        for(int center=0;center<s.size()-1;center++)
        {
            int len1=Palin(center, center, s);
            int len2=Palin(center, center+1, s);
            int len;
            if(len1>=len2){len=len1;}
            if(len1<len2){len=len2;}
            if((len>end-start+1)) 
            {
                start=center-(len-1)/2;
                end=center+len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
    int Palin(int L,int R,string s)
    {
        int len=0;
        while(L>=0 && R<s.size())
        {
            if(s[L]==s[R])
            {
                len=R-L+1;
                L--;
                R++;
            }
            else{break;}
        }
        return len;
    }
};
*/