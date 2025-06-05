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
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
                
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
                
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return ans->next;
    }
};