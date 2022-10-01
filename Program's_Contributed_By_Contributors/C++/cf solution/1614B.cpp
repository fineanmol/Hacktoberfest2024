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
      
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v(n);

    fo1(i,n)
    {
        ll x;
        cin>>x;
        v[i].first=x,v[i].second=i;
    }
    sort(v.rbegin(),v.rend());
    vector<ll>ans(n);
    ll mid=(n+2)/2;
    ll res=0;

    ll left=mid-1, right=mid+1;
    bool isLeft=1;
    for(int i=0;i<n;i++)
    {
        ll idx=v[i].second;
        ll cnt=v[i].first;

        if(isLeft){
            ans[idx]=left;
            ll cost=2*(mid-left);
            res+=cnt*cost;
            left--;
            isLeft=0;
        }
        else{
            ans[idx]=right;
            ll cost=2*(right-mid);
            res+=cnt*cost;
            right++;
            isLeft=1;
        }
    }
    cout<<res<<endl;
    cout<<mid<<" ";
    for(ll x:ans) cout<<x<<" ";
    cout<<endl;

    
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


