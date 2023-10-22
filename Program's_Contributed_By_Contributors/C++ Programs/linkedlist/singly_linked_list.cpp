#include <iostream>

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    public:
        Node* head;
        LinkedList() {
            head = NULL;
        }
        void push(int data);
        void insert(int data, int position);
        void deleteNode(int position);
        void print();
};

void LinkedList::push(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void LinkedList::deleteNode(int position)
{
    Node* temp = head;
    if(position == 0) {
        head = temp->next;
        delete temp;
        return;
    }
    for(int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

void LinkedList::print()
{
    Node* temp = head;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    LinkedList list;
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.deleteNode(2); // delete node at index 2
    list.print(); // 5 4 2
    return 0;
}
