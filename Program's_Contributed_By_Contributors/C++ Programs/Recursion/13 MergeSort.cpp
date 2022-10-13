// n<=100 (constraints)
#include<iostream>
using namespace std;

void merge(int*a,int s,int m,int e){
	int i=s;
	int j=m+1;
	int k=s;
	int b[100];
	while(i<=m && j<=e){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;k++;
		}else{
			b[k]=a[j];
			k++;j++;
		}
	}
	while(i<=m){
		b[k]=a[i];
		k++;i++;
	}
	while(j<=e){
		b[k]=a[j];
		k++;j++;
	}
	for(int l=s;l<=e;l++){
		a[l]=b[l];
	}
}

void mergeSort(int*a, int s, int e){
	if(s>=e){ //an array of size 0 and size 1(s=e) is already sorted
		return;
	}

	// divide array into two sub array along midpoint
	int m=(s+e)/2;

	//recursively sort two sub array
	mergeSort(a,s,m);
	mergeSort(a,m+1,e);


	//merge two sorted  arrays into merged array
	merge(a,s,m,e);
}

int main(){
	int a[]={50,39,48,11};
	int n=4;

	mergeSort(a,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}