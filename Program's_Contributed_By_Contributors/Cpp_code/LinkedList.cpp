#include <iostream>
using namespace std;

class Node{
	private:
		
		int data;
		Node* next;
	public:
		Node()
		{
			data =0;
			next = NULL;
		}
		
		void setData(int d)
		{
			data = d;
		}
		void setNext(Node* n)
		{
			next = n;
		}
		int getData()
		{
			return data;
		}
		void setall(int k,int d,Node* n)
		{
			
			data = d;
			next = n;
		}
		Node* getnextNode(){
			return next;
		}
		
		
	
		
};

class List{
	private:
		Node* head;
		Node* current;
		Node* last;
	public:
		List()
		{
			head = NULL;
			current = NULL;
			last = NULL;
		}
	void AddToList(int v)
	{
		Node *newNode = new Node();
		newNode->setData(v);
		if(head==NULL)
		{
			newNode->setNext(NULL);
			head = newNode;
			
			current =newNode;
		}
		else
		{
			newNode->setNext(current->getnextNode());
			current->setNext(newNode);
			current= newNode;
			
		}
	}
	void PristList()
	{
		Node *start = head;
	
		while(start->getnextNode() != NULL)
		{
			cout<<start->getData()<<endl;
			start = start->getnextNode();
		}
		if(start->getnextNode()==NULL)
		{
			cout<<start->getData()<<endl;
		}
	}
	void DeleteN(int val)
	{
		Node *start = head;
		
		if(start->getnextNode()==NULL)
		{
			start->setData(0);
			cout<<"Working";
		}
		else
		{
		
			while(start->getnextNode()!=NULL)
			{
				if(start->getData()==val)
				{
					start->setData(0);
					start= start->getnextNode();
					
				}
				else if(start->getData()!=val)
				{
					start= start->getnextNode();
				}
			}
		}
	}
};

int main()
{
	List L;
	int choise;
	bool a= true;
	
	while(a==true)
	{
	
	cout<<"\n\nPress 1 to add to the list\n";
	cout<<"Press 2 to Print the list\n";
	cout<<"Press 3 To Remove Val\n";
	cout<<"Press 4 To Exit \nChoise: ";
	cin>>choise;
	if(choise==1)
	{
		cout<<"\nEnter the value to be added: ";
		int b;
		cin>>b;
		L.AddToList(b);
	}
	if(choise==2)
	{
		L.PristList();
	}
	if(choise==3)
	{
		cout<<"\nEnter value to Removed: ";
		int q;
		cin>>q;
		L.DeleteN(q);
	}
	if(choise==4)
	{
		a=false;
	}
	}
	
	
}
