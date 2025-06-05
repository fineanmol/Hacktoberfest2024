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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode*oddhead = head, *odd=head;
        ListNode*evenhead = head->next, *even=head->next;
        while(odd!=NULL && odd!=NULL && odd->next!=NULL && even->next!=NULL){
            odd->next = even->next;
             odd = odd->next;
            even->next = odd->next;
           even = even->next;
        }
        odd->next = evenhead;
        return oddhead;
    }
};