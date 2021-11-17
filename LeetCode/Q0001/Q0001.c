/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize=2;
    int * result=NULL;
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(target==nums[i]+nums[j])
            {
                result=(int *)malloc((*returnSize)*sizeof(int));
                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
    return result;
}
*/

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize=2;
    int * map=malloc(2*sizeof(int));
    map[0]=nums[0];
    map[1]=0;
    for(int j,i=1;i<numsSize;i++)
    {
        for(j=0;j<i*2;j=j+2)
        {
            if(target-nums[i]==map[j])
            {
                int * result=malloc((*returnSize)*sizeof(int));
                result[0]=map[j+1];
                result[1]=i;
                free(map);
                return result;
            }
        }
        map=realloc(map,2*(i+1)*sizeof(int));
        map[j]=nums[i];
        map[j+1]=i;
    }
    return NULL;
}
*/

struct dataMap
{
    int value;
    int index;
};
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize=2;
    struct dataMap *map=calloc(1,sizeof(struct dataMap));
    map->value=nums[0];
    map->index=0;
    for(int j,i=1;i<numsSize;i++)
    {
        for(j=0;j<i;j++)
        {
            if(target-nums[i]==map[j].value)
            {
                int * result=malloc((*returnSize)*sizeof(int));
                result[0]=map[j].index;
                result[1]=i;
                free(map);
                return result;
            }
        }
        map=realloc(map,(i+1)*sizeof(struct dataMap));
        map[j].value=nums[i];
        map[j].index=i;
    }
    return NULL;
}

/*
class Solution 
{
private:
    vector<int> result;
    map<int,int> table;
    map<int,int>::iterator it;
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i=0;i<nums.size();i++)
        {
            it=table.find(target-nums[i]);
            if(it!=table.end())
            {
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            else
            {
                table.insert({nums[i],i});
            }
        }
        return result;
    }
};
*/