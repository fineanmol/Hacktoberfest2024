#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;

        node() = default;

        node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class DoublyLinkedList{
    public:
        node *head, *tail;
        int size = 0;

        DoublyLinkedList(int data){
            head = NULL;
            tail = NULL;

            createNextNode(data);
        }

        void createNextNode(int data){
            node* newNode = new node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                newNode = NULL;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;

                tail = newNode;
            }

            size++;
        }

        void insertAtHead(int data){
            node* newNode = new node(data);
            newNode->next = head;
            
            head->prev = newNode;

            head = newNode;

            size++;
        }

        void insertAtTail(int data){
            createNextNode(data);
        }

        void insertAtPosition(int pos, int data){
            node* newNode = new node(data);
            node* temp = new node;
            temp = head;
            int cnt = 1;
            
            if(pos == 1){
                insertAtHead(data);
                return;
            }
            else if(pos == size || pos>size){
                insertAtTail(data);
                return;
            }

            while(cnt < pos-1){
                temp = temp->next;
                cnt++;
            }

            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;

            size++;
        }

        void deleteAtHead(){
            node* temp = new node;
            temp = head;

            head = head->next;
            head->prev = NULL;

            delete temp;

            // cout << head->prev->data;
            size--;
        }

        void deleteAtTail(){
            node* temp = new node;
            temp = tail;

            tail = tail->prev;
            tail->next = NULL;

            delete temp;

            // cout << tail->next;
            size--;
        }

        void deleteAtPosition(int pos){
            node* temp = new node;
            node* prev_node = new node;
            temp = head;
            int cnt = 1;

            if(pos == 1){
                deleteAtHead();
                return;
            }
            else if(pos == size || pos>size){
                deleteAtTail();
                return;
            }

            while(cnt <= pos-1){
                prev_node = temp;
                temp = temp->next;
                cnt++;
            }

            prev_node->next = temp->next;
            temp->next->prev = prev_node;

            delete temp;

            size--;
        }

        void print(){
            node* temp = new node;
            temp = head;

            while(temp != NULL){
                cout << temp->data << " - ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        void printReverse(){
            node* temp = new node;
            temp = tail;

            while(temp != NULL){
                cout << temp->data << " - ";
                temp = temp->prev;
            }
            cout << "NULL" << endl;
        }

        void printSize(){
            cout << size << endl;
        }
};

int main(){

    DoublyLinkedList dl(10);
    dl.createNextNode(20);
    dl.createNextNode(30);

    cout << "Traverse from head : ";
    dl.print();

    cout << "Traverse from tail : ";
    dl.printReverse();

    cout << "Size : ";
    dl.printSize();

    dl.insertAtHead(1);
    dl.print();

    dl.insertAtTail(40);
    dl.print();

    dl.insertAtPosition(2, 50);
    dl.print();
    
    cout << "Size : ";
    dl.printSize();

    dl.deleteAtHead();
    dl.print();

    dl.deleteAtTail();
    dl.print();

    dl.deleteAtPosition(3);
    dl.print();
    dl.printReverse();
    dl.printSize();

    dl.deleteAtHead();
    dl.print();
    dl.insertAtPosition(2, 20);
    dl.createNextNode(40);
    dl.insertAtPosition(4,50);

    // dl.deleteAtHead();

    dl.print();

    return 0;
}