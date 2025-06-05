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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = dummy, *nex = dummy;

        int cnt = 0;
        while(cur->next){
            cnt += 1;
            cur = cur->next;
        }

        while(cnt >= k){
            cur = pre->next;
            nex = cur->next;
            for(int i = 1; i < k; i++){
                cur->next = nex->next;
                nex->next = pre->next;

                pre->next = nex;
                nex = cur->next;
            }
            cnt -= k;
            pre = cur;
        }

        return dummy->next;
    }
};