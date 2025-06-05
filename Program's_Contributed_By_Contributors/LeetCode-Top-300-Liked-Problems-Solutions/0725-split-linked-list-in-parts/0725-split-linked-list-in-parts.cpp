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
private:
    int findLen(ListNode *h)
    {
        int l = 0;
        
        while(h)
        {
            l++;
            h = h->next;
        }

        return l;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* iter = head;
        int len = findLen(head);

        int divisions = len / k, rem = len % k;

        while(k--){
            ans.push_back(iter);

            for(int i = 0; i < divisions - 1; i++)
                iter = iter->next;
            
            if(rem > 0 && divisions != 0)
                iter = iter->next;

            rem--;
            if(iter){
                ListNode* temp = iter->next;
                iter->next = NULL;
                iter = temp; // For next split part
            }
        }
        return ans;
    }
};