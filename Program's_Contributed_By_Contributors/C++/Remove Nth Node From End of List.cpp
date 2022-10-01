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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *iter = head;
        int len = 0, i = 1;
        while (iter)
            iter = iter->next, len++; // finding the length of linked list
        if (len == n)
            return head->next; // if head itself is to be deleted, just return head -> next
        for (iter = head; i < len - n; i++)
            iter = iter->next;         // iterate first len-n nodes
        iter->next = iter->next->next; // remove the nth node from the end
        return head;
    }
}

;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}