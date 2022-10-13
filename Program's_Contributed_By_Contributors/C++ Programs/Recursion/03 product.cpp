// given two number a and b calculate their product recursively;
#include<iostream>
using namespace std;
int f(int a,int b){
	// ->   base case
	if( b==0 ){
		//return product of a*0
		return 0;
	}

	// ->  recursive case
	int ans=f(a,b-1); // b-1=> times 
	return a+ans; // a+a+a (b-1 times)
}
int main(){
	int a=4;
	int b=3;
	cout<< f(a,b);	
	return 0;
}