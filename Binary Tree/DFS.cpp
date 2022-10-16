#include "iostream"
#include "stack"
#include "vector"
using namespace std;

class Node{

    public:
        char value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

void DFS(Node* root){
    if(root == NULL) return;

    stack<Node*> stk;
    stk.push(root);

    while(!stk.empty()){
        Node* temp = stk.top();
        stk.pop();
        cout << temp->value << " ";
        
        // pushing its child in stack
        if(temp->right){
            stk.push(temp->right);
        }
        if(temp->left){
            stk.push(temp->left);
        }
    }
}

vector<char> DFS_recursive(Node* root, vector<char>& result){

    if(root == NULL){
        return result;
    }

    // cout << root->value << " ";
    result.push_back(root->value);
    DFS_recursive(root->left, result);
    DFS_recursive(root->right, result);

    return result;

}

int main(){

    Node* A = new Node('a');
    Node* B = new Node('b');
    Node* C = new Node('c');
    Node* D = new Node('d');
    Node* E = new Node('e');
    Node* F = new Node('f');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    
    vector<char> res;
    res = DFS_recursive(A, res);

    for(auto & element: res){
        cout << element << " ";
    }

    return 0;
}




