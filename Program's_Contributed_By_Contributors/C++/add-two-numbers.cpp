// problem https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0;
        ListNode newHead(0);
        ListNode *t = &newHead;
        while (c || l1 || l2)
        {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            t->next = new ListNode(c % 10);
            t = t->next;
            c /= 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return newHead.next;
    }
}

;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}