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
// #define INP/OUT freopen(
// , 
// , stdin); freopen(
// , 
// , stdout);

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
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    if(n<=6){
        cout<<"NO"<<endl;
    }
    else if(n==9){
        cout<<"NO"<<endl;
    }
    else if(n%3!=0 ){
        cout<<"YES"<<endl;
        cout<<n-3<<" "<<1<<" "<<2<<endl;
    }
    else if(n%3==0){
        cout<<"YES"<<endl;
        cout<<n-5<<" "<<1<<" "<<4<<endl;
    }
}
 return 0;
}
