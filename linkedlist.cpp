// Retain M nodes and delete N nodes problem
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
 Node *skipMdeleteN(Node *head, int m, int n)
 {
 	// Write your code here
     if(head==NULL)
         return head;
     Node *temp=head,*prev=NULL;
     while(temp!=NULL){
       // Skip the m node from the linked list
         for(int i=0;i<m && temp!=NULL;i++){
             prev=temp;
             temp=temp->next;
         }
      // Delete n node from the linked list
         for(int i=0;i<n && temp!=NULL;i++){
             Node *d=temp;
             temp=temp->next;
             delete d;
         }
        // Connect the prev->next to the temp after deleting n node
         if(prev!=NULL)
     	 	prev->next=temp;
     }
     
     if(prev==NULL)
         return NULL;
     return head;
 }

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}