Problem link - "https://leetcode.com/problems/reverse-linked-list/"

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
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *temp=head->next;
        ListNode *newHead=reverseList(head->next);
        temp->next=head;
        head->next=NULL;
        return newHead;
    }
};