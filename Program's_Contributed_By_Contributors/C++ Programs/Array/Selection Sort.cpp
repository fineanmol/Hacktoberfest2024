#include<iostream>
using namespace std;
#define N 6
int List[N];
void InsElem(){
	for(int i = 0;i<N;i++){
		cout<<"\nEnter the "<<i+1<<" element : ";
		cin>>List[i];
	}
}
void SelSort(){
	for(int i=0;i<N;i++){
		int min=i;
		for(int j=i+1;j<N;j++){
			if(List[j]<List[min]){
				min = j;
			}
		}
		if(min!=i){
			swap(List[i],List[min]);
		}
	}
}
void Display(){
	cout<<"\nThe formed array is : ";
	for(int i=0;i<N;i++){
		cout<<List[i]<<" ";
	}
	cout<<endl;
}
int main(){
	cout<<"Name   -> Shubham Mishra";
	cout<<endl;
	cout<<"Enroll -> 0832CS221196";
	cout<<"\n";
	int choice;
	do{
		cout<<"\nPress 1 to Enter the elements of the list";
		cout<<"\nPress 2 to sort the elements of the list";
		cout<<"\nPress 3 to Display the sorted list";
		cout<<"\n\nPlease enter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				InsElem();
				break;
			case 2:
				cout<<"\nThe List has been Sorted !\n";
				SelSort();
				break;
			case 3:
				Display();
				break;
			default:
				cout<<"Invalid Choice !..."<<endl;
		}
	}while(choice!=0);
}
