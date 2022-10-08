#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        int count = 0;
        struct Node * ptr = head;
        while(ptr != NULL){
            ptr = ptr->next;
            count++;
        }
        if(count%2==0){
            struct Node* p1 = head;
            for(int i=1; i<=count/2; i++){
                p1 = p1->next;
            }
            return p1->data;
        }
        else{
            struct Node* p2 = head;
            for(int i=1; i<= count/2; i++){
                p2 = p2->next;
            }
            return p2->data;
        }
    }
};
