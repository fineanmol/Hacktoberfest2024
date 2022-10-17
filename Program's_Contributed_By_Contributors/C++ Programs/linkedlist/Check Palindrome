class Solution {
public:
    ListNode* temp;
    
    bool check(ListNode* head) {
        if (NULL == head) return true;
        bool res = check(head->next) & (temp->val == head->val);
        temp = temp->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};
