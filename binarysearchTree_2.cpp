#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//construction of binary search tree
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


//sorted array to BST
BinaryTreeNode<int>* sortedArrayToBst(int arr[],int start, int end){
    //base case
    if (start > end)
        return NULL;
    int mid = (start+end)/2;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    root->left = sortedArrayToBst(arr,start,mid-1);
    root->right = sortedArrayToBst(arr,mid+1,end);
    return root;
}

//finding the path between the nodes of a bst
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root==NULL)
        return NULL;
    //root agar null hua to seedhe null return kar denge
    //aur agar root me hi data hua then root ke data ko vector me push krke
    //return kr denge
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    //if root me data nhi hua to then ek baar right me and ek baar left me search krenge
    vector<int>* leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }

}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    /* array to bst
    int arr[]={1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    BinaryTreeNode<int>* root = sortedArrayToBst(arr,0,n);
    printTree(root);
    */

    BinaryTreeNode<int>* root = takeInput();
    vector<int>* output = getRootToNodePath(root,8);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<endl;
    }



    delete root;
    return 0;
}

