#include <iostream>
#include "Queuecpp.h"

class Tree
{
	public:
		Node *root;
		Tree()
		{
			root=NULL;
		}
		void CreateTree();
		void PreOrder()
		{
			PreOrder(root);
		}
		void PreOrder(Node *p);
		void InOrder(Node *p);
		void PostOrder(Node *p);
		void LevelOrder(Node *p);
		void Height(Node *root);
};

void Tree::CreateTree()
{
	Node *p,*t;
	int x;
	Queue q(100);
	
	cout<<"Enter the root Node"<<endl;
	cin>>x;
	root=new Node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	q.enqueue(root);
	
	while(!q.isEmpty())
	{
		p=q.dequeue();
		cout<<"Enter the left child of "<<p->data<<endl;
		cin>>x;
		if(x!=-1)
		{
			t= new Node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			q.enqueue(t);
		}
		cout<<"Enter the right child of "<<p->data<<endl;
		cin>>x;
		if(x!=-1)
		{
			t= new Node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			q.enqueue(t);
		}
	}
	
}

void Tree::PreOrder(Node *p)
{
	cout<<p->data<<"\t";
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}

void Tree::InOrder(Node *p)
{
	InOrder(p->lchild);
	cout<<p->data<<"\t";
	InOrder(p->rchild);
}

void Tree::PostOrder(Node *p)
{
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout<<p->data<<"\t";
}

void Tree::LevelOrder(Node *p)
{
	Queue q(100);
	
	cout<<root->data<<endl;
	q.enqueue(root);
	
	while(!q.isEmpty())
	{
		root=q.dequeue();
		if(root->lchild)
		{
			cout<<root->lchild->data<<endl;
			q.enqueue(root->lchild);
		}
		if(root->rchild)
		{
			cout<<root->rchild->data;
			q.enqueue(root->rchild);
		}
	}
	
}

int main()
{
	Tree t;
	t.CreateTree();
	cout<<"PreOrder"<<endl;
	t.PreOrder();
	cout<<endl;
	t.PostOrder(t.root);
	cout<<endl;
	t.InOrder(t.root);
	cout<<endl;
	t.LevelOrder(t.root);
	return 0;
}

