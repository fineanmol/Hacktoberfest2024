#include<iostream>
using namespace std;

int lcm(int a,int b,int i){
	int p=0;
	if(i<=a || i<=b){
		if(a%i==0 && b%i==0){
			p=lcm(a/i,b/i,i);
			return p*i;
			
		}
		else if(a%i==0){
			p=lcm(a/i,b,i);
			return p*i;
		
			
		}
		else if(b%i==0){
			p=lcm(a,b/i,i);
			return p*i;
			
			
		}
		else{
			p=lcm(a,b,i+1);
			return p;
		
		}
		
	}
	else{
		return 1;
	}	
}
int main(){
	int a,b,x;
	cin>>a>>b;
	x=lcm(a,b,2);
	cout<<x;
	return 0;
}