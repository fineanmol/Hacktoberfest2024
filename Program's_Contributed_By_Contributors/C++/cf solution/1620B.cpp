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
      
    ll w,h,d,x;
    cin>>w>>h;

    ll n;
    ll mx=LONG_LONG_MIN;
    fo1(i,4){
        cin>>n;
        d=0;
        fo1(j,n){
            cin>>x;
            if(j==0)d=x;
            else if(j==n-1)
            {
                d=x-d;
            }
        }

        if(i<2){
            d*=h;
        }
        else d*=w;
        mx=max(mx,d);
    }
    cout<<mx<<endl;
    
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


