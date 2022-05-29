
#define SIZE 5 
void printarr(int *arr,int n) 
{ 
    for(int i=0;i<n;i++) 
    { 
        printf("%d\t",arr[i]); 
    } 
    printf("\n"); 
} 
void bubble_sort(int *arr,int n) 
{ //sort from less to most 
    for(int i=0;i<n-1;i++)
    { 
        for(int j=0;j<n-1-i;j++) 
        { 
            if(arr[j]>arr[j+1]) //must move the most to the right 
            { 
                int temp=arr[j]; 
                arr[j]=arr[j+1]; 
                arr[j+1]=temp; 
            } 
        } 
    } 
} 
void selection_sort(int * arr,int len) 
{ //sort from less to most 
    int i,j,temp; 
    for(i=0;i<len-1;i++) 
    { 
        int min=i; //suppose min  
        for(j=i+1;j<len;j++) //unsorted part 
        { 
            if(arr[j]<arr[min]) 
            { 
                min=j; //update min so far 
            } 
        } 
        if(min!=i) //swap min 
        { 
            temp=arr[min]; 
            arr[min]=arr[i]; 
            arr[i]=temp; 
        } 
    } 
} 
void insertion_sort(int * arr, int len) 
{ //sort from less to most 
    int i,j,key; 
    for(i=1;i<len;i++) //unsorted part 
    { 
        key=arr[i]; //value need to be inserted 
        j=i-1; 
        while((j>=0)&&(arr[j]>key)) 
        { 
            arr[j+1]=arr[j]; //search & move previous elements 
            j--; 
        } 
        arr[j+1]=key; //insert value 
    } 
} 
void merge_sort(int arr[],int len)
{ //sort from less to most 
    int *a=arr; 
    int *b=(int*)malloc(len * sizeof(int)); 
    int seg, start; 
    for(seg=1;seg<len;seg+=seg) //n elements as a segment 
    { 
        for(start=0;start<len;start+=seg*2) //compare adjacent segments 
        { 
            int low=start; 
            int mid=( (start+seg)<(len)?(start+seg):(len) ); 
            int high=( (start+seg*2)<(len)?(start+seg*2):(len) ); 
            int k=low; 
            int start1=low, end1=mid; 
            int start2=mid, end2=high; 
            while(start1<end1 && start2<end2) //sort and insert 
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++]; 
            while(start1<end1) 
                b[k++] = a[start1++]; 
            while(start2<end2) 
                b[k++] = a[start2++]; 
        } 
        int *temp=a; //swap temporary for next comparasion 
        a=b; 
        b=temp; 
    } 
    if(a!=arr) //check for returning true arr 
    { 
        int i; 
        for(i=0;i<len;i++) 
            b[i]=a[i]; 
        b=a; 
    } 
    free(b); 
}
void merge_sort_recursive(int *arr,int len)
{
    if(len<2) return;
    int mid=len/2;
    int *left=(int*)malloc((mid)*sizeof(int));
    int *right=(int*)malloc((len-mid)*sizeof(int));
    for(int i=0;i<mid;i++){left[i]=arr[i];}
    for(int i=mid;i<len;i++){right[i-mid]=arr[i];}

    merge_sort_recursive(left,mid);
    merge_sort_recursive(right,len-mid);

    int i=0,j=0,k=0;
    while(i<mid && j<(len-mid))
    {
        if(left[i]<=right[j]){arr[k++]=left[i++];}
        else{arr[k++]=right[j++];}
    }
    while(i<mid){arr[k++]=left[i++];}
    while(j<(len-mid)){arr[k++]=right[j++];}
}
typedef struct _Range
{ 
    int start, end; 
} Range; 
Range new_Range(int s,int e)
{ 
    Range r; 
    r.start=s; 
    r.end=e; 
    return r; 
} 
void swap(int *x, int *y) 
{ 
    int t=*x; 
    *x = *y; 
    *y = t; 
} 
void quick_sort(int arr[],int len) 
{ 
    if(len<=0){return;} 
    // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素 
    Range r[5]; //r[len]
    int p=0; 
    r[p++]=new_Range(0,len-1); 
    while(p) 
    { 
        Range range=r[--p]; 
        if(range.start>=range.end){continue;} 

        int mid=arr[(range.start+range.end)/2]; //use mid as pivot 
        int left=range.start, right=range.end; 
        do { 
            while(arr[left]<mid){++left;} //check left  
            while(arr[right]>mid){--right;} //check right 
            if(left<=right) 
            { 
                swap(&arr[left],&arr[right]); //swap two found elements once 
                left++; 
                right--; 
            } 
        } while(left<=right); 
        if(range.start<right){r[p++]=new_Range(range.start,right);} //set new left division
        if(range.end>left){r[p++]=new_Range(left, range.end);} //set new right division
    } 
} 
void quick_sort_recursive(int *number, int lowIndex, int highIndex)
{
    if(lowIndex < highIndex)
    {
        int pivot = number[(lowIndex+highIndex)/2];
        int left = lowIndex;
        int right = highIndex;

        while(1)
        {
            while(number[left] < pivot) left++;
            while(number[right] > pivot) right--;

            if(left >= right) break;

            int temp=number[left];
            number[left]=number[right];
            number[right]=temp;
            
            if(number[left]==pivot && number[right]==pivot) left++;
        }

        quick_sort_recursive(number, lowIndex, left-1);
        quick_sort_recursive(number, right+1, highIndex);
    }
}