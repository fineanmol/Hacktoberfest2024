#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

ll mod = 1000000007;
void doit()
{
    int n,ans=0;
    cin>>n;
    map<ll,ll>mp;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<0)
            a[i]*=-1;
        mp[a[i]]++;
    }
    for(auto it:mp){
        if(it.second>=2 && it.first!=0)
            ans+=2;
        else ans++;
    }

    cout<<ans<<endl;
    

}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}