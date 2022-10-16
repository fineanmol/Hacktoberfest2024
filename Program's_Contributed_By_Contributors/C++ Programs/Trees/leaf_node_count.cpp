 
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std; 
  

struct node  
{  
    int data;  
    struct node* le;  
    struct node* rig;  
};  

unsigned int Leaf_count(struct node* node)  
{  
    if(node == NULL)      
        return 0;  
    if(node->le == NULL && node->rig == NULL)  
        return 1;         
    else
        return Leaf_count(node->le) +  Leaf_count(node->rig);  
}  

struct node* newNode(int data)  
{  
    struct node* node = (struct node*)  malloc(sizeof(struct node));  
    node->data = data;  
    node->le = NULL;  
    node->rig = NULL;  
      
return(node);  
}  

int main()  
{  

    struct node *root = newNode(10);  
    root->le = newNode(8);  
    root->rig = newNode(15);  
    root->le->le = newNode(6);  
    root->le->rig = newNode(9);  
    root->rig->rig = newNode(20);
	root->rig->le = newNode(14);
cout << "Leaf count of the tree are : "<<  Leaf_count(root) << endl;  
return 0;  
} 

