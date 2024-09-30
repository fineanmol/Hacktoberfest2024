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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a = a - 1;
        b = b + 1;
        ListNode * start = list1, * end = list1;
        while(a || b){
            if(a){
                start = start->next;
                a -= 1;
            }
            if(b){
                end = end->next;
                b -= 1;
            }
        }
        start->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        list2->next = end;

        return list1;
    }
};