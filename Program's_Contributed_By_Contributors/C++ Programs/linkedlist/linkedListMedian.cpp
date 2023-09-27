
// You are given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

// Algorithm: Tortoise-Hare-Approach

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};

// Function to build a linked list from user input
ListNode* buildLinkedList() {
    int n;
    std::cout << "Enter the number of nodes in the linked list: ";
    std::cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cout << "Enter value for node " << i + 1 << ": ";
        std::cin >> val;

        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    ListNode* head = buildLinkedList();
    Solution solution;
    ListNode* middleNode = solution.middleNode(head);
    if (middleNode)
        std::cout << "The middle node value is: " << middleNode->val << std::endl;
    else
        std::cout << "The linked list is empty." << std::endl;

    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

/*
Input Format: 
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]

Result: [3,4,5]
- Element 3 is the middle element.
( As we will return the middle of Linked list the further linked list will be still available )
*/
