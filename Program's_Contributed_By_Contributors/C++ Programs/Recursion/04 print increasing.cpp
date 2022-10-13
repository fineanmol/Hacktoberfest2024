#include<iostream>
using namespace std;
  				     // increasing order
// void f(int n){
// 	// ->   base case
// 	if(n==0)
// 		return;
// 	// ->  recursive case
// 	f(n-1);
// 	cout<<n<<" ";
	
// }
       				// decreasing order
void f(int n){
	// ->   base case
	if(n==0){
		return;
	}
	cout<<n<<" ";

	// ->  recursive case
	f(n-1);
}
int main(){
	int n=5;
	f(n);	
	return 0;
}