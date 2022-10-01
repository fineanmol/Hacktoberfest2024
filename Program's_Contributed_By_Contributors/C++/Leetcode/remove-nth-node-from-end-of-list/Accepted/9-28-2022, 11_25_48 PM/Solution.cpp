// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *curr = head;
        ListNode *slow = NULL;
        
        int count = 1;
        while (curr){
            // cout<<curr->val<<" "<<count<<" "<<n<<endl;
            if (slow){
                slow = slow->next;
            }
            if ((count-1)==n){
                
                slow = head;
            }
            
            curr = curr->next;
            count++;
        }
        
       
        if (!slow){
            return head->next;
        }
        
        
        slow->next = slow->next->next;
        
        return head;
        
        
        
       
        
        
    }
};