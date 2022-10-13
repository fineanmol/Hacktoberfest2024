#include<iostream>
using namespace std;
int binarySearch(int *a,int s,int e,int t){
	if(s>e)
		return -1;
	int m=s+((e-s)>>1);
	if(a[m]==t){
		return m;
	}
	else if(a[m]>t){
		return binarySearch(a,s,m-1,t);
	}
	return binarySearch(a,m+1,e,t);
}

int main(){
	int a[]={1,2,4,6,8};
	int t=6;
	int n=5;
	cout<<binarySearch(a,0,n-1,t);	
	return 0;
}