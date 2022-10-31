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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        
        ListNode * dummy  = new ListNode;
        ListNode * head = dummy;
        
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                head->next = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        
        if(list1)
        {
            head->next = list1;
        }
        if(list2)
        {
            head->next = list2;
        }
        return dummy->next;
    }
};