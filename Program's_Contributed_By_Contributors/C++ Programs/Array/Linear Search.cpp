#include<iostream>
using namespace std;
#define N 6
int MainList[N];
void insElem(){
	for(int i=0;i<N;i++){
		cout<<"\nEnter the "<<i+1<<" element : ";
		cin>>MainList[i];
	}
}
void LinearSearch(){
	int found = 0;
	int search_elem;
	cout<<"Enter the element to be searched : ";
	cin>>search_elem;
	for(int i=0;i<N;i++){
		if(MainList[i]==search_elem){
			cout<<"\n"<<search_elem<<" is present at "<<"'"<<i<<"'"<<" index of the list"<<endl;
			found=1;
			break;
		}
	}
	if(found!=1){
		cout<<search_elem<<" was not found in the list !"<<endl;
	}
}
void display(){
	cout<<"\nThe formed array is : ";
	for(int i=0;i<N;i++){
		cout<<MainList[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int choice;
	cout<<"Name   -> Shubham Mishra";
	cout<<endl;
	cout<<"Enroll -> 0832CS221196";
	cout<<"\n";
	do{
		cout<<"\n\nPress 1 for Inserting elements.\n";
		cout<<"\nPress 2 to search for the element.\n";
		cout<<"\nPress 3 to Display the elements.\n";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				insElem();
				break;
			case 2:
				LinearSearch();
				break;
			case 3:
				display();
				break;
			default:
				cout<<"Invalid choice !";
		}
		
	}while(choice!=0);	
}
