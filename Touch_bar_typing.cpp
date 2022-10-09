// TOUCHBAR TYPING
 
// TIME COMPLEXITY: O(MAX * MAX)
// SPACE COMPLEXITY: O(MAX * MAX)
 
#include "bits/stdc++.h"
using namespace std;
 
#define endl "\n"
#define F   first
#define S   second
#define ll  long long
#define vi  vector<ll>
#define pb  push_back
#define pii pair<ll,ll>
#define vii vector<pii>
#define vb  vector<bool>
#define vc  vector<char>
#define vs  vector<string> 
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
 
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define print(v) for(auto& it:v)cout<<it<<" ";
#define calc_fact(n) tgamma(n+1)
#define inf 9223372036854775807LL
#define MOD 1000000007
#define mod 998244353
 
template<typename T, typename U> static inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y) { if(x < y) x = y; }
 
/* 1. Think in Reverse Way
   2. Handle Corner Cases
   3. Check Array Bounds
   4. Don't Get Stuck on One Approach */
 
const ll MAX = 2505;
 
ll n, m;
vi s(MAX + 1), k(MAX + 1);
vvi pref(MAX + 1, vi(MAX + 1, -1));
vvi suff(MAX + 1, vi(MAX + 1, -1));
 
ll MinCostTyping(ll i, ll j, vvi& dp){
    if(i == n){
        return 0;
    }
 
    if(dp[i][j] != -1){
        return dp[i][j];
    }
 
    ll ans = inf;
 
    if(pref[j][s[i]] != -1){
        ll cost = abs(j - pref[j][s[i]]);
        amin(ans, cost + MinCostTyping(i + 1, pref[j][s[i]], dp));
    }
 
    if(suff[j][s[i]] != -1){
        ll cost = abs(j - suff[j][s[i]]);
        amin(ans, cost + MinCostTyping(i + 1, suff[j][s[i]], dp));
    }
 
    return dp[i][j] = ans;
}
 
void Saraff(){
    cin >> n;
 
    rep(i,0,n){
        cin >> s[i];
    }
 
    cin >> m;
 
    rep(i,0,m){
        cin >> k[i];
    }
 
    ll mx = *max_element(all(k));
 
    rep(i,0,m){
        rep(j,0,mx+1){
            pref[i][j] = suff[i][j] = -1;
        }
    }
 
    rep(i,0,m){
        pref[i][k[i]] = suff[i][k[i]] = i;
    }
 
    rep(j,0,mx+1){
        ll last = -1;
        rep(i,0,m){
            if(pref[i][j] != -1){
                last = pref[i][j];
            }
 
            pref[i][j] = last;
        }
 
        last = -1;
        for(ll i=m-1; i>=0; i--){
            if(suff[i][j] != -1){
                last = suff[i][j];
            }
 
            suff[i][j] = last;
        }
    }
 
    ll ans = inf;
    vvi dp(n, vi(m, -1));
 
    rep(j,0,m){
        amin(ans, MinCostTyping(0, j, dp));
    }
 
    cout << ans << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll test = 1;
    cin>>test;
    for(ll t=1;t<=test;t++){
        cout<<"Case #"<<t<<": ";
        Saraff();
    }
}
