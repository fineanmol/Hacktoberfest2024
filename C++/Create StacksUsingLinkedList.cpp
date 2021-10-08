#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size;

    public:

    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop(){
        if(isEmpty()){
            return 0;
        }