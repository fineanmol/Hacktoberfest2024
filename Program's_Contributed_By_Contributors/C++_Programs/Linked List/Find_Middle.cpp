#include <iostream>
using namespace std;
 
class Node{
    public:
        int data;
        Node *next;
};
 
class NodeOperation{
  public:
   
    // add a new node
    void pushNode(class Node** head_ref,int data_val)
    {
       
        
        class Node *new_node = new Node();
        
        new_node->data = data_val;
        new_node->next = *head_ref;
         
        *head_ref = new_node;
    }
     
    //  print a given linked list
    void printNode(class Node *head)
    {
        while(head != NULL)
        {
            cout <<head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
     
    void printMiddle(class Node *head)
    {
        struct Node *slow_ptr = head;
        struct Node *fast_ptr = head;
  
        if (head!=NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->data << "]" << endl;
        }
    }
};
 
// Driver Code
int main()
{
    class Node *head = NULL;
    class NodeOperation *temp = new NodeOperation();
    for(int i=5; i>0; i--)
    {
        temp->pushNode(&head, i);
        temp->printNode(head);
        temp->printMiddle(head);
    }
    return 0;
}