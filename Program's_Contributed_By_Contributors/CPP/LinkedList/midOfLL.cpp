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

Node* findMid(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main(){

  Node* head = new Node(10);

  head->next = new Node(20);

  head->next->next = new Node(30);

  head->next->next->next = new Node(40);

  head->next->next->next->next = new Node(50);

  Node* mid = findMid(head);

  cout<<"Middle element of the Linked List is: "<<mid->data;

  return 0;
}
