// recursive algo to compute sum of elements of array.
#include<iostream>
using namespace std;

int sum(int* a, int n,int i){
	if(i==n-1){
		return a[n-1]; // f(n-1)=subarray A[n-1,...n-1]=> only 1 element in array
	}
	int A=sum(a,n,i+1);
	
	return a[i]+A;
}

int main(){
	int n=3;
	int arr[]={10,20,30};
	cout<<sum(arr,n,0);	
	return 0;
}