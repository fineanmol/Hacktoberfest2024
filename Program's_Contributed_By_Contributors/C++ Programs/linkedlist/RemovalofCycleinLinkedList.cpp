//

#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
  Node(int val){
    data = val;
    next = NULL;
  }
};
void InsertAtHead(Node *&head,int val){
  if(head==NULL){
    head = new Node(val);
    return;
  }
  Node *n = new Node(val);
  n->next = head;
  head = n;
}
Node * Input(){
  Node * head = NULL;
  int d;
  cin>>d;
  while(d!=-1){
    InsertAtHead(head,d);
    cin>>d; 
  }
  return head;
}
void PrintLL(Node *head){
  while(head!=NULL){
    cout<<head->data<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}
void makecycle(Node *head,int pos){
  Node * temp = head;
  Node * loop = NULL;
  int count=1;
  while(temp->next!=NULL){
    if(count==pos){
      loop = temp;
    }
    temp = temp->next;
    count++;
  }
  temp->next = loop;
}
void RemoveCycle(Node *head){
  Node *slow = head;
  Node *fast = head;
  while(fast->next!=NULL && fast->next->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow==fast){
      break;
    }
  }
  //if loop starts at first node
  if(fast==head){
    while(slow->next!=fast){
      slow=slow->next;
    }
    slow->next = NULL;
    return;
  }
  //Meeting at starting point of cycle
  fast = head;
  while(fast->next!=slow->next){
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = NULL;
}
int main(){
  Node *head = Input();
  PrintLL(head);
  int pos;
  cin>>pos;
  makecycle(head,pos);
  RemoveCycle(head);
  PrintLL(head);
}