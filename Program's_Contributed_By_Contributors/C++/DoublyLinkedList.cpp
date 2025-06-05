
#include <bits/stdc++.h>
using namespace std;


// Creating node data structure
class node{
public:
  int data;
  node *prev;
  node *next;

  node (int val){
  data = val;
  prev = NULL;
  next = NULL;
  }
};

// Inserting new node at head
void insertAtHead (node * &head, int val){
  node *n = new node (val);
  n->next = head;
  if (head != NULL)  head->prev = n;
  head = n;
}

// Inserting new node at tail or at middle of doubly linked list
void insertAtTail (node * &head, int val){
  node *n = new node (val);
  if (head == NULL){
      insertAtHead (head, val);
      return;
  }

  node *temp = head;
  while (temp->next != NULL){
      temp = temp->next;
  }
  temp->next = n;
  n->prev = temp;

}

// Deletion of node
void deletenode (node * &head, int val){
  node *temp = head;
  
//  deleting node at head
  if (temp->data == val){
      head = head->next;
      head->prev = NULL;
  } 
  
  //  deleting node at tail or at middle of doubly linked list
  else {
      while (temp->data != val){
	        temp = temp->next;
	    }
      if (temp->next != NULL)  temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
   }
  
  delete temp;
}


// printing data of nodes in doubly linked list
void print (node * head){
  node *temp = head;
  while (temp != NULL){
      cout << temp->data << " ";
      temp = temp->next;
    } 
  cout << endl;
}

int main () {
  node *head = NULL;
  insertAtHead (head, 1);
  insertAtTail (head, 2);
  insertAtHead (head, 3);
  insertAtTail (head, 4);
  insertAtTail (head, 5);
  print(head);
  insertAtHead (head, 83);
  deletenode (head, 5);
  deletenode (head, 83);
  deletenode (head, 3);

  print (head);
}
