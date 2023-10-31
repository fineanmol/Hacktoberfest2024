#include<bits/stdc++.h>
using namespace std;

int help(int base, int pow)
{
	if(pow==0)
		return 1;
	if(pow==1)
		return base;
	if(pow%2)
		return base*help(base*2,(pow-1)/2);
	else
		return help(base*2,pow/2);
}

int main()
{
	int base ;
	cin>>base;
	
	int pow ;
	cin>>pow;
	if(pow<0)
		cout<<1.0/help(base,-pow)<<endl;
	else
		cout<<help(base,pow)<<endl;
	return 0;

}
