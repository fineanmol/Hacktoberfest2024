#include<iostream>
#include<stack> 
#define endl "\n"
using namespace std;


// Basic Structure of a Tree
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* Pre, In and Post order Traversal of a Binary Tree using recusrion */
/* Complexity for each Traversal : O(n) */

// LST -> Left SubTree   RST -> Right SubTree

// Pre-Order goes like :-   Root, LST, RST (Recursively)
void pre_order(struct Node* root){
    if(root == NULL)
      return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

// In-Order goes like :-   LST, Root, RST (Recursively)
void in_order(struct Node* root){
    if(root == NULL)
      return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

// Pre-Order goes like :-  LST, RST, Root (Recursively)
void post_order(struct Node* root){
    if(root == NULL)
      return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}


/* Pre, In and Post order Traversal of a Binary Tree using Iteration */
/* Complexity for each Traversal : O(n) */


void NRpreorder(struct Node* root) //Iterative Preorder Traversal
{ 
   stack <Node*> s; 
   while(!s.empty() || root!=NULL) 
   { 
       while(root!=NULL) 
       { 
           cout<<root->data<<" "; 
           s.push(root); 
           root=root->left; 
       } 
       root=s.top(); 
       s.pop(); 
       root=root->right; 

   } 
} 



void NRinorder(struct Node* root) //Iterative Inorder Traversal
{ 
   stack <Node*> s; 
   while(!s.empty() || root!=NULL) 
   { 
       while(root!=NULL) 
       { 
           s.push(root); 
           root=root->left; 
       } 
       root=s.top(); 
       s.pop(); 
       cout<<root->data<<" "; 
       root=root->right; 
   } 
} 


void NRpostorder(struct Node* root) //Iterative Postorder Traversal
{ 
   stack <Node*> s1; 
   stack <int> s2; 
   while(root!=NULL) 
   { 
       s1.push(root); 
       s2.push(0); 
       root=root->left; 
   } 
   while(!s1.empty()) 
   { 
       root=s1.top(); 
       if(s2.top()==1) 
       { 
           s1.pop(); 
           s2.pop(); 
           cout<<root->data<<" "; 
       } 
       else 
       { 
           s2.top()=1; 
           root=root->right; 
           while(root!=NULL) 
           { 
               s1.push(root); 
               s2.push(0); 
               root=root->left; 
           } 
       } 
   } 
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    /*                       
                    1
                   / \
                  2   3
                 / \   \
                4   5   7    
        Expected-> From Recursive calls : 
                   pre-order : 1 2 4 5 3 7 
                   in-order : 4 2 5 1 3 7 
                   post-order : 4 5 2 7 3 1 

                   From Non-Recursive/Iterative calls : 
                   preorder : 1 2 4 5 3 7 
                   inorder : 4 2 5 1 3 7 
                   postorder : 4 5 2 7 3 1 
    
    */
    // Tree Traversal using recursive calls
   cout<<"From Recursive calls : "; cout<<endl;
   cout<<"pre-order : "; pre_order(root); cout<<endl;
   cout<<"in-order : "; in_order(root); cout<<endl;
   cout<<"post-order : "; post_order(root); cout<<endl<<endl;

   // ~~~~~~ Tree Traversal using non-recusive/Iterative calls ~~~~~~
   cout<<"From Non-Recursive/Iterative calls : "; cout<<endl;
   cout<<"preorder : "; NRpreorder(root); cout<<endl;
   cout<<"inorder : "; NRinorder(root); cout<<endl;
   cout<<"postorder : "; NRpostorder(root); cout<<endl;

    return 0;
}
