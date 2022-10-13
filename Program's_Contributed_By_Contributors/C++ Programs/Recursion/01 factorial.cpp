#include<iostream>
using namespace std;
int f(int n){
	// ->   base case
	if(n==0){
		//compute and return 0!
		return 1;
	}

	// ->  recursive case
	int ans=f(n-1);  //friend
	return n*ans;
}
int main(){
	int n=5;
	cout<< f(n);	
	return 0;
}