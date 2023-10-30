#include<iostream>
#include<queue>

using namespace std;
template <typename T>
class binaryTreeNode{
    public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    ~binaryTreeNode(){
        delete left;
        delete right;
    }
};

void printBinaryTree(binaryTreeNode<int> *root){
    if(root==NULL) return;
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
binaryTreeNode<int>* takeInput(){
    
    int val;
    cout<<"Enter the data of root Node "<<endl;
    cin>>val;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(val);

    queue<binaryTreeNode<int>*> q; 
    q.push(root);
    while (!q.empty())
    {
        binaryTreeNode<int>* front=q.front();
        q.pop();
        int ldata;
        cout<<"Enter the left Child "<<endl;
        cin>>ldata;
        if (ldata!=-1)
        {
            binaryTreeNode<int>* lchild = new binaryTreeNode<int>(ldata);
            front->left=lchild;
            q.push(lchild);
        }

        int rdata;
        cout<<"Enter the right Child "<<endl;
        cin>>rdata;
        if (rdata!=-1)
        {
            binaryTreeNode<int>* rchild = new binaryTreeNode<int>(rdata);
            front->right=rchild;
            q.push(rchild);
        }
        
    }
    return root;
}

int main(){
    binaryTreeNode<int> *root = takeInput();
    
    printBinaryTree(root);

    return 0;

}
//This is contributed by Prateek Pathak(prateek2pathak)
