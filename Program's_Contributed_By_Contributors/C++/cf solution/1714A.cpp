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
    int n,H,M;
    cin>>n>>H>>M;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int h,m;
        cin>>h>>m;
        mp[h*60+m]++;
    }
    int t=0;
    while(!mp[(H*60 + M+ t)%(24*60)]) t++;
    // t%=24*60;
    cout<<t/60<<" "<<t%60<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
   int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        doit();
    }
    return 0;
}


