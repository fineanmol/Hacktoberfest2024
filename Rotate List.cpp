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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)return head;
        if (head->next == NULL)return head;
        ListNode *temp = head, *new_head = NULL;
        int total_nodes = 1, cnt;
        while (temp->next!=NULL)
        {
            total_nodes += 1;
            temp = temp->next;
        }
        temp->next = head;
        k = k % total_nodes;
        cnt = (total_nodes - k );
        for(int i=0;i<cnt;i++)
        {
            temp = temp->next;
        }
        new_head = temp->next;
        temp->next = NULL;
        return new_head;
    }
};
