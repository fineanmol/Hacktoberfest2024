#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// Basic Structure of a Tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};







//Function which prints out the top view of the tree

void topView(struct Node * root)
{
    if (root == NULL)
        return;

    queue<pair<struct Node*, int>>q;
    map<int, int> mp;
    int d;
    q.push({root, 0});
    Node *temp = NULL;

    while (!q.empty())
    {
        temp = q.front().first;
        d = q.front().second;


        if (mp.find(d) == mp.end())
        {
            //cout << temp->data <<" ";
            mp[d] = temp->data;
        }

        if (temp->left)
        {
            q.push({temp->left, d - 1});    //every node left to its predecessor is tagged a number less than one

        }
        if (temp->right)
        {
            q.push({temp->right, d + 1}); //every node right to its predecessor is tagged a number greater than one

        }
        q.pop();
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
        cout << i->second << " ";



}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    /*
                    1
                   / \
                  2   3
                 / \   \
                4   5   7
        Expected-> 4 2 1 3 7

    */
    cout << "The top view of the tree is : " << endl;
    topView(root);

    return 0;
}