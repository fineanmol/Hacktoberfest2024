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

void ZigZag(Node* head, vector<vector<int>> &a, int level, int ltr)
{
    queue<Node*> q;
    q.push(head);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            q.pop();
            if(!q.empty()) q.push(NULL);
            if(ltr==-1) {
                reverse(a[level].begin(),a[level].end());
                level++;
                ltr=1;
            }
            else if(ltr==1) ltr=-1,level++;
        }
        if(q.front()!=NULL) {
            a[level].push_back(q.front()->data);
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            q.pop();
        }
    }
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

    cout<<"\nZigZag Order:\n";
    vector<vector<int>> zigzag(height(head));
    ZigZag(head,zigzag,1,1);
    for(int i=0; i<=zigzag.size(); i++)
    {
        for(int j=0; j<zigzag[i].size(); j++)
        {
            cout<<zigzag[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}