class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*next=head->next;
        while(curr!=NULL)
        {
        next=curr->next;
          curr=prev->next;
          prev=curr;
          current=next;
            
            
        }
        return head;
        
    }
};
