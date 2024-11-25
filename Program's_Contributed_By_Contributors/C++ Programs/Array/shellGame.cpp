#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define unique(v) v.erase(std::unique(v.begin(), v.end()), v.end());
#define INP/OUT freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
long long   gcd(long long  a, long long  b)
{
if (b == 0)
return a;
return gcd(b, a % b);
}
long long   lcm(long long  a, long long  b)
{
return (a / gcd(a, b)) * b;
}






int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
    int n ;
    cin>>n;
    fo(i,0,3){
        int x,y;
        cin>>x>>y;
        if(x==n){
            n = y;
        }
        else if(y==n){
            n = x;
        }

    }
    cout<<endl;
    cout<<n<<endl;
    

 return 0;
}
