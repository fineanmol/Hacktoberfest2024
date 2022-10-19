#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node* grow()
{
    node *add=NULL;
    add = new node();
    // cin>> add->data;
    // add->next=NULL;
    return add;
}
int main()
{
    int len;
    cout<<"Enter no of nodes to add";
    cin>>len;
    node *head=NULL;
    head = new node();
    node *temp_head = head;
    for(int i=0;i<len+1;i++)
    { 
        temp_head->next=grow();
        cin>>temp_head->data;
        if (i!=len)
        temp_head=temp_head->next;
        else
        temp_head->next=NULL;
    }
    temp_head=head;
    while(temp_head!=NULL)
    {
        cout<<temp_head->data;
        temp_head=temp_head->next;
    }
    // cout<<"\n";
    // cout<<head->data;
    // cout<<head->next->data;
    // cout<<head->next->next->data;
    return 0;
}