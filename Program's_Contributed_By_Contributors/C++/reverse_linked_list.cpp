//Problem Link:-https://leetcode.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* ptr1=head;
        if(ptr1!=nullptr && ptr1->next!=nullptr){
        struct ListNode* ptr3=nullptr;
        struct ListNode* ptr2=head->next;
        ptr1->next=nullptr;
        while ((ptr2->next !=nullptr))
        {
           ptr3=ptr2->next;
           ptr2->next=ptr1;
           ptr1=ptr2;
           ptr2=ptr3;
        }
        ptr2->next=ptr1;
        head=ptr2;
        }
        return head; 
    }
};
