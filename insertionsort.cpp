#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void insertion_sort(int arr[], int n){
for(int i=1;i<n;i++){
	cout<<" Iteration: "<<i<<endl;
	int j=i-1;
	int temp=i;
	while(arr[j]>arr[temp] && j>=0){
		cout<<"SWappiing :"<<arr[j]<<" "<<arr[j+1]<<endl;
		swap(arr[j], arr[temp]);
		j--;
		temp--;
	}
}
	
}


int main(){
	int arr[10];
	int n;
	cout<<"Enter the number of elements :";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertion_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
