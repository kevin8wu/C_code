
char* strrevs(char* s)  
{  
    //h指向s的頭部 
    char* h = s;      
    char* t = s;  
    char ch;  
    // t指向s的尾部 
    while(*t++){;}
    t--;    // 與t++抵消 
    t--;    // 回跳過結束符'\0' 
    // 當h和t未重合時，交換它們所指向的字元 
    while(h < t)  
    {  
        ch = *h;  
        *h++ = *t;    // h向尾部移動 
        *t-- = ch;    // t向頭部移動 
    }  
    return(s);  
} 