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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast!=nullptr || fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        while (slow!=nullptr){
            ListNode* temp = slow->next;
            slow=slow->next;
            
        }
        return true; 
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> palind;
        while (head!=nullptr){
            palind.push_back(head->val);
            head=head->next;
        }

        int left = 0, right = palind.size()-1;

        while (left<=right){
            if (palind[left]!=palind[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};