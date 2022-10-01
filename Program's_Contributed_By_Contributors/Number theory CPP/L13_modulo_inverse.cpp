#include<bits/stdc++.h>
#define lli long long int 
using namespace std;


lli power(lli a, lli n, lli mod )
{
    lli res=1;
    while(n>0)
    {
        if (n%2)
        {
            res=(res*a)%mod;
            n--;
        }
        else
        {
            a=(a*a)%mod;
            n/=2;
        }
    }
    return res;
}
int main()
{
    lli a, m;
    cin>>a>>m;
    cout<<"a^-1="<<power(a, m-2, m)<<endl;
    return 0;
}