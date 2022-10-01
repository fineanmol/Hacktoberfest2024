// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head,*next1,*next2,*curr;
        
        if (!list1){
            return list2;
        } else if (!list2) {
            return list1;
        }
        
        if (list1->val<=list2->val){
            head = list1;
            next1 = list1->next;
            next2 = list2;
        } else {
            head = list2;
            next2 = list2->next;
            next1 = list1;
            
        }
        
        curr = head;
        while (next1 && next2){
            if (next1->val<=next2->val){
                curr->next = next1;
                next1 = next1->next;
            } else {
                curr->next = next2;
                next2 = next2->next;
            }
            curr = curr->next;
        }
        
        while (next1){
            curr->next = next1;
            next1 = next1->next;
            curr = curr->next;
        }
        
        while (next2){
            curr->next = next2;
            next2 = next2->next;
            curr = curr->next;
        }
        
        return head;
    }
};