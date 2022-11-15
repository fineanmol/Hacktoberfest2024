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
//     ListNode * reverse(ListNode * l1)
//     {
//         if(!l1 || l1->next == NULL)
//             return l1;
        
//         ListNode * nextnode=l1->next;
//         ListNode * reversed = reverse(l1->next);
//         l1->next = NULL;
//         nextnode->next = l1;
//         return reversed;
//     }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   //     l1 = reverse(l1);
   //     l2 = reverse(l2);
        int carry = 0;
        ListNode * dummy = new ListNode(0);
        ListNode * temp = dummy;
        while(l1 != NULL || l2 !=NULL)
        {
            int sum = carry;
            if(l1)
                sum+=l1->val;
            if(l2)
                sum+=l2->val;
            
            int value = sum%10;
            carry = sum/10;
            ListNode * newNode = new ListNode(value);
            temp->next = newNode;
            temp = temp->next;
            if(l1)
            l1 = l1->next;
            if(l2)
            l2 = l2->next;
        }
        
        if(carry)
        {
            ListNode * newNode = new ListNode(carry);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummy->next;
        
    }
};