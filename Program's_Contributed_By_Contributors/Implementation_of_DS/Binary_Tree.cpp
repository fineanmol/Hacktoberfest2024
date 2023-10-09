#include <iostream>
using namespace std;

class Node
{
    int data;

public:
    Node *left;
    Node *right;

    Node()
    {
        this->data=0;
        this->left = nullptr;
        this->right = nullptr;
    }

    void setData(int N)
    {
        this->data = N;
    }
    int getData()
    {
        return data;
    }
};

Node *takeInput(Node *root)
{

    cout << "Enter the data of the given Node:" << endl;
    int N;
    cin >> N;
    root->setData(N);
    cout << "Does ("<<N<<") have a left node?" << endl;
    bool choice;
    cout << "Enter 1 for yes, 0 for no" << endl;
    cin >> choice;
    if (choice)
    {
        root->left = new Node();
        root->left = takeInput(root->left);
    }
    cout << "Does ("<<N<<") have a right node?" << endl;
    cout << "Enter 1 for yes, 0 for no" << endl;
    cin >> choice;
    if (choice)
    {
        root->right = new Node();
        root->right = takeInput(root->right);
    }
}

void printTree(Node * root){
cout<<root->getData()<<endl;
if(root->left){
    printTree(root->left);
}
if(root->right){
    printTree(root->right);
}


}

int main()
{

    cout << "Enter 1 by 1 each node of the given binary tree:" << endl;

    Node *root = new Node();
    takeInput(root);
    printTree(root);

    return 0;
}