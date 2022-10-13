#include<iostream>
using namespace std;
int search(int*a , int n, int i,int key){
				// base case
	if(i==-1){ 
		return -1;
	}

					//recursive case
	if(a[i]== key){
		return i;
	}
	return search(a,n,i-1,key);
}
int main(){
		int a[]={10,20,30,40,50,50,50};
		int n=7,i=n-1;
		int k=50;
		cout<<search(a,n,i, k);
	
	return 0;
}