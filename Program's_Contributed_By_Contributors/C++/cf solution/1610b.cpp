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

bool isPal(vector<ll>&v){
    ll s=v.size();
    ll i=0,j=s-1;
    while(i<j){
        if(v[i]!=v[j])
            return 0;
        i++,j--;
    }
    return 1;
}

bool check(vector<ll>&a,ll x){
    vector<ll>b;
    for(int i=0;i<a.size();i++){
        if(a[i]!=x)
            b.push_back(a[i]);
    }
    bool ans=isPal(b);
    return ans;
}
void doit()
{
      
   ll n;
   cin>>n;
   vector<ll>a(n);
   for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1|| n==2)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(isPal(a))
    {
        cout<<"YES"<<endl;
        return;
    }

    bool flag=0;
    ll i=0,j=n-1;
    while(i<j)
    {
        if(a[i]!=a[j])
        {
            flag=check(a,a[i])||check(a,a[j]);
            break;
        }
        i++,j--;
    }
    if(flag)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
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


