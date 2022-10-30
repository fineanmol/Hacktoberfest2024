#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
};


int main()
{

Node* head = new Node();
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();
    Node* four = new Node();
    head->val = 5;
    one->val = 2;
    two->val = 3;
    three->val = 1;
    four->val = 4;
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = two;

if (head == NULL || head->next == NULL) 
    {
        cout<<"No cycle"<<endl;
        return 0;
    }

        Node* firstp = head;
        Node* secondp = head;
        bool isCycle = false;

        while(firstp != NULL && secondp != NULL) {
            firstp = firstp->next;
            if (secondp->next == NULL)
                {
                    cout<<"No cycle"<<endl;
                    return 0;
                }
            secondp = secondp->next->next;
            if (firstp == secondp) { isCycle = true; break; }
        }

        if(!isCycle)
        {
         cout<<"No cycle"<<endl;
         return 0;
     }
        firstp = head;
        while( firstp != secondp) {
            firstp = firstp->next;
            secondp = secondp->next;
        }

        cout<<firstp->val<<endl;

return 0;
}