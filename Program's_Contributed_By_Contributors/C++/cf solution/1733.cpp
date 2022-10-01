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
    string ans="";
    int nval=9;
    while(n){
        int val=min(nval,n);
        ans.push_back((char)('0'+val));
        n-=val;
        nval--;
    }
    reverse(ans.begin(),ans.end());
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


