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
    
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
      
        if(l1->val >= l2->val)
        {
            ListNode * temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        ListNode* res = l1;
        
        while(l2 != NULL && l1 != NULL)
        {
            ListNode * temp = NULL;
            while(l1 != NULL && l2->val >= l1->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp -> next = l2;
            
            ListNode * tem = l1;
            l1 = l2;
            l2 = tem;
            
        }
        return res;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
      if (lists.size() == 0) return NULL;
        
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++)
            head = mergeTwoLists(head, lists[i]);
        
        return head;
    }
};