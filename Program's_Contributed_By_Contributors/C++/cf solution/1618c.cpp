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

    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    ll v1=0,v2=0;
    for(int i=0;i<n;i+=2)
        v1=__gcd(v1,a[i]);
    for(int i=1;i<n;i+=2)
        v2=__gcd(v2,a[i]);
    
    bool ok=true;
    for(int i=0;i<n;i+=2)
        if(a[i]%v2==0)
            {
                ok=false;
                break;
            }
    if(ok){
        cout<<v2<<"\n";
        return;
    }
    ok=true;
    for(int i=1;i<n;i+=2)
        if(a[i]%v1==0)
            {
                ok=false;
                break;
            }
    if(ok){
        cout<<v1<<"\n";
        return;
    }
    cout<<0<<"\n";           
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