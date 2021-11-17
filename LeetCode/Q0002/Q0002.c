/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int sum=0;
    struct ListNode * result=NULL;
    struct ListNode * curr=(struct ListNode *)malloc(sizeof(struct ListNode));
    result=curr;
    while(l1!=NULL || l2!=NULL || sum>0)
    {
        if(l1!=NULL)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        struct ListNode * node;
        node=(struct ListNode *)malloc(sizeof(struct ListNode));
        node->val=sum%10;
        node->next=NULL;
        curr->next=node;
        curr=node;
        sum/=10;
    }
    return result->next;
}


/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode * result = NULL;
		ListNode ** node = &result;
		int sum = 0;

		while (l1 != NULL || l2 != NULL || sum > 0)
		{
			if (l1 != NULL)
			{
				sum = sum + l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				sum = sum + l2->val;
				l2 = l2->next;
			}
			(*node) = new ListNode(sum % 10);
			node = &((*node)->next); 
			sum = sum / 10;
		}
		return result;
	}
};
*/