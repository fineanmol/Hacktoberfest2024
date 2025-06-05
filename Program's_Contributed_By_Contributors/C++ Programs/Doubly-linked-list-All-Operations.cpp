#include<iostream>
using namespace std;
class node
{ 
    public:
    int value;
    node *next = NULL;
    node *prev = NULL;

    node(int n)
    {
        value = n;

    }

};
class DoublyLinked
{
    public:
        node *head = NULL;
        node* tail=NULL;
    
void InsertAtStart(int n)
    {
        node *new_node = new node(n);

        if(head==NULL && tail==NULL)
        {
            head = new_node;
            tail = new_node;

        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;

        }
    }
void insertAtEnd(int n)
    {
        node *new_node = new node(n);
        if(head==NULL && tail==NULL)
        {
            head = new_node;
            tail = new_node;

        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
void printForward()
	{
		node* temp = head;
		if (temp == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
		}
	}
void PrintBack()
    {
       node* temp = tail;
		if (tail == NULL && head==NULL)
		{
			cout << "List is empty" << endl;
		} 
        else
		{
			while (temp != NULL)
			{
				cout << temp->value << " ";
				temp = temp->prev;
			}
		}
    }
void InsertAfterIndex(int n)
    {
        cout << "\n Enter the index: ";
        int index;
        cin >> index;
        int c = lengthOfList();
        if(index>c)
        {
            cout << "Index does not exist";
        }
    else{
        node *current = head;
        if (tail == NULL && head == NULL)
		{
            node *new_node = new node(n);
            head=new_node;
            tail=new_node;

		} 

 else{
       

        for (int i = 0; i <index; i++)
        {
            current = current->next;
            
        }
        if(current->next==NULL)
        {
            insertAtEnd(n);
        }
        else
       { node* new_node=new node(n);
        new_node->prev=current;
        new_node->next=current->next;
        current->next->prev=new_node;
        current->next= new_node;}



    }}
    }
void InsertBeforeIndex(int n)
{
    cout << "\nEnter the index: ";
    int index;
    cin >> index;
    
    if (head == NULL && tail == NULL)
    {
        // List is empty, create a new node and set head and tail.
        node* new_node = new node(n);
        head = new_node;
        tail = new_node;
    }
    else
    {
        node* new_node = new node(n);
        node* current = head;

        for(int i = 0; i < index - 1; i++)
        {
            if (current->next == NULL)
            {
                cout << "\nIndex does not exist";
                break;
            }
            current = current->next;
        }

        if (current->prev == NULL)
        {
            // Insert before the current head node.
            new_node->next = current;
            current->prev = new_node;
            head = new_node;
        }
        else
        {
            // Insert before the current node.
            new_node->prev = current->prev;
            new_node->next = current;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
}

void DeleteAtIndex(int key)
		{
			node *temp=head;
			node *prev;
			while(temp!=NULL)
			{
				if(temp->value==key)
				{
					prev->next=temp->next;
					delete temp;
					return;
				}
				else
				{
					prev=temp;
					temp=temp->next;
				}
			}
			cout<<"Number to be deleted is not found"<<endl;
		}
void deleteStart()
{
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
}
void deleteAtEnd()
{
    node* temp=tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}
void middle()
{
    node *trav = head;
    int count = 0;
    while(trav!=NULL)
    {
   trav=trav->next;
    count++;
    }
    int mid = count/2;
    node *temp = head;
    for(int i=0; i<mid; i++)
    {
        temp=temp->next;
    }
    cout<<"Middle element is: "<<temp->value<<endl;

}
void reverse()
{
    node *temp = NULL;
    node *current = head;
    while(current!=NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL)
    {
        head = temp->prev;
    }


}
void middleWithoutPointer()
{
    node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle element is: "<<slow->value<<endl;
}
int lengthOfList()
{
    node *trav = head;
    int count = 0;
    while(trav!=NULL)
    {
   trav=trav->next;
    count++;
    }
    return count;
}
};
int main()
{
    DoublyLinked list;
    list.InsertAtStart(90);
    list.InsertAtStart(70);
    list.InsertAtStart(80);
    list.insertAtEnd(100);
    list.insertAtEnd(70);
    list.insertAtEnd(5);
    cout << "-----------------Print List-----------------"<<endl;
    cout << "List: ";
    list.printForward();
    cout << endl;
     cout << endl;
 cout << "--------------Insert after index--------------------"<<endl;

    list.InsertAfterIndex(1);
    list.printForward();
    cout << endl;

    cout << endl;
 cout << "--------------Insert before index:--------------------"<<endl;
    list.InsertBeforeIndex(6);
    list.printForward();

  cout << endl;
 cout << "--------------Print Backwards::--------------------"<<endl;
 
    list.PrintBack();
    cout << endl;
    
  cout << endl;
 cout << "-------------DeleteAtIndex--------------------"<<endl;
 
    list.DeleteAtIndex(6);
     list.printForward();
     cout << endl;
 cout << endl;
 cout << "-------------DeleteAtStart--------------------"<<endl;
 

     
     list.deleteStart();
    list.printForward();
     cout << endl;

      cout << endl;
 cout << "-------------DeleteAtEnd--------------------"<<endl;
 
     list.deleteAtEnd();
     list.printForward();
     cout << endl;
     cout << endl;
 cout << "-------------Print Middle --------------------"<<endl;
 
    list.middle();

cout << endl;
cout << endl;
 cout << "-------------Reverse--------------------"<<endl;
 list.reverse();
 list.printForward();

 cout << endl;
cout << endl;
 cout << "------------Middle without pointer --------------------"<<endl;
 list.middleWithoutPointer();
 list.printForward();
}
