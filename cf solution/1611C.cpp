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
   vector<ll>a(n);
   for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1){
        cout<<a[0]<<endl;return;
    }

    if(a[0]!=n && a[n-1]!=n){
        cout<<-1<<endl; return;
    }

    reverse(a.begin(),a.end());
        for(auto x:a)
            if(x!=n)
                cout<<x<<" ";
    cout<<n<<" "<<endl;

    
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


