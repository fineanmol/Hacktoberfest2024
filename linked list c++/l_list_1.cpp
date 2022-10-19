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
    node *head = NULL;
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;

    head = new node();
    first = new node();
    second = new node();
    third = new node();
    fourth = new node(); 
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    head->data=1;
    first->data=2;
    second->data=3;
    third->data=4;
    fourth->data=5;
    node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    return 0;
}