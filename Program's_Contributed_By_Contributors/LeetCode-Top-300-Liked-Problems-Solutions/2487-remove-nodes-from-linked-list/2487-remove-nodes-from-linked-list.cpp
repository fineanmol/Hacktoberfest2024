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

    ListNode* removeNodes(ListNode* head) {
        ListNode* res = reverseList(head);
        ListNode* temp = res;
        while(res->next){
            if(res->val > res->next->val)
                res->next = res->next->next;
            else
                res = res->next;
        }
        head = reverseList(temp);
        return head;
    }
};