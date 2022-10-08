#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int left, int right, int element)
{
	if(right>=left)
	{
		int mid = left + (right-left)/2; 

		if(arr[mid] == element) 						
			return mid;

		if(arr[mid] > element)                 				
			return binarySearch(arr,left,mid-1,element);

		return binarySearch(arr,mid+1,right,element);

	}
	return -1;
}

int main()
{
	int size;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	int element = 12;

	int result = binarySearch(arr,0,size-1,element);
	if(result==-1)
		cout<<"Element is not present in array"<<endl;
	else
		cout<<"Element is present @ index "<<result<<endl;

	return 0;
}
