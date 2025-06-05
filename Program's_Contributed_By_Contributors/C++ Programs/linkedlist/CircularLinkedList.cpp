#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    ~CircularLinkedList()
    {
        if (head != nullptr)
        {
            Node *temp = head->next;
            while (temp != head)
            {
                Node *prev = temp;
                temp = temp->next;
                delete prev;
            }
            delete head;
        }
    }

    void append(int data)
    {
        Node *new_node = new Node(data);
        if (head == nullptr)
        {
            head = new_node;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node *temp = head;
        do
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << head->data << std::endl;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    cll.append(4);

    std::cout << "Circular Linked List:" << std::endl;
    cll.display();

    return 0;
}
