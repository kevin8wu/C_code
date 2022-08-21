
void steps_method(int max_step)
{
    int count=0;
    for(int i=0;i<=max_step;i++)
    {
        if((max_step-i)%2==0)
        {
            count++;
        }
    }
    printf("you got %d different ways for %d steps\n", count, max_step);
}

void add32()
{
    unsigned char a = 0;
    char b = 0;
    unsigned int c = 0;
    int d = 0;

    for(int i=0;i<8;i++)
    {
        a+=32;
        b+=32;
        c+=32;
        d+=32;
        printf("%d %d %d %d\n", a, b, c, d);
    }
}

int* longestSubArray(int* arr, int len)
{
    int* result;
    int max_count=0;
    int max_index=0;

    for(int i=0;i<len;i++)
    {
        int count=0;
        int cur_value=arr[i];
        
        for(int j=i;j<len;j++)
        {
            if(cur_value<arr[j])
            {
                count++;
                cur_value=arr[j];
            }
        }

        if(count>max_count)
        {
            max_count=count;
            max_index=i;
            printf("count update %d %d\n", max_count, max_index);
        }
    }

    result=malloc(max_count*sizeof(int));
    result[0]=arr[max_index];

    for(int i=max_index,k=0;i<len;i++)
    {
        if(result[k]<arr[i])
        {
            k++;
            result[k]=arr[i];
        }
    }

    for(int i=0;i<max_count;i++)
    {
        printf("%d ",result[i]);
    }
    printf("\n");

    return result;
}