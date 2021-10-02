#include<iostream>
#include<math.h>
using namespace std;

class node{

	public:
		int power;
		int coefficient;
		node *next;
};

int main(){
	int a,b,c=0,d=0,e,f,x;
	node *start=NULL,*temp,*ptr,*start2=NULL,*temp2,*ptr2,*start3=NULL,*temp3,*ptr3,*start4=NULL,*temp4,*ptr4;
	
	cout<<"P1"<<endl;
	cout<<"enter highest degree of coefficient"<<endl;
	cin>>a;
	
	for(int i=a;i>=0;i--){
		ptr=new node();
		ptr->power=i;
		cout<<"enter coefficient of polynomial"<<endl;
		cin>>ptr->coefficient;
		ptr->next=NULL;
		if(start==NULL){
			start=ptr;
		}
		else{
			temp=start;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			
		}
		
	}


	temp=start;
	int z=0;
	while(temp!=NULL){
		if(temp->coefficient<0){
		if(temp->power==0)
		{
		
		cout<<temp->coefficient;
	}
	else
	{
		cout<<temp->coefficient;
		
		cout<<"x"<<"^"<<temp->power;
	}
		}
		else if(temp->coefficient==0){
			cout<<"";
		}
		else{
			if(z==0)
			{
				z=1;
					if(temp->power==0)
		{
					cout<<temp->coefficient;
				}
				else
				{
				cout<<temp->coefficient;
			cout<<"x"<<"^"<<temp->power;
		}
			}
			else
			{
						if(temp->power==0)
		{
			cout<<"+"<<temp->coefficient;
		}
		else
		{
			cout<<"+"<<temp->coefficient;
			cout<<"x"<<"^"<<temp->power;
		}
		}
			
		}
		
		
		temp=temp->next;
	}

	
	
	
	cout<<"\n P2"<<endl;
	cout<<"enter highest degree of coefficient"<<endl;
	cin>>b;
	
	for(int j=b;j>=0;j--){
		ptr2=new node();
		ptr2->power=j;
		cout<<"enter coefficient of polynomial"<<endl;
		cin>>ptr2->coefficient;
		ptr2->next=NULL;
		if(start2==NULL){
			start2=ptr2;
		}
		else{
			temp2=start2;
			while(temp2->next!=NULL){
				temp2=temp2->next;
			}
			temp2->next=ptr2;
			
		}
		
	}


	temp2=start2;
	z=0;
	while(temp2!=NULL){
		if(temp2->coefficient<0){
		if(temp2->power==0)
		{
		
		cout<<temp2->coefficient;
	}
	else
	{
		cout<<temp2->coefficient;
		
		cout<<"x"<<"^"<<temp2->power;
	}
		}
		else if(temp2->coefficient==0){
			cout<<"";
		}
		else{
			if(z==0)
			{
				z=1;
					if(temp2->power==0)
		{
					cout<<temp2->coefficient;
				}
				else
				{
				cout<<temp2->coefficient;
			cout<<"x"<<"^"<<temp2->power;
		}
			}
			else
			{
						if(temp2->power==0)
		{
			cout<<"+"<<temp2->coefficient;
		}
		else
		{
			cout<<"+"<<temp2->coefficient;
			cout<<"x"<<"^"<<temp2->power;
		}
		}
			
		}
		
		
		temp2=temp2->next;
	}
	

	
	
	cout<<"\n P3"<<endl;
	temp=start;
	temp2=start2;
	

	while(temp!=NULL && temp2!=NULL){
		temp3=new node();
		if(temp->power==temp2->power){
			
			temp3->coefficient=temp->coefficient+temp2->coefficient;
			temp3->power=temp->power;
			temp=temp->next;
			temp2=temp2->next;
		}
		else if(temp->power>temp2->power){
			temp3->coefficient=temp->coefficient;
			temp3->power=temp->power;
			temp=temp->next;
		}
		else{
			temp3->coefficient=temp2->coefficient;
			temp3->power=temp2->power;
			temp2=temp2->next;
		}
		temp3->next=NULL;
		if(start3==NULL){
			start3=temp3;
		}
		else{
			ptr3=start3;
			while(ptr3->next!=NULL){
				ptr3=ptr3->next;
				
			}
			ptr3->next=temp3;
		}
		
	}
	
	
	ptr3=start3;
	z=0;
	while(ptr3!=NULL){
		if(ptr3->coefficient<0){
		if(ptr3->power==0)
		{
		
		cout<<ptr3->coefficient;
	}
	else
	{
		cout<<ptr3->coefficient;
		
		cout<<"x"<<"^"<<ptr3->power;
	}
		}
		else if(ptr3->coefficient==0){
			cout<<"";
		}
		else{
			if(z==0)
			{
				z=1;
					if(ptr3->power==0)
		{
					cout<<ptr3->coefficient;
				}
				else
				{
				cout<<ptr3->coefficient;
			cout<<"x"<<"^"<<ptr3->power;
		}
			}
			else
			{
						if(ptr3->power==0)
		{
			cout<<"+"<<ptr3->coefficient;
		}
		else
		{
			cout<<"+"<<ptr3->coefficient;
			cout<<"x"<<"^"<<ptr3->power;
		}
		}
			
		}
		
		
		ptr3=ptr3->next;
	}
	
	
cout<<"\n P4"<<endl;
	temp=start;
	temp2=start2;
	

	while(temp!=NULL && temp2!=NULL){
		temp4=new node();
		if(temp->power==temp2->power){
			
			temp4->coefficient=temp->coefficient-temp2->coefficient;
			temp4->power=temp->power;
			temp=temp->next;
			temp2=temp2->next;
		}
		else if(temp->power>temp2->power){
			temp4->coefficient=temp->coefficient;
			temp4->power=temp->power;
			temp=temp->next;
		}
		else{
			temp4->coefficient=temp2->coefficient;
			temp4->power=temp2->power;
			temp2=temp2->next;
		}
		temp4->next=NULL;
		if(start4==NULL){
			start4=temp4;
		}
		else{
			ptr4=start4;
			while(ptr4->next!=NULL){
				ptr4=ptr4->next;
				
			}
			ptr4->next=temp4;
		}
		
	}
	
	
	ptr4=start4;
	z=0;
	while(ptr4!=NULL){
		if(ptr4->coefficient<0){
		if(ptr4->power==0)
		{
		
		cout<<ptr4->coefficient;
	}
	else
	{
		cout<<ptr4->coefficient;
		
		cout<<"x"<<"^"<<ptr4->power;
	}
		}
		else if(ptr4->coefficient==0){
			cout<<"";
		}
		else{
			if(z==0)
			{
				z=1;
					if(ptr4->power==0)
		{
					cout<<ptr4->coefficient;
				}
				else
				{
				cout<<ptr4->coefficient;
			cout<<"x"<<"^"<<ptr4->power;
		}
			}
			else
			{
						if(ptr4->power==0)
		{
			cout<<"+"<<ptr4->coefficient;
		}
		else
		{
			cout<<"+"<<ptr4->coefficient;
			cout<<"x"<<"^"<<ptr4->power;
		}
		}
			
		}
		
		
		ptr4=ptr4->next;
	}
	
	
	
	
	
	
	cout<<"\n enter value of x"<<endl;
	cin>>x;
	temp=start;
	while(temp!=NULL){
		c=c+temp->coefficient*pow(x,temp->power);
		temp=temp->next;
		
	}
	cout<<"P1="<<c<<endl;
	
	
	temp2=start2;
	while(temp2!=NULL){
		d=d+temp2->coefficient*pow(x,temp2->power);
		temp2=temp2->next;
		
	}
	cout<<"P2="<<d<<endl;
	
	
	e=c+d;
	cout<<"P3="<<e<<endl;
	
	f=c-d;
	cout<<"P4="<<f<<endl;
	
	
	
	


	
}