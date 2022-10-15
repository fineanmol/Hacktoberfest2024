#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        this->data = x;
        this->next = NULL;
    }
};

Node *insertBeforeHead(Node *head, int x) {
    Node *newNode = new Node(x);
    newNode->next = head;
    return newNode;
}
//2x 3y 4null
//2x 5t 3y 4null
void insertAfterHead(Node *head, int x) {
    if(head==NULL)
        return;
    Node *newNode = new Node(x);
    Node *temp = head->next;
    head->next = newNode;
    newNode->next = temp;
}

void print(Node *head) {
    Node *curr = head;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* insertAtEnd(Node *head, int x) {

    Node *newNode = new Node(x);

    if(head==NULL) {
       return newNode; 
    }

    Node *temp = head;

    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


//1x 3b 4h 10i 7null 8
void insertAfterNode(Node* head, int x, int y) {
    Node* temp = head;
    while(temp!=NULL) {
        if(temp->data==x) {
            Node *newNode = new Node(y);
            Node *curr = temp->next;
            temp->next = newNode;
            newNode->next = curr;
            break;
        }
        else {
            temp = temp->next;
        }         
    }
}

//1y 3y 5u 5
bool searchNumber(Node *head, int x) {
    Node *temp = head;
    while(temp!=NULL) {
        if(temp->data==x)
            return true;
        else
            temp = temp->next;
    }
    return false;
}

Node* deleteHead(Node* head) {
    if(head==NULL)
        return NULL;

    Node* temp = head->next;
    delete head;
    return temp;
}

//1t 3y 5null 5
//1t 3y 5x 8n 9null
Node* deleteGivenNode(Node* head, int x) {
    if(head==NULL)
        return NULL;
    else if(head->data==x) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    else {
        Node* curr=head;
        while(curr->next!=NULL) {
            if(curr->next->data==x) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return head;
            }
            else 
                curr = curr->next;
                
        }
        return head;
    }

}

//1z 3t 6y 8u 9null
//9y 8t 6z 3head 1null

Node* reverseLinkedlist(Node* head) {

    vector <int> numbers;
    Node* temp = head;
    while(temp!=NULL) {
        numbers.push_back(temp->data);
        temp = temp->next;
    }
    int count = numbers.size();
    Node* curr = head;
    for(int i=count-1; i>=0; i--) {
        curr->data = numbers[i];
        curr = curr->next;
    }
    return head;
}




int main() {
    Node *head = new Node(5);
    insertAfterHead(head,6);
    insertAfterHead(head,0);
    head = insertBeforeHead(head,1);
    head = insertAtEnd(head,123);
    print(head);
    head = deleteGivenNode(head,123);
    print(head);
    head = reverseLinkedlist(head);
    print(head);

}


