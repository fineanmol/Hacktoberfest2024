#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

class Node{
    public:
        int data;
        Node * left;
        Node * right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node * buildTree(Node * root) {
    // pre-order
    std::cout << "Enter data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    std::cout << "Enter data for inserting in left child of " << data << endl;
    root -> left = buildTree(root -> left);

    std::cout << "Enter data for inserting in right child of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node * root) {
    if(root == NULL) {
        cout << "root is null" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // separator to know if level is complete

    while(!q.empty()) {
        Node * temp = q.front();
        q.pop();

        if(temp == NULL) {
            // last level traverse complete
            std::cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
                
        }else {
            std::cout << temp -> data << " ";        

            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
        
    }

    std::cout << endl;
}



void inOrderTraversal(Node * root) {

    // base case
    if (root == NULL)
        return;

    inOrderTraversal(root -> left);
    std::cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void inOrderIterative(Node * root) {
    if(root == NULL)
        return;

    stack<Node *> s;

    Node * current = root;

    while(current != NULL) {
        s.push(current);
        current = current -> left;

        while(current == NULL && !s.empty()) {
            Node * temp = s.top();
            cout << temp -> data << " ";
            s.pop();
            current = temp -> right;
        }
    }

    cout << endl;
}

void preOrderTraversal(Node * root) {

    // base case
    if (root == NULL)
        return;

    std::cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void preOrderIterative(Node * root) {
    if(root == NULL)
        return;

    stack<Node *> s;

    Node * current = root;

    while(current != NULL) {
        s.push(current);
        cout << current -> data << " ";
        current = current -> left;

        while(current == NULL && !s.empty()) {
            Node * temp = s.top();
            s.pop();
            current = temp -> right;
        }
    }

    cout << endl;
}

void postOrderTraversal(Node * root) {

    // base case
    if (root == NULL)
        return;

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    std::cout << root -> data << " ";
}

// Iterative function to perform postorder traversal on the tree
void postOrderIterative(Node* root)
{
    // return if the tree is empty
    if (root == NULL) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
         if(curr != NULL){
            out.push(curr->data);

            // push the left and right child of the popped node into the stack
            if (curr->left) {
                s.push(curr->left);
            }
    
            if (curr->right) {
                s.push(curr->right);
            }
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}


void buildFromLevelOrder(Node * &root) {
    // level order matlab queue
    queue<Node *> q;
    cout << "Enter data for root" << endl; 
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);
    // cout << q.front() -> data << endl;

    while(!q.empty()) {
        Node * temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }


        cout << "Enter right node for " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }

}

int main() {
    Node * root = NULL;

    // Creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1

    std::cout << "Printing the level order traversal :" << endl;
    levelOrderTraversal(root);

    // std::cout << "Printing the reverse level order traversal :" << endl;
    // reverseLevelOrderTraversal(root);
    // std::cout << endl;

    // Inorder traversal LNR
    // 7 3 11 1 17 5
    std::cout << "Printing the in-order traversal :" << endl;
    inOrderTraversal(root);
    std::cout << endl;
    inOrderIterative(root);
    std::cout << endl;

    // Preorder traversal NLR
    // 1 3 7 11 5 17
    std::cout << "Printing the pre-order traversal :" << endl;
    preOrderTraversal(root);
    std::cout << endl;
    preOrderIterative(root);
    std::cout << endl;

    // PostOrder traversal LRN
    // 7 11 3 17 5 1
    std::cout << "Printing the post-order traversal :" << endl;
    postOrderTraversal(root);
    std::cout << endl;
    postOrderIterative(root);
    std::cout << endl;

    // Node * root2 = NULL;
    // // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // buildFromLevelOrder(root2);

    // std::cout << "Printing the level order traversal :" << endl;
    // levelOrderTraversal(root2);

    return 0;
}
