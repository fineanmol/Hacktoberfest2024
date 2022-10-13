#include<iostream>
using namespace std;
bool checkSort(int* a,int n, int i){
				// base case
	if(i==n-1){ // check subarray start at a[n-1]indx is sorted
		return true;
	}

				// recursive case
	// check if arr[i....n-1] is sorted
	// bool A=checkSort(a,n,i+1);

	return a[i]<a[i+1] and checkSort(a,n,i+1);

}
int main(){
	int a[]={10,20,30,40,50};
	int i=0;
	checkSort(a,5,0)?cout<<"true": cout<<"false";	
	return 0;
}