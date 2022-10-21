#include <iostream>
#include <vector>
#include <queue>
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

    ~TreeNode(){}
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

//preorder printing
void preorder(TreeNode<int>* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

//TODO: levelorder printing
/*void levelorder(TreeNode<int>* root){
    if(root==NULL)
        return;
    for(int i=0;i<root->children.size();i++){
        cout<<root->data<<" ";
        levelorder(children[i]);
    }
}*/


//TODO: postorder printing
void postorder(TreeNode<int>* root){
    if(root==NULL)
        return;

    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
        cout<<root->data<<" ";
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

//counting total nodes in a tree
int countNodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans=ans+countNodes(root->children[i]);
    }
    return ans;
}

//printing nodes at level k
void printAtLevelK(TreeNode<int>* root, int k)
{
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0; i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

//taking input level wise
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;

    //now root node banake usme rootData ka value daal denge
    TreeNode<int>* root = new TreeNode<int>(rootData);

    //now ek queue bana lenge
    queue<TreeNode<int>*> pendingNodes;
    //aur root ko queue me push kr denge
    pendingNodes.push(root);
    //now jab tk queue ka size empty na ho tab ke loop chalayenge
    //aur ek ek node nikalenge unke child node ka data enter krwayenge
    //aur unke child nodes ke data ko queue me hi push krte jayenge
    //kuki unke bhi to child nodes ka data enter krna hoga agr honge to
    while(pendingNodes.size()!=0){
        //front element ko nikal liye queue se ab iske children enter krwayenge
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of childrens of:"<<front->data<<endl;
        int numChild;
        cin>>numChild;
        //loop chalake jitne numchild hain utne entry krwa lenge
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            //vector me push back krwayege child ko
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }

    }
    return root;
}

//delete tree
//is function ko direct tree class me implement kr skte hain
void deleteTree(TreeNode<int>* root)
{
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
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
    //taking input normal
    //TreeNode<int>* root = takeInput();

    //taking input levelwise
    TreeNode<int>* root = takeInputLevelWise();

    //printTree(root);
    //printing the tree

    //printing tree with detail
    //printTreeWithDetail(root);

    //preorder printing
    //preorder(root);

    //levelorder printing
    //levelorder(root);

    //postorder printing
    postorder(root);



    //counting total nodes
    int totalNodes = countNodes(root);
    cout<<"Total nodes are: "<<totalNodes<<endl;

    return 0;
}

