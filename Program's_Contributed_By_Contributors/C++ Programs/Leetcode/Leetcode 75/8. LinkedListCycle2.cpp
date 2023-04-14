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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast){
                while (slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return entry;
            }
        }

    }
};