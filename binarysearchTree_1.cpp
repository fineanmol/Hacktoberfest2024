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

//taking input
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1) return NULL;

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild=takeInput();
    BinaryTreeNode<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
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

/* binary tree me root ke right side me greater than root elements hote hain and
root ke left side me smaller than root elements hote hain
aise searching speed fast ho jati hai in comparison with normal trees */

/*binary search ka benefit ye hai ki hm direct calculate kr lete hain ki kis side
me hme apni search karni hai */

//checking if a binary tree is a bst(binary search tree or not)
/*ek tree ko bst hone ke liye tree ka root left subtree ke greatest element se bda and
right subtree ke smallest element se chhota hona chahiye */

//required function
int maximum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }

    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool output = (root->data > leftMax && root->data<=rightMin && isBST(root->left) && isBST(root->right));
}

//second method to check bst less time complexity
class isBSTReturn{
public:
    bool isBST;
    int maximum;
    int minimum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTReturn output;
        output.isBST=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        return output;
    }
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    isBSTReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTFinal;
    return output;
}

//third method to check bst
bool isBST3(BinaryTreeNode<int>* root,int min=INT_MIN, int max=INT_MAX){
    if(root==NULL)
        return true;
    if(root->data < min || root->data > max){
        return false;
    }
    bool isLeftOk = isBST3(root->left, min, root->data-1);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    //levelwise input
    BinaryTreeNode<int>* root=takeInput();
    printTree(root);
    isBSTReturn output = isBST2(root);
    cout<<"is tree is bst: "<<output.isBST<<endl;
    cout<<"minimum node value : "<<output.minimum<<endl;
    cout<<"maximum node value : "<<output.maximum<<endl;

    cout<<isBST3(root)<<endl;


    delete root;
    return 0;
}
