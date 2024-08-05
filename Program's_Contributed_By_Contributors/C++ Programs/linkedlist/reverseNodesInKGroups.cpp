#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        while(this-> next != NULL){
            Node* temp = this->next;
            this -> next = NULL;
            delete next;
        }
    }

};

void insertAtHead(Node* &head, int d){
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

Node* reverseListInKGroup(Node* &head, int k){
    if (head == NULL){
        return head;
    }

    Node *prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    int cnt = 0;

    while(cnt < k && curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if (next != NULL)
        head -> next = reverseListInKGroup(next, k);

    return prev;

}

void printLL(Node* head) {
    cout << "inside func" << endl;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {


    int arr[] = {20,30,40,50,60,70,80};
    
    Node* node1 = new Node(10);
    Node* head = node1;

    for(int i = 0; i < 7; i++){
        insertAtHead(head, arr[i]);
    }
    int k = 3;

    printLL(head);

    Node* newHead = reverseListInKGroup(head , k);

    printLL(newHead);

    return 0;
}