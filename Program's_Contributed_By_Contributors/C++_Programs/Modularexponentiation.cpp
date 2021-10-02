#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod(ll a,ll b,ll c)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return mod( (a*a)%c, b/2,c);
    else
        return (a%c) * mod( (a*a)%c, (b-1)/2,c);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<mod(a,b,c)<<"\n";
    }
    return 0;
}
