#include<iostream>
using namespace std;
int binary(int a){
	int b=0,c=0;
	if(a>1){
		b=binary(a/2);
	
		c=a%2;
		return c+(b*10);	
	}
	else{
		return 1;
	}
	
}
int main(){
	int a,x;
	cin>>a;
	x=binary(a);
	cout<<x;
	return 0;
	
}