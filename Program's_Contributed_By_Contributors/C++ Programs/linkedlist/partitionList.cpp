problem name:  Partition List
problem link: https://leetcode.com/problems/partition-list/description/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0); 
        ListNode* a1 = l1;

        ListNode* l2 = new ListNode(0); 
        ListNode* b2 = l2;

        ListNode* current = head;

        while (current) {
            if (current->val < x) {
                a1->next = current;
                a1 = a1->next;
            } else {
                b2->next = current;
                b2 = b2->next;
            }
            current = current->next;
        }

        b2->next = nullptr; 
        a1->next = l2->next; 

        ListNode* new_head = l1->next; 
        delete l1;
        delete l2;

        return new_head;
    }
};
