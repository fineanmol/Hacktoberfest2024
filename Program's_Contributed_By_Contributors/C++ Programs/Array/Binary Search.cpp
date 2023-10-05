//Program for Insertion Sorting in Array by Shubham.
#include<iostream>
using namespace std;
#define N 3
int array[N];
void InsElem(){
	for(int i=0;i<N;i++){
		cout<<"\nEnter the "<<i+1<<" element of the array : ";
		cin>>array[i];
	}
}
void LinearSearch(){
	int temp;
	for(int i=1;i<N;i++){
		temp = array[i];
		int j = i-1;
		while(j>=0 && array[j]>temp){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
	int value,mid;
	cout<<"Enter the element you wish to search : ";
	cin>>value;
	int l=0;
	int r=N-1;
	int found =0;
	
	while(l<=r){
		mid = (l+r)/2;
		if(value==array[mid]){
			cout<<value<<" is at "<<mid<<"position.";
			found =1;
			break;
		}
		else if(value<array[mid]){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	if(found!=1){
		cout<<"The element was not found !";
	}
	
}
void display(){
	cout<<"\nThe formed array is : ";
	for(int i=0;i<N;i++){
		cout<<array[i]<<" ";
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
		cout<<"\nPress 1 to Enter the elements.";
		cout<<"\nPress 2 to Sort the elements.";
		cout<<"\nPress 3 to Display the elements of Array.";
		cout<<"\n\nPlease Enter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				InsElem();
				break;
			case 2:
				LinearSearch();
				break;
			case 3:
				display();
				break;
			default:
				cout<<"Invalid Choice !\n";
		}
	}while(choice!=0);
}
