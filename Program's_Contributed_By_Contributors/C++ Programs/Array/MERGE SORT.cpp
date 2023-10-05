#include<iostream>
using namespace std;
#define N 6
int MainList[N];
int SortedSubList[N];
void insElem(){
	for(int i=0;i<N;i++){
		cout<<"\nEnter the "<<i+1<<" element : ";
		cin>>MainList[i];
	}
}
void MergeSort(int lb,int ub){
	if(lb<ub){
	int mid_term = (lb+ub) / 2;
    MergeSort(lb, mid_term);
    MergeSort(mid_term + 1, ub); 
	int i = lb;
	int j = mid_term+1;
	int k = lb;
	while(i<=mid_term && j<=ub)
	if(MainList[i]<MainList[j]){
		SortedSubList[k] = MainList[i];
		i++;
		k++;
	}
	else{
		SortedSubList[k] = MainList[j];
		j++;
		k++;
	}
	if(i>mid_term){
		while(j<=ub){
			SortedSubList[k] = MainList[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid_term){
			SortedSubList[k] = MainList[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++){
		MainList[k]=SortedSubList[k];
	}	
}
}
void Sort_Display(){
	cout<<"The list after sorting is : ";
	for(int i=0;i<N;i++){
		cout<<SortedSubList[i]<<" ";
	}
}
int main(){
	int choice;
	do{
		cout<<"\nPress 1 for Inserting elements."<<endl;
		cout<<"\nPress 2 for Sorting Elements by Merge Sort"<<endl;
		cout<<"\nPress 3 for displaying Sorted List"<<endl;
		cout<<"\nEnter your choice : "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				insElem();
				break;
			case 2:
				MergeSort(0,N-1);
				break;
			case 3:
				Sort_Display();
				break;
			default:
				cout<<"Invalid choice !";
		}
		
	}while(choice!=0);	
}
