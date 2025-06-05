#include <bits/stdc++.h>
using namespace std;
 

string a;long long d;
const long long M = 2e4;
const long long MOD = 107;
long long dp[M][2][MOD];
long long mod = 1e9+7;

// make as more variables in state so that there are less chances of overlapping dp

long long solve(long long pos,long long t,long long mo){
      if(pos==a.size()){
        return (mo==0);
      }

      if(dp[pos][t][mo]!=-1){
        return dp[pos][t][mo];
      }

      long long en = (t?a[pos]-'0':9);
      long long re =  0;

      
      for(int i=0;i<=en;i++){
          re=(re+solve(pos+1,t&(i==en),(d+mo-i%d)%d))%mod;
          re%=mod;
      }
      return dp[pos][t][mo] = re%mod;
}



void solve(){
    memset(dp,-1,sizeof dp);
    cin>>a>>d;
    long long ans = solve(0,1,0);
    ans--;
    ans+=mod;
    ans%=mod;
    cout<<ans<<"\n";
}


int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    long long  t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}
