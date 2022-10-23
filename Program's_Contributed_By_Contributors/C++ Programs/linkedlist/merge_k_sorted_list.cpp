/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Leetcde 23 : You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//              Merge all the linked-lists into one sorted linked-list and return it.

#define f first
#define s second

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        priority_queue< pair<int, pair<int,ListNode*>> , vector<pair<int, pair<int,ListNode*>>>, greater<pair<int, pair<int,ListNode*>>> >pq;
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        
        int n = lists.size();
          
        for(int i=0;i<n;i++)
            if(lists[i])
              pq.push({lists[i]->val,{i,lists[i]}});

        while(!pq.empty()){
            
           int i = pq.top().s.f;
           ListNode* node = pq.top().s.s;
            
           pq.pop();
            
          // cout<<node->val<<" ";
           curr->next = node;
           // cout<<curr->val<<" ";
           curr = curr->next;
            
          if(node->next)
             pq.push({node->next->val,{i,node->next}});
            

          }
       return head->next; 
    }
};