#include<iostream>
using namespace std;

int factorial(int a){
	int b=0,c=0;
	if(a>0){
b=	factorial(a-1);
	b=b*a;
	return b;	
		
	}
	else
	{
		return 1;
	}

	
	
}
int main(){
	int a,x;
	cin>>a;
	x=factorial(a);
	cout<<x;
	return 0;
}