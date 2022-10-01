// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head = new ListNode();
        struct ListNode *result = head;
        struct ListNode *prev = NULL;
        int carry = 0;
        while (l1 && l2){
            
                
            int sum = l1->val+l2->val+carry;
            
            head->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            head->next = new ListNode();
            prev = head;
            head = head->next;
            
        }
        
        while (l1){
             int sum = l1->val+carry;
            
            head->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
            
             head->next = new ListNode();
             prev = head;
            head = head->next;
        }
        
        while (l2){
             int sum = l2->val+carry;
            
            head->val = sum%10;
            carry = sum/10;
            l2 = l2->next;
            
             head->next = new ListNode();
             prev = head;
            head = head->next;
        }
        
        if (!carry){
            prev->next = NULL;
        } else {
            head->val = carry;
        }
        
        
        return result;
    }
};