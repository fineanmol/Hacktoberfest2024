#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int length(ListNode *node) {
        int count = 0;
        while (node) {
            count++;
            node = node->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // First check if the remaining nodes are not less than k, if it is, suspend the recursion and return head.
        if (length(head) < k) {
            return head;
        }
        
        // Reverse the first k nodes and call a recursive function.
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *Next;

        int count = 0;
        while (curr != nullptr && count < k) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count++;
        }
        
        if (Next != nullptr) {
            head->next = reverseKGroup(Next, k);
        }
        
        return prev;
    }
};

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 6; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }

    // Print the original linked list
    current = head;
    std::cout << "Original Linked List: ";
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Reverse the linked list in groups of 3
    Solution solution;
    int k = 3;
    ListNode* newHead = solution.reverseKGroup(head, k);

    // Print the reversed linked list
    current = newHead;
    std::cout << "Reversed Linked List (in groups of " << k << "): ";
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
