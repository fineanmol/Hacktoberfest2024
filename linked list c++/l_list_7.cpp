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
    node *head=new node(),*temp,*pred,*succ;
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
    five->next=NULL;
    //how to delete a node in between 
    int pos;
    cout<<"Enter node to delete";
    cin>>pos;
    temp=head;
    for(int i=1;i<pos;i++)
    {
        pred=temp;
        temp=temp->next;
        succ=temp->next;
    }
    pred->next=succ;
    temp->next=NULL;
    //
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    return 0;
}