#include<iostream>
using namespace std;

void binary_search(int arr[],int low,int high,int target){
	if(high < low){
		cout << "Element not found in the list." << endl;
		return;
	}
		int mid = low + (high - low)/2;
		//cout << "The current element is :"<<arr[mid]<<endl;
		if(arr[mid] == target){
			cout << "Element found at "<<mid<<"th index." << endl;
			return;
		}else if(arr[mid] > target){
			binary_search(arr,low,mid-1,target);
		}else{
			binary_search(arr,mid+1,high,target);
		}
	return;
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	binary_search(arr,0,(sizeof(arr)/sizeof(int))-1,6);
	return 0;
}