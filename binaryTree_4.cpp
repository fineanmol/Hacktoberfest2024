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

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

//calculating diameter of treenode
int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL){
        return 0;
    }

    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);

    return max(option1,max(option2,option3));
}

//heightDiameter- this function is used for better approach in diameter function
pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int> rightAns=heightDiameter(root->right);
    int ld=leftAns.second;
    int lh=leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;

    int height=1+max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
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
    //levelwise input
    BinaryTreeNode<int>* root=takeInputLevelwise();

    printTree(root);
    cout<<"Total number of nodes: "<<numNodes(root)<<endl;


    pair<int,int> p = heightDiameter(root);
    cout<<"Height: "<<p.first<<endl;
    cout<<"Diameter: "<<p.second<<endl;
    delete root;
    return 0;
}




