// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode *curr = head,*prev = NULL;
        
        while (curr and size<k){
            size++;
            curr = curr->next;
        }
        
        if (size<k){
            return head;
        }
        
        curr = head;
        int reversed = 0;
        while (reversed<k){
            ListNode *temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
            reversed++;
        }
        
        ListNode *smallrev = reverseKGroup(curr,k);
        head->next = smallrev;
        
        return prev;
        
        
    }
};