#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node* grow_rev(node *head)
{
    node *add=NULL;
    add = new node();
    cin>>add->data;
    add->next=head;
    return add;
}
int main()
{
    node *head=NULL;
    head=new node();
    head->next=NULL;
    int len;
    node *temp=head;
    cout<<"Enter no of nodes";
    cin>>len;
    cout<<"Enter data";
    cin>>head->data;
    //create a linked list from last node 
    for(int i=0;i<len;i++)
    {
        temp=grow_rev(temp);
    }
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    return 0;
}