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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next; // This keeps a track of next element
            head->next = prev; // When reversing, we need to point it to prev
            prev = head; // For next iteration, prev will be changed to head (current)
            head = next; // And, head moves to next (next element)
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* iter = head;
        int carry = 0;
        while(iter){
            int sum = 0;
            sum = iter->val * 2;
            sum += carry;
            iter->val = sum % 10;
            carry = sum / 10;
            if(iter->next)
                iter = iter->next;
            else
                break;
        }
        if(carry != 0){
            ListNode* temp = new ListNode(carry);
            iter->next = temp;
        }
        
        head = reverseList(head);
        return head;
    }
};