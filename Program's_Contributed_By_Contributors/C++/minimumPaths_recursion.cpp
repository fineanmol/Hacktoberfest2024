#include "bits/stdc++.h"
using namespace std;
int min(int a, int b){
	if (a>b)
		return b;
	return a;

}
int minPath(int m, int n){
	if(n==1||m==1){
		return 1;
	}
	return (minPath(m-1,n) +minPath(m,n-1));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int m, n;
		cin>>m>>n;
		cout<<minPath(m,n)<<'\n';
	}
	return 0;
}
