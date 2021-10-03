#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n

using namespace std;

// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

// Some frequently used functions
template <typename T>
T modpow(T base, T exp, T modulus){  
    base %= modulus;  T result = 1;  
    while(exp > 0){    
        if(exp & 1) result = (result * base) % modulus;    
        base = (base * base) % modulus;    
        exp >>= 1;  
    }  
    return result;
}
ll lcm(ll a, ll b) { return (a * (b / __gcd(a, b))); }
//Repeat,Example,Approach,Code,Testcases,Optimize
// int overflow, array bounds special cases (n=1?) 
// do smth instead of nothing and stay organized 
// WRITE STUFF DOWN DON'T GET STUCK ON ONE APPROACH

// Some constants
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);



void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    // odd + odd = even
    // even + odd = odd
    // odd + even = odd
    // even + even = even;
    int n,    

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) ;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}