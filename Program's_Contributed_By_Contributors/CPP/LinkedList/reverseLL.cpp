#include<iostream>
#include<cstdio>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

void printList(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}

Node* reverse(Node* head){
  Node* curr = head;
  Node* nextNode = NULL;
  Node* prevNode = NULL;

  while(curr!=NULL){
    nextNode = curr->next;
    curr->next = prevNode;
    prevNode = curr;
    curr = nextNode;
  }

  return prevNode;
}

int main(){

  Node* head = new Node(10);

  head->next = new Node(20);

  head->next->next = new Node(30);

  head->next->next->next = new Node(40);

  head->next->next->next->next = new Node(50);

  printList(head);
  cout<<endl;

  Node* new_head = reverse(head);

  printList(new_head);
  cout<<endl;

  return 0;
}
