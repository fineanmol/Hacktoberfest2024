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

bool isLoopPresent(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast!=NULL && fast->next!=NULL){

    slow = slow->next;
    fast = fast->next->next;

    if(fast == slow){
      return true;  
    }

  }

  return false;
}

void removeLoop(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast!=NULL && fast->next!=NULL){

    slow = slow->next;
    fast = fast->next->next;

    if(fast == slow){
      break; 
    }

  }

  Node* temp = head;
  Node* prev = head;

  do{
    prev = head;
    head = head->next;
    temp = temp->next;
  }while(head!=temp);

  prev->next = NULL;

}

int main(){

  Node* head = new Node(10);

  head->next = new Node(20);

  head->next->next = new Node(30);

  head->next->next->next = new Node(40);

  head->next->next->next->next = head;

  cout<<isLoopPresent(head);

  removeLoop(head);

  cout<<isLoopPresent(head);

  return 0;
}
