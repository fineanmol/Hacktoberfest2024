#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626
#define ll long long
#define lli long long int
#define fo(i,a,n) for(int i=a;i<n;i++)
#define pr(i,arr) for(auto i:arr)

typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef map<int,int> mi;

void file_i_p()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    return a%b==0 ? b : _gcd(b,a%b);
}

void ans(string text,string pat,int q)
{
    int m = pat.length();
    int n = text.length();
    int d = 256;
    int p = 0;
    int t = 0;
    int h = 1;

    for(int i=0;i<m-1;i++)
    {
        h = (h*d)%q;
    }

    for(int i=0;i<m;i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + text[i])%q;
    }

    for(int i=0;i<=n-m;i++)
    {
        if(p == t)
        {
            int kk = 0;
            for(int j=0;j<m;j++)
            {
                if(text[i+j]!=pat[j])
                {
                    kk = 11;
                    break;
                }
            }
            if(kk == 0)
            {
                cout<<i<<" ";
            }
        }

        if(i<n-m)
        {
            t = (d*(t-text[i]*h) + text[i+m])%q;
            if(t<0)
            {
                t = t + q;
            }
        }
    }
}

void solve()
{
    string text = "GEEKSFORGEEKS";
    string pat = "GEEKS";
    int q = 101;

    ans(text,pat,q);
    
}

int main() {
    
    file_i_p();

    solve();

    return 0;
}
