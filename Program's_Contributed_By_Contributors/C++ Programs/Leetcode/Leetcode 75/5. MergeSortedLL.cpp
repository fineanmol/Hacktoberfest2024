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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode mergeHead = ListNode(-1);
        ListNode* mergePtr = &mergeHead;

        if (list1==nullptr) return list2;
        if (list2==nullptr) return list1;

        while (list1!=nullptr && list2!=nullptr){
            if (list1->val<list2->val){
                mergePtr->next = list1;
                list1 = list1->next;
            } else {
                mergePtr->next = list2;
                list2 = list2->next;
            }
            mergePtr = mergePtr->next;
        }
        if(list1==nullptr) mergePtr->next = list2;
        if (list2==nullptr) mergePtr->next = list1;

        return mergeHead.next;
    }
};

