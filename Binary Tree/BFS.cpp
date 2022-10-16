#include "iostream"
#include "queue"
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

void BFS(Node* root){
    if(root == NULL) return;

    queue<Node*> Q;
    Node* temp;
    Q.push(root);

    while(!Q.empty()){

        int size = Q.size();
        for(int i=0; i<size; i++){
            temp = Q.front();
            Q.pop();
            cout << temp->value << " ";

            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);

        }
    }
}

vector<char> BFS_recursive(Node* root, vector<char>& result){

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


    BFS(A);

    return 0;
}




