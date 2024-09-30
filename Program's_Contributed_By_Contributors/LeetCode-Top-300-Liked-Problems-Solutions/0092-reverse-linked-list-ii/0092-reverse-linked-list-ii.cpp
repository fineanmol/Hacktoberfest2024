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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; // prev should be always before the left. So handle a edge case like left is the head start itself, prev is before that now

        for(int i = 0; i < left - 1; i++)
            prev = prev->next;
        
        ListNode* cur = prev->next;

        for(int i = left; i < right; i++){
            ListNode* nex = cur->next;
            cur->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
        }

        return dummy->next;
    }
};