#include <iostream>


//class defines a node of a linked list
class Node {
public:
    int data;
    Node *next;

    Node() {}
    Node(int data) : data(data) {}
    Node(int data, Node *next) : data(data), next(next) {}

};


//class defines linked list and its functions
class LinkedList {
public:
    Node *head, *tail;
    LinkedList();
    void insert(int data);
    void insertPos(int data, int pos);
    void deletePos(int index);
    int getElementAt(int index);
    int *findOccurrence(int data);
    int findMiddle();
    int length();
    void print();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

//creates a node and then inserts at the end of the list
void LinkedList::insert(int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

//creates a node and then inserts at a given position
void LinkedList::insertPos(int data, int pos) {
    Node *temp = new Node(data);
    Node *prev = new Node;
    Node *curr = new Node;
    curr = head;
    for (int i = 0; i < pos; ++i) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
}

//deletes a node at a given pos
void LinkedList::deletePos(int index) {
    Node *prev = new Node;
    Node *curr = new Node;
    Node *temp = new Node;
    curr = head;
    for (int i = 0; i < index; ++i) {
        prev = curr;
        curr = curr->next;
    }
    temp = curr;
    prev->next = curr->next;
}

//returns the element at the given index
int LinkedList::getElementAt(int index) {
    Node *curr = new Node;
    curr = head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

int *LinkedList::findOccurrence(int data) {
    int p[length()];
    Node *curr = new Node;
    curr = head;
    for (int i = 0; i < length(); ++i) {
        if (curr->data == data) {
            p[i] = i;
        }
    }
}

//finds and returns the middle of the linked list. If the list has even number of nodes then it returns the second of the two middle nodes
int LinkedList::findMiddle() {
    Node *curr = head;
    for (int i = 0; i < length() / 2; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

//returns the length of a linked list
int LinkedList::length() {
    int length{};
    Node *temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

//prints all the nodes in a linked list separated by a space
void LinkedList::print() {
    Node *curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr= curr->next;
    }
    std::cout << std::endl;
}

int main() {
//    LinkedList list; //creates a list

//    for (int i = 0; i < 5; ++i) {
//        list.insert(i);
//    } //inserts 0-4 in the linked list
//    list.print(); //prints the list
//
//    list.insertPos(9,2); //inserts 9 at index 2
//    list.print();
//
//    list.deletePos(3); //deletes element at index 3
//    list.print();
//
//    std::cout << "Element at index 4: " << list.getElementAt(4) << std::endl; //returns element at index 4
//
//    std::cout << "Element at the middle of list: " << list.findMiddle() << std::endl; //returns element at middle of list
//
//    std::cout << "Length of list: " << list.length() << std::endl; //returns length of list

    LinkedList l1;
    LinkedList l2;
    for (int i = 1; i < 10; i+=2) {

    }
    return 0;
}


