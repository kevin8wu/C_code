
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double result;
    int tmpA=0,tmpB=0;
    int i=0,n1=0,n2=0;
    
    while(i<(nums1Size+nums2Size)/2+1)
    {
        if(n1==nums1Size && n2<nums2Size){tmpA=tmpB;tmpB=nums2[n2]; n2++;}
        else if(n1<nums1Size && n2==nums2Size){tmpA=tmpB;tmpB=nums1[n1]; n1++;}
        else
        {
            if(nums1[n1]<=nums2[n2]){tmpA=tmpB;tmpB=nums1[n1]; n1++;}
            else{tmpA=tmpB;tmpB=nums2[n2]; n2++;}
        }
        i++;
    }
    
    if((nums1Size+nums2Size)%2==1){result=tmpB;}
    else{result=(tmpA+tmpB)/2.0;}
    
    return result;
}

/*
class Solution
{
public:
    double findMedianSortedArrays
    (vector<int>& nums1, vector<int>& nums2)
    {
        int odd;
		int n1=0;
		int n2=0;
		int tempA=0,tempB=0;
		int i=0,k1=0,k2=0;
		
        if(!nums1.empty()){n1=nums1.size();}
        if(!nums2.empty()){n2=nums2.size();}
        
		if((n1+n2)%2==1){odd=1;}
		else{odd=0;}
		
		while(i<(n1+n2)/2+1)
		{
			if(k2==n2 || k1==n1)
			{
				if(k1<n1 && k2==n2)
				{
					tempA=tempB;tempB=nums1[k1];
					i++;k1++;
				}
				else if(k1==n1 && k2<n2)
				{
					tempA=tempB;tempB=nums2[k2];
					i++;k2++;
				}
                else{return 0;}
			}
			else
			{
				if(nums1[k1]<nums2[k2])
				{		
					tempA=tempB;tempB=nums1[k1];
					i++;k1++;
				}
				else if(nums1[k1]>nums2[k2])
				{
					tempA=tempB;tempB=nums2[k2];
					i++;k2++;
				}
				else
				{
					//tempA=nums1[k1];tempB=nums2[k2];
					//i=i+2;k1++;k2++;
                    tempA=tempB;tempB=nums1[k1];
					i++;k1++;
				}
			}
		}
		
		if(odd==1)
        {
            double result=tempB;
            return result;
        }
		else
        {
            double result=(tempA+tempB)/2.0;
            return result;
        }
    }
};
*/