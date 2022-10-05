//Leetcode proplem: 876. Middle of the Linked List
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast, *slow;
        fast = slow = head;

        while (fast && fast->next)
        {
            if (fast->next->next == NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            else
            {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};
