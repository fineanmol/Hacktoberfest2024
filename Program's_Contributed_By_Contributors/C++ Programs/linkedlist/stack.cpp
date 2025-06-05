#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Linked
{
public:
   Node *top;
    Linked()
    {
        top = NULL;
    }
    Node *create_node(int val)
    {
        Node *ptr;
        ptr = new Node;
        ptr->data = val;
        ptr->next = NULL;
        return ptr;
    }
    void push(int x)
    {
        // cout<<"aayo push ma"<<endl;
        Node* ptr = create_node(x);
        
        if (top == NULL)
        {
            top = ptr;

        }
        else
        {
            ptr->next = top;
            top = ptr;
             
        }
    }
    void pop()
    {
        Node *ptr;
        if (top == NULL)
        {
            cout << "No data to be deleted" << endl;
        }
        else
        {
            ptr = top;
            top = top->next;
            cout<<"Data deleted is: "<<ptr->data<<endl;
            delete ptr;
        }
    }
    void display(){

        Node *ptr;
        ptr=top;
        while(ptr!=NULL){
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }

    }
};
int main(){
    Linked l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.pop();
    l.display();

}