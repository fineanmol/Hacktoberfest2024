// 0,1,1,2,3,5,8,13...
#include<iostream>
using namespace std;
int f(int n){
	// ->   base case
	if(n==0 || n==1){
		return n; // for 0 = 0 and 1 = 1
	}

	// ->  recursive case
	int a=f(n-1);
	int b=f(n-2);
	return a+b;

}
int main(){
	int n=6;
	cout<< f(n);	
	return 0;
}