#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void addNode(node *&head, int data)
{
	node *newnode = new node(data);
	if (head == NULL)
	{
		head = newnode;
		return;
	}
	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}

void reverseLinkedList(node *&head)
{
    // For 0 or 1 node linked list
    if (head == NULL || head->next == NULL)
        return;

    node *curr = head;
    node *prev = NULL;
    while (curr)
    {
        node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void traverse(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	node *head = NULL;
	addNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);
	addNode(head, 50);
	addNode(head, 60);
	traverse(head);
	reverseLinkedList(head);
	traverse(head);
	return 0;
}
