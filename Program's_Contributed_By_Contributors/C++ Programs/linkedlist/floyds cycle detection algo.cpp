#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
int main()
{
    node *head=new node(),*temp,*fast,*slow;
    node *one=new node();
    node *two=new node();
    node *three=new node();
    node *four=new node();
    node *five=new node();
    head->data=0;
    one->data=1;
    two->data=2;
    three->data=3;
    four->data=4;
    five->data=5;
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=one;
    fast=head;
    slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            fast=head;
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            break;
        }
    }
    if(fast==slow)
        cout<<"The node where loop starts is "<<fast->data;
    else
        cout<<"There is no loop in the linked list";
    return 0;
}