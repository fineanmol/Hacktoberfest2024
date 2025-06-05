#include <iostream>
#include <queue>
using namespace std;

template <typename T>


class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

//Traversal techniques
//Level order
//pre order
//post order
//in order

//inorder traversal
void inorder(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//remaining traversals do it by yourself

//generating tree with preorder and inorder values given
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
    if(inS>inE){
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }

    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rPres=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(in,pre,rInS,rInE,lPreS,lPreE);
    return root;
}

BinaryTreeNode<int>* buildTree(int* in, int *pre, int size){
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}

//printing binary tree
void printTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}



//taking input level wise
BinaryTreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;

}

//counting nodes
int numNodes(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    return 1+numNodes(root->left)+numNodes(root->right);
};

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    //binary tree creation using inorder and preorder
    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};
    BinaryTreeNode<int>* root=buildTree(in,pre,9);


    //levelwise input
    //BinaryTreeNode<int>* root=takeInputLevelwise();
    cout<<"Total number of nodes: "<<numNodes(root)<<endl;
    printTree(root);
    //inorder(root);
    delete root;
    return 0;
}



