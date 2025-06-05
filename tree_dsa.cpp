#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(int data){
        this->data=data;
    }
};

TreeNode<int> * takeInput(){
    int data;
    cout<<"Enter root data"<<endl;
    cin>>data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        int childs;
        cout<<"Enter the no.of childs of "<<front->data<<endl;
        cin>>childs;
        for (int i = 0; i < childs; i++)
        {
            int data;
            cout<<"Please enter the data of "<<i<<"th child"<<endl;
            cin>>data;
            TreeNode<int> *child = new TreeNode<int>(data);
            front->children.push_back(child);
            q.push(child);

        }
        
    }
    return root;
    


    
}
int countNodes(TreeNode<int>* root){
    if (root->children.size()==0)
    {
        return 1;
    }
    int k=0;
    int n=root->children.size();
    for (int i = 0; i < n; i++)
    {
        k+=countNodes(root->children.at(i));
    }
    return 1+k;
    
}
int sum(TreeNode<int>* root){
    if (root->children.size()==0)
    {
        return root->data;
    }
    int k=0;
    int n=root->children.size();
    for (int i = 0; i < n; i++)
    {
        k+=countNodes(root->children.at(i));
    }
    return root->data+k;
    
}
void printTree(TreeNode <int>*root ){
    if (root==NULL)
    {
        return;
    }
    
    cout<<root->data<<":";
    int n=root->children.size();
    for (int i = 0; i <n ; i++)
    {
        cout<<root->children.at(i)->data<<",";
    }
    cout<<endl;
    for (int i = 0; i <n ; i++)
    {
        printTree(root->children.at(i));
    }
    
    
    
}

int findHeight(TreeNode<int>*root){
    if(root->children.size()==0){
        return 1;
    }
    int n=root->children.size();
    int height=findHeight(root->children.at(0));
    for (int i = 1; i < n; i++)
    {
        int h=findHeight(root->children.at(i));
        if (h>height)
        {
            height=h;
        }
        
    }
    return 1+height;
    
}

int main(){
    TreeNode<int> *root = takeInput();
    printTree(root);
    cout<<countNodes(root);
    delete root;

    return 0;
}
//contributed by prateek pathak
