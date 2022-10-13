#include<iostream>
using namespace std;
int search(int*a , int n, int i,int key){
				// base case
	// if(i==n-1){
	// 	if(a[i]==key){
	// 		return n-1;
	// 	}
	// 	return -1;
	// }
	if(i==n){ // finding idx of 1st occ of target in a[i...n]{empty subarray}
		return -1;
	}

					//recursive case
	if(a[i]== key){
		return i;
	}
	return search(a,n,i+1,key);
}
int main(){
		int a[]={10,20,30,40,50};
		int n=5,i=0;
		int k=30;
		cout<<search(a,n,i, k);
	
	return 0;
}