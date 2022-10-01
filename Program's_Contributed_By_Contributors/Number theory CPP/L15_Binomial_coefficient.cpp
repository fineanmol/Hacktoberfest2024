#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int 
using namespace std;

lli mod=1000000007;

vector<lli> fact;

lli pow(lli a, lli n,lli p)
{
	lli res=1;
	while(n)
	{
		if(n%2)
		{
			res=(res*a)%mod;
			n--;
		}
		else{
			a=(a*a)%mod;
			n/=2;
		}
	}
	return res;
}

void factfill()
{
	fact.push_back(1);
	for(int i=1; i<=1000; i++ )
	{
		fact[i]=(fact[i-1]*i)%mod;
		// cout<<i<<"!="<<fact[i]<<endl;
	}
}


lli c(lli n,lli r)
{
	lli res=(fact[n]*pow(fact[r], mod-2, mod))%mod;
	res=(res*pow(fact[n-r], mod-2, mod))%mod;
    return res;
}
int main()
{
	lli n, r;
	cin>>n>>r;
	factfill();
    cout<<"fact(n)="<<fact[n]<<endl;
	cout<<"nCr="<<c(n, r);
	return 0;
}