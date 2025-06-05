#include<iostream>
#include<queue>
using namespace std;

/* input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
   output : 1
            2 3
            4 5 6
            7
*/           

class Node{

public:
    int data;
    Node * left;  
    Node * right; 

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void leveldotprint(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            //insert a new null for the next level
            if(!q.empty()){
                q.push(NULL);
            
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
    return;
}
int main(){
    Node* root = buildTree();
    leveldotprint(root);

    return 0;
}


