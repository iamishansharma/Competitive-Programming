/**
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    public:
            ListNode* removeElements(ListNode* head, int val) 
            {
                if(head == NULL)
                    return head;
                
                ListNode *prev = NULL;
                ListNode *temp = head;
                
                while(temp != NULL)
                {
                    if(temp->val == val)
                    {
                        if(temp == head)
                        {
                            head = head->next;
                            prev = NULL;
                            temp = head;
                        }
                        else
                        {
                            prev->next = temp->next;
                            temp = prev->next;
                        }
                    }
                    else
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                }
                
                return head;
            }
};