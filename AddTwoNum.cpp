#include <iostream>
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
        ListNode *res = new ListNode(0);
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *curr = res;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL)
        {
            int x = temp1 != NULL ? temp1->val : 0;
            int y = temp2 != NULL ? temp2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (temp1->next != NULL)
                temp1->next;
            if (temp2->next != NULL)
                temp2->next;
        }
        if (carry > 0)
        {
            curr->next = new ListNode(carry);
        }
        return res->next;
    }
};
int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    Solution s;

    ListNode *ans = s.addTwoNumbers(l1, l2);
    ans->next = new ListNode(3);
    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
}