#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkList{
    Node *head1,*tail1,*head2,*tail2,*mergehead;
    public:
        LinkList()
        {
            head1=NULL;
            tail1=NULL;
            head2=NULL;
            tail2=NULL;
        }
        void create1();
        void create2();
        void merge();
        void Display(Node*);
        Node* gethead1(){return head1;}
        Node* gettail1(){return tail1;}
        Node* gethead2(){return head2;}
        Node* gettail2(){return tail2;}
        Node* getmergehead(){return mergehead;}
};
void LinkList::create1()
{
    int size;
    cout<<"Enter the size of LinkList : ";
    cin>>size;
    while(size--)
    {
        Node *temp=new Node();
        cout<<"Enter data of Node : ";
        cin>>temp->data;
        temp->next=NULL;
        if(head1==NULL && tail1==NULL)
        {
            head1=tail1=temp;
        }else
        {
            tail1->next=temp;
            tail1=temp;
        }
    }
}


void LinkList::create2()
{
    int size;
    cout<<"Enter the size of LinkList : ";
    cin>>size;
    while(size--)
    {
        Node *temp=new Node();
        cout<<"Enter data of Node : ";
        cin>>temp->data;
        temp->next=NULL;
        if(head2==NULL && tail2==NULL)
        {
            head2=tail2=temp;
        }else
        {
            tail2->next=temp;
            tail2=temp;
        }
    }
}


void LinkList::merge()
{
    Node *t=new Node();
    t->data=0;
    t->next=NULL;
    mergehead=t;
    Node *p=head1,*q=head2,*z=mergehead;
    while(p && q)
    {
        Node *temp=new Node();
        if(p->data<q->data)
        {
            temp->data=p->data;
            z->next=temp;
            z=z->next;
            p=p->next;
        }else if(q->data<p->data){
            temp->data=q->data;
            z->next=temp;
            z=z->next;
            q=q->next;                
        }
        else
        {
            temp->data=q->data;
            z->next=temp;
            z=z->next;
            q=q->next;
            p=p->next;              
        }
        temp->next=NULL;
    }
    while(p)
    {
            Node *temp=new Node();
            temp->data=p->data;
            temp->next=NULL;
            z->next=temp;
            z=z->next;
            p=p->next; 
    }
    while(q)
    {
            Node *temp=new Node();
            temp->data=q->data;
            temp->next=NULL;
            z->next=temp;
            z=z->next;
            q=q->next; 
    }
    mergehead=mergehead->next;
}

void LinkList::Display(Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Display(p->next);
    }
}

int main()
{
    LinkList L;
    L.create1();
    L.create2();
    cout<<"\n";
    L.Display(L.gethead1());
    cout<<"\n";
    L.Display(L.gethead2());
    L.merge();
    cout<<"\n";
    L.Display(L.getmergehead());
    return 0;
}
