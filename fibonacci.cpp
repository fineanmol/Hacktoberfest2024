#include<iostream>
using namespace std;
int main(){
	int n,i,f=0,s=1,t=0;
	cout<<"Enter the value of n:";
	cin>>n;
	cout<<f<<" "<<s<<' ';
    for(i=0;i<=n-3;i++){
    	t=f+s;
    	f=s;
    	s=t;
    	cout<<t<<" ";
	}
}
