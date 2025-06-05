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

//class of bst with all fucntions
class BST{
    BinaryTreeNode<int>* root;
public:
    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }

private:
    BinaryTreeNode<int>* deleteDate(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }

        if(data>node->data){
            node->right = deleteDate(data,node->right);
            return node;
        }else if(data<node->data){
            node->left = deleteDate(data,node->left);
            return node;
        }else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->left == NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left !=NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteDate(rightMin,node->right);
                return node;
            }
        }
    }


public:
    void deleteDate(int data){
        root = deleteDate(data,root);
    }

private:
     //printing of tree
    void printTree(BinaryTreeNode<int>* root){
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

public:
    void printTree(){
        printTree(root);
    }

private:
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data<node->data){
            node->left = insert(data,node->left);
        }else{
            node->right = insert(data,node->right);
        }
        return node;
    }
public:
    void insertData(int data){
        this->root = insert(data,this->root);
    }

private:
    bool hasData(int data,BinaryTreeNode<int>* root){
        if(root==NULL)
            return NULL;
        if(root->data == data){
            return true;
        }else if(data < root->data){
            return hasData(data,root->left);
        }else{
            return hasData(data,root->right);
        }

    }
public:
    bool hasData(int data){
        return hasData(data,root);
    }
};

//printing binary tree


int main(){
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(3);
    b.insertData(7);
    b.insertData(20);
    b.insertData(15);

    b.deleteDate(10);

    b.printTree();

    return 0;
}

