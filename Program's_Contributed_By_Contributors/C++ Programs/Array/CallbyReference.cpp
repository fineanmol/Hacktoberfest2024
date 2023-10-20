
#include<iostream>
using namespace std;

void swap(int, int);
void swap(int *, int *);

int main()
{
	int a,b;
	cout<<"Enter First number:";
	cin>>a;
	cout<<"Enter Second number:";
	cin>>b;
	cout<<"\nBefore Call by value.";
	cout<<"\n1st number :"<<a;
	cout<<"\n2nd number :"<<b;
	swap(a,b);
	cout<<"\nAfter Call by value.";
	cout<<"\n1st number :"<<a;
	cout<<"\n2nd number :"<<b;
	cout<<"\n-----------------------------";
	cout<<"\nBefore Call by reference.";
	cout<<"\n1st number :"<<a;
	cout<<"\n2nd number :"<<b;
	swap(&a,&b);
	cout<<"\nAfter Call by reference.";
	cout<<"\n1st number :"<<a;
	cout<<"\n2nd number :"<<b;
	
}

void swap(int x, int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}

void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
