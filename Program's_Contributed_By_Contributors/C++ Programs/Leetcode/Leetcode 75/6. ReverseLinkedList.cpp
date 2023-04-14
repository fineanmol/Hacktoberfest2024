#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;


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
// Iterative
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        // null -> 1 -> 2 -> 3 -> 4 -> 5
        while (curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

// Recursive: (much faster)
    ListNode* reverseListRecursive(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;

        ListNode* newHead = reverseListRecursive(head->next);
        ListNode* headNext = head->next;

        headNext->next=head;
        head->next = nullptr;
        return newHead;

}
};

