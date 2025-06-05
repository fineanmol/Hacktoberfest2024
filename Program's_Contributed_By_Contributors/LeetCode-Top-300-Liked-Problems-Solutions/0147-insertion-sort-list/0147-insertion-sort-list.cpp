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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0); 
        ListNode* cur = head; 
        while (cur) {
            ListNode* prev = dummy;
            ListNode* nex = cur->next; 
            // prev is used to find the position to insert the current node.
            while(prev->next && prev->next->val <= cur->val)
                prev = prev->next;
            // insert the current node to the new list
            cur->next = prev->next;
            prev->next = cur;
            cur = nex; 
        }
        return dummy->next;
    }
};