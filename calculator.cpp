#include <bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter two num"<<endl;
	int a,b;
	cin>>a;
	cin>>b;
	cout<<"Choose between 1, 2 or 3"<<endl;
	int n;
	cin>>n;
	if(n==1)
	cout<<a+b;
	if(n==2)
	cout<<a-b;
	else
	cout<<a*b;
}
