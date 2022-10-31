#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    
    //contructor of node class for having at least one value
    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor for deleting the values in LL
    ~node()
    {
        int value = this -> data;
        // memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

        cout<<"memory free is for value : "<<value<<endl;
    }
};

void deletion(int posi, node* &head)
{
    if(posi==1){
        //deleting first element
        node* temp = head;
        head = head -> next;
        
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting remaining element
        node* prev=NULL;
        node* curr=head;
        int cnt = 1;

        while(cnt<posi){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr->next = NULL;  
        delete curr;
    }
}

void insertAtHead(node* &head,int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node* &tail,int data)
{
    node *temp = new node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtMiddle(node* &head,node* &tail ,int data,int pos)
{
    //inserting at first position thats why calling head function
    if(pos==1){
        insertAtHead(head, data);
        return;
    }

    node *temp = head;
    int count=1;
    //traverse to given position
    while(count<pos-1){
        temp = temp -> next;
        count++;
    }

   
    //creating a new node for middle data
    node *middle = new node(data);
    middle->next=temp->next;
    temp->next=middle;


     //inserting at last position thats why calling tail function
    if(temp -> next ==NULL){
        insertAtTail(tail,data);
        return;
    }



}

void print(node* &head)
{
    node *temp = head;
    while(temp!=NULL){
        cout<<temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    //created a new node or ccreate a object of node class
    node *node1=new node(10);
    //cout<<node1 -> data << endl;
    //cout<<node1 -> next << endl;

    //head pointed to node1
    node *head = node1;
    node *tail = node1;

    print(head);
    

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtMiddle(head,tail,24,4);
    print(head);

    cout<<"head : "<< head -> data << endl;
    cout<<"tail : "<< tail -> data << endl;

    deletion(4,head);
    print(head);

    cout<<"head : "<< head -> data << endl;
    cout<<"tail : "<< tail -> data << endl;

    return 0;
}
