#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;

    }
};

class Dlinklist
{
private:
    Node *head;
public:
    Dlinklist(){
        head=NULL;
    };
    void in_Beg(int value);
    void display();
    int count();
    void in_Any(int value , int pos);
    void del_Beg();
    void del_any(int pos);
    void rev_display();
};

int Dlinklist :: count(){
    int c=0;
    if (head==NULL)
    {
        return c;
    }
    else{
        c++;
    Node* p=head;
    while (p->next != NULL)
    {
         p = p->next;
         c++;
    }
    return c;
    }
}

void Dlinklist :: in_Beg(int value){
    if (head==NULL)
    {
        Node *temp = new Node(value);
        head=temp;
        cout<<"inserted 1"<<endl;
        return;
    }
    else
    {
        Node *temp = new Node(value);
        head->prev=temp;
        temp->next=head;
        head=temp;
        cout<<"inserted"<<endl;
        return;
    }
    
}

void Dlinklist :: display()
{
    cout << "The items are" << endl;
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "\t";
        current = current->next;
    }
}

void Dlinklist :: in_Any(int value ,int pos){
    if (pos<0 || pos>count())
    {
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        if (pos==0)
        {
            in_Beg(value);
        }
        else
        {
            Node* temp=new Node(value);
            Node* p = head;
            for (int i = 0; i < pos-1; i++)
            {
                p=p->next;
            }
            temp->prev=p->prev;
            p->prev->next=temp;
            temp->next=p;
            p->prev=temp;
            
        }
        
    }
   cout<<"inserted"<<endl; 
}

void Dlinklist :: del_Beg(){
    if (head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    else if (head->next==NULL)
    {
        head=NULL;
        return;
    }
    
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    
}

void Dlinklist :: del_any(int pos){
    if (pos<1 || pos>count())
    {
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        if (pos==1)
        {
            del_Beg();
        }
        else
        {
            Node *p=head;
             for (int i = 0; i < pos-1; i++)
             {
                p=p->next;
             }
            Node *temp=p;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            delete temp;
        }
        
    }
}

void Dlinklist:: rev_display(){
    Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    while (p!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->prev;
    }
    
}

int main(){
    Dlinklist p;
    p.in_Beg(4);
    p.in_Beg(2);
    p.in_Beg(1);
    p.display();
    cout<<endl;
    p.in_Any(3,3);
    p.display();
    cout<<endl;
    p.del_any(3);
    p.display();
    cout<<endl;
    p.rev_display();
    
    
return 0;
}