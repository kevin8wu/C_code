//2020/01/09 奕力
int find_second_max(int a[],int len)
{
    int *p=a;
    int Fmax,Smax;
    if(len<=2){return 0;}
    if(a[0]>a[1])
    {
        Fmax=a[0];Smax=a[1];
    }
    else
    {
        Fmax=a[1];Smax=a[0];
    }
    for(int i=2;i<len;i++)
    {
        if(a[i]>=Fmax)
        {
            Smax=Fmax;
            Fmax=a[i];
        }
        else if(a[i]>=Smax)
        {
            Smax=a[i];
        }
        else
        {
            continue;
        }
    }
    return Smax;
}
void swap(int *a, int *b) //call by ref is only for C++
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
