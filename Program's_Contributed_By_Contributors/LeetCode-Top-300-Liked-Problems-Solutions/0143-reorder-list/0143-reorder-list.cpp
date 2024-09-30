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
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        //Finding the middle element
        ListNode* mid = middleNode(head);
        //Take the second half of the list
        ListNode* mHead = mid->next;
        //Breaking connection between first and second half of the list
        mid->next = NULL;

        //Reversing second half of the list
        mHead = reverseList(mHead);

        //Reordering the divided two lists in the given format
        ListNode* first = head;
        ListNode* second = mHead;
        while(second){
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;
        first->next = second;
        second->next = firstNext;
        first = firstNext;
        second = secondNext;
        }
    }
};