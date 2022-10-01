#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

void doit()
{

    int n,k,ans=0,x;
    cin>>n>>k;
    vector<ll>a;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<ll>());

    fo1(i,k){
        ans+=a[i+k]/a[i];
    }
    for(int i=2*k;i<n;i++)
        ans+=a[i];
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