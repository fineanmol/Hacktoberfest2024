#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            this->next = NULL;
        }
        node(){};
};

class linkedList{

    public:
        node* head, *tail;
        int size = 0;

        linkedList(int data){
            head = NULL;
            tail = NULL;

            createNextNode(data);
        }

        void createNextNode(int data){
            node *temp = new node(data);

            // temp->data = data;
            // temp->next = NULL;

            if(head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            }else{
                tail->next = temp;
                tail = temp;
            }

            size++;
        }

        void print(){
            node *temp = new node;
            temp = head;

            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        void printSize(){
            cout << size << endl;
        }

        void insertAtHead(int data){
            node* temp = new node(data);

            temp->next = head;

            head = temp;
            size++;
        }

        void insertAtTail(int data){
            node* temp = new node(data);

            tail->next = temp;

            tail = temp;
            size++;
        }

        void insertAtPosition(int pos, int data){
            node* newNode = new node(data);
            node* traverse = head;
            int cnt = 1;

            if(pos == 1){
                insertAtHead(data);
            }else if(pos > size){
                insertAtTail(data);
                return;
            }

            while(cnt < pos-1){
                traverse = traverse->next;
                cnt++;
            }

            newNode->next = traverse->next;
            traverse->next = newNode;
            size++;            
        }

        void deleteFirst(){
            node* temp = head;

            head = head->next;
            
            // temp->next = NULL;
            delete temp;
            size--;
        }

        void deleteLast(){
            node* temp = new node;
            temp = head;
            node* prevNode;
            int cnt = 1;

            while(cnt < size){
                prevNode = temp;
                temp = temp->next;
                cnt++;
            }

            prevNode->next = NULL;
            tail = prevNode;

            delete temp;
            size--;
        }

        void deletePosition(int pos){
            node* temp = new node;
            temp = head;
            node* prevNode;
            int cnt = 1;

            while(cnt < pos){
                prevNode = temp;
                temp = temp->next;
                cnt++;
            }

            prevNode->next = temp->next;

            delete temp;
            size--;
        }

        void search(int element){
            node *temp = new node;
            temp = head;
            int cnt = 1;

            while(temp != NULL){
                if(temp->data == element){
                    cout << "Element found at " << cnt << " position." << endl;
                    return;
                }
                temp = temp->next;
                cnt++;
            }
            cout << "Element not found." << endl;
        }

};

int main(){

    linkedList l1(10);
    l1.createNextNode(20);
    l1.createNextNode(30);
    l1.createNextNode(40);
    l1.print();

    l1.insertAtHead(1);
    l1.print();

    l1.insertAtTail(50);
    l1.print();

    l1.insertAtPosition(10, 60);
    l1.print();
    // l1.printSize();

    l1.deleteFirst();
    l1.print();    

    l1.deleteLast();
    l1.print();

    l1.deletePosition(3);
    l1.print();

    l1.search(40);
    l1.search(30);

    l1.printSize();

    return 0;
}