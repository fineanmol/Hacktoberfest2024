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
    int pos;
    node *head;
    head = new node();
    node *one ;
    one = new node();
    node *two;
    two = new node();
    node *three;
    three = new node();
    node *four = new node();
    four = new node();
    node *temp=head,*temp_prev;
    node *extra;
    extra = new node();
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=NULL;
    head->data=1;
    one->data=2;
    two->data=3;
    three->data=4;
    four->data=5;
    cout<<"Enter the position ";
    cin>>pos;
    //add extra node in btween
    int i=1;
    temp=head;
    while (i!=pos)
    {
        temp_prev=temp;
        temp=temp->next;
        i++;
    }
    temp_prev->next=extra;
    extra->next=temp;
    extra->data=9;
    //
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    return 0;
}