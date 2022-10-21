#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode*> children;

    TreeNode(T data){
        this->data=data;
    }
};

//basic printing of trees
void printTree(TreeNode<int>* root){
    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

//printing trees with detail
void printTreeWithDetail(TreeNode<int>* root){
    cout<<root->data<<":";
    //now here ek loop chalake is node ke harek node ko print krenge
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTreeWithDetail(root->children[i]);
    }
}

//taking input for trees recursively
TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"enter data:"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    //now taking input about childrens
    int n;
    cout<<"enter no. of children of"<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;

}

int main()
{
    cout<<"-------------Program started-------------"<<endl;

/*  TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* node1 = new TreeNode<int>(20);
    TreeNode<int>* node2 = new TreeNode<int>(30);
    //abhi bs three node create kiye hain linked nhi hain abhi aapas me

    root->children.push_back(node1);
    root->children.push_back(node2);
    //root ke children vector me node1 and node2 ko push kr diye isse ye connect ho gye
*/
    //taking input
    TreeNode<int>* root = takeInput();

    //printTree(root);
    //printing the tree

    //printing tree with detail
    printTreeWithDetail(root);

    return 0;
}


