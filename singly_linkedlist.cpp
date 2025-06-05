#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;
        // nl free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data" << value << endl;
    }
};
void insert(node *&head, int d)
{

    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void itail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void mid(node* &tail,node *&head, int pos, int d)
{
    node *temp = head;
    int cnt = 1;
    if (pos == 1)
    {
        insert(head, d);
        return;
    }
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
if (temp->next==NULL) {
itail(tail,d) ;
return ;}
    node *ins = new node(d);
    ins->next = temp->next;
    temp->next = ins;
}
void deleteNode(int position, node *&head)
{
    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        // delete temp;
    }
    else
    { // deteting any middle node or last node
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;

            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *node1 = new node(1);
    // cout<<node1->data<<endl;
    // cout<<node1->next;
//ayush savner
    node *head = node1;
    node *tail = node1;

    insert(head, 10);
    itail(tail, 22);
    print(head);
 //ayushsavner
 cout<<"Ayush";
    print(head);
    deleteNode(3, head);
    print(head);
}
