/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(true)
        {
            int minindx = -1;
            ListNode* minNode = NULL;
            for(int i = 0; i < k; i++)
            {
                if(lists[i] != NULL)
                {                  
                    if(minNode == NULL || lists[i]->val < minNode->val)
                    {
                        minNode = lists[i];
                        minindx = i;
                    }
                }
            }
                if(minNode == NULL) break;
                curr->next = minNode;
                curr = curr->next;
                lists[minindx] = lists[minindx]->next;
            
        }
        return dummy->next;
    }
};