class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = NULL, *headodd = NULL, *even = NULL, *headeven = NULL;
        
        if(!head || !head->next || !head->next->next) return head;
         
        odd = head; headodd = odd;
        even = head->next; headeven = even;
        
        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = headeven;
        return headodd;
    }  
};
