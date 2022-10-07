#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left=NULL;
        Node* right=NULL;
        Node(int x)
        {
            data=x;
        }
};

void PostOrder(Node* head, vector<int> &a)
{
    if(head==NULL) return;
    PostOrder(head->left,a);
    PostOrder(head->right,a);
    a.push_back(head->data);
    return;
}

int main()
{
    Node* head=new Node(1);
    head->left=new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->left=new Node(6);
    head->right->right=new Node(7);
    head->left->left->right=new Node(8);
    head->left->right->left=new Node(9);
    head->right->left->left=new Node(10);
    head->right->right->right=new Node(11);
    head->right->right->right->right=new Node(12);

    vector<int> post;
    PostOrder(head,post);
    cout<<"\nPostOrder: ";
    for(int i=0; i<post.size(); i++)
    {
        cout<<post[i]<<' ';
    }
        return 0;
}